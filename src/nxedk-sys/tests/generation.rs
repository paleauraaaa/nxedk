#[test]
fn generates_bindings_from_nxedk_headers() {
    let bindings: String = include_str!(concat!(env!("OUT_DIR"), "/bindings.rs"))
        .split_whitespace()
        .collect();

    assert!(bindings.contains("pubfnnxedk_init("));
    assert!(bindings.contains("pubfnvm_alloc_pages("));
    assert!(bindings.contains("pubfnvm_free_pages("));
    assert!(bindings.contains("pubtypevm_paddr_t="));
    assert!(bindings.contains("pubconstVM_PAGE_4K_MIN:"));
    assert!(!bindings.contains("pubfnmmap("));
}
