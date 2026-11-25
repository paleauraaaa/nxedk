// Symlinked into xboxkrnl-sys and xam-sys.

use clang_sys::*;
use std::env;
use std::ffi::{CStr, CString};
use std::path::PathBuf;
use std::ptr;

#[derive(Default)]
struct Declarations {
    functions: Vec<String>,
    unsigned_char: bool,
    invalid_name: bool,
}

extern "C" fn collect_prototypes(
    cursor: CXCursor,
    _: CXCursor,
    data: CXClientData,
) -> CXChildVisitResult {
    unsafe {
        let kind = clang_getCursorKind(cursor);
        if kind == CXCursor_FunctionDecl || kind == CXCursor_TypedefDecl {
            let declarations = &mut *(data as *mut Declarations);
            let name = clang_getCursorSpelling(cursor);
            let text = clang_getCString(name);
            if text.is_null() {
                declarations.invalid_name = true;
            } else if let Ok(name) = CStr::from_ptr(text).to_str() {
                if kind == CXCursor_FunctionDecl
                    && clang_getCursorType(cursor).kind == CXType_FunctionProto
                {
                    declarations.functions.push(name.to_owned());
                } else if kind == CXCursor_TypedefDecl && name == "CHAR" {
                    let ty = clang_getTypedefDeclUnderlyingType(cursor);
                    declarations.unsigned_char = clang_getCanonicalType(ty).kind == CXType_Char_U;
                }
            } else {
                declarations.invalid_name = true;
            }
            clang_disposeString(name);
        }
    }
    CXChildVisit_Continue
}

fn prototypes(header: &str, args: &[String]) -> Vec<String> {
    clang_sys::load().expect("failed to load libclang");
    let header = CString::new(header).expect("header path contains a null byte");
    let args: Vec<_> = args
        .iter()
        .map(|arg| CString::new(arg.as_str()).expect("Clang argument contains a null byte"))
        .collect();
    let arg_ptrs: Vec<_> = args.iter().map(|arg| arg.as_ptr()).collect();

    unsafe {
        let index = clang_createIndex(0, 0);
        assert!(!index.is_null(), "failed to create Clang index");
        let mut unit = ptr::null_mut();
        let status = clang_parseTranslationUnit2(
            index,
            header.as_ptr(),
            arg_ptrs.as_ptr(),
            arg_ptrs.len() as i32,
            ptr::null_mut(),
            0,
            0,
            &mut unit,
        );
        if status != CXError_Success || unit.is_null() {
            clang_disposeIndex(index);
            panic!("failed to parse header with libclang: error {status}");
        }

        let mut has_errors = false;
        for i in 0..clang_getNumDiagnostics(unit) {
            let diagnostic = clang_getDiagnostic(unit, i);
            if clang_getDiagnosticSeverity(diagnostic) >= CXDiagnostic_Error {
                let message =
                    clang_formatDiagnostic(diagnostic, clang_defaultDiagnosticDisplayOptions());
                let text = clang_getCString(message);
                if !text.is_null() {
                    eprintln!("{}", CStr::from_ptr(text).to_string_lossy());
                }
                clang_disposeString(message);
                has_errors = true;
            }
            clang_disposeDiagnostic(diagnostic);
        }

        let target = clang_getTranslationUnitTargetInfo(unit);
        assert!(
            !target.is_null(),
            "libclang did not report target information"
        );
        let pointer_width = clang_TargetInfo_getPointerWidth(target);
        clang_TargetInfo_dispose(target);

        let mut declarations = Declarations::default();
        if !has_errors {
            clang_visitChildren(
                clang_getTranslationUnitCursor(unit),
                collect_prototypes,
                &mut declarations as *mut Declarations as CXClientData,
            );
        }
        clang_disposeTranslationUnit(unit);
        clang_disposeIndex(index);
        assert!(
            !has_errors,
            "libclang reported errors while parsing the header"
        );
        assert!(
            pointer_width == 32 && declarations.unsigned_char,
            "libclang did not use the Xbox ABI (expected 32-bit pointers and unsigned char)"
        );
        assert!(
            !declarations.invalid_name,
            "invalid declaration name from libclang"
        );
        declarations.functions
    }
}

