#[test]
fn generates_prototypes_but_omits_unspecified_parameters() {
    let bindings: String = include_str!(concat!(env!("OUT_DIR"), "/bindings.rs"))
        .split_whitespace()
        .collect();

    assert!(bindings.contains("pubfnNetDll_WSAGetLastError("));
    assert!(bindings.contains("pubfnXamInputGetState("));
    assert!(!bindings.contains("pubfnNetDll_getpeername("));
    assert!(!bindings.contains("pubstructX_INPUT_STATE"));
}

#[test]
fn shared_types_are_interchangeable() {
    let _: unsafe extern "C" fn(u32, u32, *mut windef_sys::X_INPUT_STATE) -> u32 =
        xam_sys::XamInputGetState;
    assert_eq!(windef_sys::ULONGLONG_MAX, u64::MAX);
}
