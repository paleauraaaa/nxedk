# Kernal/XAM library defs and Rust bindings.

This directory contains .def files to generate our xboxkrnl.lib and xam.lib 
import libraries from, and our Rust bindings to those libraries. Additionally,
types used by these APIs are defined in windef-sys.

The xboxkrnl and xam headers contain many functions with unspecified signatures
because their signatures are currently unknown. These functions are omitted 
from the Rust bindings.

The `build.rs` in this directory is symlinked into these three crates. 
DO NOT delete it.