fn main() {
    let crate_dir = PathBuf::from(env::var_os("CARGO_MANIFEST_DIR").unwrap());
    let native = crate_dir
        .parent()
        .expect("crate has no native parent directory");
    if cfg!(windows) && env::var_os("LIBCLANG_PATH").is_none() {
        if let Some(root) = env::var_os("NXEDK_ROOT") {
            let lib = PathBuf::from(root).join("toolchain/win32/lib");
            if lib.is_dir() {
                // This build script has not started any threads yet.
                unsafe { env::set_var("LIBCLANG_PATH", lib) };
            }
        }
    }
    println!("cargo:rerun-if-env-changed=NXEDK_ROOT");
    let package = env::var("CARGO_PKG_NAME").unwrap();
    let shared = package == "windef-sys";
    let header = crate_dir.join(match package.as_str() {
        "windef-sys" => "windef.h",
        "xboxkrnl-sys" => "xboxkrnl.h",
        "xam-sys" => "xam.h",
        _ => panic!("unsupported native bindings package: {package}"),
    });
    let header = header.to_str().expect("header path is not UTF-8");
    let windef = native.join("windef-sys");
    let include = windef.to_str().expect("windef directory path is not UTF-8");
    let mut args = vec![
        "--target=powerpc64-microsoft-xbox360".to_owned(),
        "-ffreestanding".to_owned(),
        format!("-I{include}"),
    ];
    println!("cargo:rerun-if-env-changed=NXEDK_CLANG_RESOURCE_DIR");
    if let Some(resource_dir) = env::var_os("NXEDK_CLANG_RESOURCE_DIR") {
        args.push("-resource-dir".to_owned());
        args.push(
            resource_dir
                .into_string()
                .expect("Clang resource directory path is not UTF-8"),
        );
    }

    println!(
        "cargo:rerun-if-changed={}",
        native.join("build.rs").display()
    );
    println!("cargo:rerun-if-changed={header}");
    println!(
        "cargo:rerun-if-changed={}",
        windef.join("windef.h").display()
    );
    println!("cargo:rerun-if-env-changed=LIBCLANG_PATH");

    // Match bindgen's target-specific environment variable precedence.
    let target = env::var("TARGET").unwrap();
    let extra_args = [
        format!("BINDGEN_EXTRA_CLANG_ARGS_{target}"),
        format!("BINDGEN_EXTRA_CLANG_ARGS_{}", target.replace('-', "_")),
        "BINDGEN_EXTRA_CLANG_ARGS".to_owned(),
    ]
    .iter()
    .find_map(|name| env::var(name).ok());
    let mut parse_args = args.clone();
    if let Some(extra) = extra_args {
        parse_args.extend(shlex::split(&extra).unwrap_or_else(|| vec![extra]));
    }

    let functions = prototypes(header, &parse_args);
    let mut builder = bindgen::Builder::default()
        .header(header)
        .clang_args(&args)
        .use_core()
        .layout_tests(false)
        .generate_comments(false)
        .rust_target("1.85".parse().unwrap())
        .rust_edition(bindgen::RustEdition::Edition2024)
        .formatter(bindgen::Formatter::None)
        .parse_callbacks(Box::new(bindgen::CargoCallbacks::new()));
    builder = if shared {
        builder
            .allowlist_file(".*windef[.]h")
            .blocklist_var("^ULONGLONG_MAX$")
    } else {
        assert!(
            !functions.is_empty(),
            "no function prototypes found in header"
        );
        let pattern = format!(
            "^({})$",
            functions
                .iter()
                .map(|name| regex::escape(name))
                .collect::<Vec<_>>()
                .join("|")
        );
        builder
            .allowlist_function(pattern)
            .blocklist_file(".*windef[.]h")
    };
    builder
        .generate()
        .expect("failed to generate native bindings")
        .write_to_file(PathBuf::from(env::var_os("OUT_DIR").unwrap()).join("bindings.rs"))
        .expect("failed to write native bindings");
}
