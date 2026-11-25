use std::env;
use std::fs;
use std::path::{Path, PathBuf};

fn collect_headers(dir: &Path, headers: &mut Vec<PathBuf>) {
    let entries = fs::read_dir(dir)
        .unwrap_or_else(|error| panic!("failed to read {}: {error}", dir.display()));
    for entry in entries {
        let entry = entry.expect("failed to read header directory entry");
        let path = entry.path();
        let file_type = entry
            .file_type()
            .expect("failed to inspect header directory entry");
        if file_type.is_dir() {
            collect_headers(&path, headers);
        } else if file_type.is_file() && path.extension().is_some_and(|ext| ext == "h") {
            headers.push(path);
        }
    }
}

fn main() {
    let crate_dir = PathBuf::from(env::var_os("CARGO_MANIFEST_DIR").unwrap());
    let root = env::var_os("NXEDK_ROOT")
        .map(PathBuf::from)
        .unwrap_or_else(|| {
            crate_dir
                .parent()
                .and_then(Path::parent)
                .expect("crate is not inside NXEDK")
                .to_owned()
        });
    let include = root.join("include");
    let headers_dir = include.join("nxedk");
    let picolibc_build = env::var_os("NXEDK_PICOLIBC_BUILD_DIR")
        .map(PathBuf::from)
        .unwrap_or_else(|| root.join("build").join("picolibc"));

    for name in [
        "NXEDK_ROOT",
        "NXEDK_PICOLIBC_BUILD_DIR",
        "NXEDK_CLANG_RESOURCE_DIR",
        "LIBCLANG_PATH",
    ] {
        println!("cargo:rerun-if-env-changed={name}");
    }
    println!("cargo:rerun-if-changed={}", headers_dir.display());
    println!(
        "cargo:rerun-if-changed={}",
        picolibc_build.join("picolibc.h").display()
    );

    if cfg!(windows) && env::var_os("LIBCLANG_PATH").is_none() {
        let lib = root.join("toolchain").join("win32").join("lib");
        if lib.is_dir() {
            // This build script has not started any threads yet.
            unsafe { env::set_var("LIBCLANG_PATH", lib) };
        }
    }

    let mut headers = Vec::new();
    collect_headers(&headers_dir, &mut headers);
    headers.sort();
    assert!(
        !headers.is_empty(),
        "no NXEDK headers found in {}",
        headers_dir.display()
    );

    let mut builder = bindgen::Builder::default()
        .clang_arg("--target=powerpc64-microsoft-xbox360")
        .clang_arg("-ffreestanding")
        .clang_arg(format!("-I{}", include.display()))
        .clang_arg(format!(
            "-I{}",
            root.join("src/picolibc/libc/machine/powerpc").display()
        ))
        .clang_arg(format!("-I{}", picolibc_build.display()))
        .clang_arg(format!(
            "-I{}",
            root.join("src/picolibc/libc/include").display()
        ))
        .allowlist_file(r".*[/\\]include[/\\]nxedk[/\\].*[.]h")
        .use_core()
        .layout_tests(false)
        .generate_comments(false)
        .rust_target("1.85".parse().unwrap())
        .rust_edition(bindgen::RustEdition::Edition2024)
        .formatter(bindgen::Formatter::None)
        .parse_callbacks(Box::new(bindgen::CargoCallbacks::new()));

    let resource_dir = env::var_os("NXEDK_CLANG_RESOURCE_DIR")
        .map(PathBuf::from)
        .or_else(|| {
            let bundled = root.join("toolchain/include/clang/23");
            (cfg!(windows) && bundled.is_dir()).then_some(bundled)
        });
    if let Some(resource_dir) = resource_dir {
        builder = builder.clang_arg("-resource-dir").clang_arg(
            resource_dir
                .to_str()
                .expect("Clang resource directory path is not UTF-8"),
        );
    }
    for header in headers {
        builder = builder.header(header.to_str().expect("header path is not UTF-8"));
    }

    builder
        .generate()
        .expect("failed to generate NXEDK bindings")
        .write_to_file(PathBuf::from(env::var_os("OUT_DIR").unwrap()).join("bindings.rs"))
        .expect("failed to write NXEDK bindings");

    if env::var("CARGO_CFG_TARGET_OS").as_deref() == Ok("xbox360") {
        let library = root.join("build").join("libnxedk.lib");
        println!("cargo:rerun-if-changed={}", library.display());
        assert!(
            library.is_file(),
            "NXEDK library not found at {}; build NXEDK first",
            library.display()
        );
        println!(
            "cargo:rustc-link-search=native={}",
            root.join("build").display()
        );
        println!("cargo:rustc-link-lib=static:+verbatim=libnxedk.lib");
    }
}
