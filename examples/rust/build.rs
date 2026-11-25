use std::env;
use std::path::PathBuf;

fn main() {
    println!(
        "cargo:rerun-if-changed={}",
        env::var("CARGO_MANIFEST_DIR").unwrap() + "/build.rs"
    );
    println!("cargo:rerun-if-env-changed=NXEDK_ROOT");
    println!("cargo:rerun-if-env-changed=PATH");

    let root = PathBuf::from(env::var_os("NXEDK_ROOT").expect("NXEDK_ROOT must be set"));
    if cfg!(windows) && env::var("CARGO_CFG_TARGET_OS").as_deref() == Ok("xbox360") {
        let bin = root
            .join("toolchain")
            .join("win32")
            .join("bin")
            .join("llvm");
        assert!(
            bin.join("lld-link.exe").is_file(),
            "Xbox linker not found in {}",
            bin.display()
        );
        let path = env::var_os("PATH").expect("PATH must be set");
        let paths = std::iter::once(bin).chain(env::split_paths(&path));
        let path = env::join_paths(paths).expect("could not construct linker PATH");
        println!(
            "cargo:rustc-env=PATH={}",
            path.to_str().expect("linker PATH is not UTF-8")
        );
    }

    let picolibc_build_dir = PathBuf::from(
        env::var("NXEDK_PICOLIBC_BUILD_DIR").expect("NXEDK_PICOLIBC_BUILD_DIR must be set"),
    );
    println!("cargo:rustc-link-search=native={}", picolibc_build_dir.display());
    println!("cargo:rustc-link-search=native={}/picocrt", picolibc_build_dir.display());
    println!("cargo:rustc-link-lib=static:+verbatim=libc.lib");
    println!("cargo:rustc-link-lib=static:+verbatim=crt0.lib");
    
    println!("cargo:rustc-link-search=native={}", root.join("build").display());
    println!("cargo:rustc-link-lib=static:+verbatim=xboxkrnl.lib");
    println!("cargo:rustc-link-lib=static:+verbatim=xam.lib");

}
