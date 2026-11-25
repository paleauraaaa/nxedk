#[test]
fn generates_prototypes_but_omits_unspecified_parameters() {
    let bindings: String = include_str!(concat!(env!("OUT_DIR"), "/bindings.rs"))
        .split_whitespace()
        .collect();

    assert!(bindings.contains("pubfnDbgPrint("));
    assert!(bindings.contains("pubfnKeQueryInterruptTime("));
    assert!(!bindings.contains("pubfnExAcquireReadWriteLockExclusive("));
    assert!(!bindings.contains("pubstructX_INPUT_STATE"));
}
