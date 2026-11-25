# Xbox 360 Rust environment

This crate sets up the initial Rust environment - it initializes the global
allocator, defines the panic handler, defines print!/println! macros, and in
general adds other niceties to make the no_std environment just a little less
miserable.
