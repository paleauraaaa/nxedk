#![no_std]
#![allow(non_camel_case_types, non_snake_case, non_upper_case_globals)]

//! Raw bindings to NXEDK's public C API.

include!(concat!(env!("OUT_DIR"), "/bindings.rs"));
