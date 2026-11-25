#![no_std]
#![allow(non_camel_case_types, non_snake_case, non_upper_case_globals)]

//! Raw bindings to NXEDK's Xbox kernel header and shared native types.
//!
//! Prototypes in the header are inferred and have not all been verified on
//! hardware. Exports with unknown signatures are intentionally omitted.
//! Supply the NXEDK-generated import library when linking an Xbox executable;
//! this crate does not add a link directive.

pub use windef_sys::*;

include!(concat!(env!("OUT_DIR"), "/bindings.rs"));
