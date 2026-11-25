#![no_std]
#![allow(non_camel_case_types, non_snake_case, non_upper_case_globals)]

//! Raw bindings to NXEDK's XAM header.
//!
//! Prototypes in the header are inferred and have not all been verified on
//! hardware. Exports with unknown signatures are intentionally omitted.
//! Provide the NXEDK-generated import libraries to the final linker as needed.

pub use windef_sys::*;

include!(concat!(env!("OUT_DIR"), "/bindings.rs"));
