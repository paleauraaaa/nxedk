#![no_std]
#![allow(non_camel_case_types, non_snake_case, non_upper_case_globals)]

//! Shared native Xbox types and constants from NXEDK's `windef.h`.

include!(concat!(env!("OUT_DIR"), "/bindings.rs"));
