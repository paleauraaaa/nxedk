cmake_minimum_required(VERSION 3.20)

get_filename_component(NXEDK_ROOT "${CMAKE_CURRENT_LIST_DIR}/../.." ABSOLUTE)
set(NXEDK_TOOLCHAIN_BIN_DIR "${NXEDK_ROOT}/toolchain/win32/bin/llvm")
set(NXEDK_CLANG_RESOURCE_DIR "${NXEDK_ROOT}/toolchain/include/clang/23")

if(CMAKE_HOST_WIN32)
    if(NOT DEFINED CMAKE_C_COMPILER)
        set(CMAKE_C_COMPILER "${NXEDK_TOOLCHAIN_BIN_DIR}/clang.exe")
    endif()
    if(NOT DEFINED CMAKE_AR)
        set(CMAKE_AR "${NXEDK_TOOLCHAIN_BIN_DIR}/llvm-ar.exe")
    endif()
else()
    message(FATAL_ERROR "The bundled nxedk toolchain currently supports Windows hosts only")
endif()

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR powerpc)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
set(CMAKE_C_FLAGS_INIT
    "--target=powerpc64-microsoft-xbox360 -mcpu=xenon -resource-dir \"${NXEDK_CLANG_RESOURCE_DIR}\"")
if(NOT DEFINED CMAKE_RANLIB)
    set(CMAKE_RANLIB ":" CACHE INTERNAL "COFF archives do not require ranlib")
endif()

project(nxedk_exit LANGUAGES C)

set(NXEDK_BUILD_DIR "${NXEDK_ROOT}/build")
set(NXEDK_PICOLIBC_BUILD_DIR "${NXEDK_BUILD_DIR}/picolibc")
set(NXEDK_SYNTHXEX "${NXEDK_ROOT}/toolchain/win32/bin/SynthXEX/synthxex.exe")
if(EXISTS "${NXEDK_BUILD_DIR}/mimalloc/libmimalloc.lib")
    set(NXEDK_MIMALLOC_LIBRARY "${NXEDK_BUILD_DIR}/mimalloc/libmimalloc.lib")
elseif(EXISTS "${NXEDK_BUILD_DIR}/mimalloc/libmimalloc-debug.lib")
    set(NXEDK_MIMALLOC_LIBRARY "${NXEDK_BUILD_DIR}/mimalloc/libmimalloc-debug.lib")
else()
    message(FATAL_ERROR "nxedk mimalloc archive not found. Build nxedk first.")
endif()

foreach(required_file IN ITEMS
        "${NXEDK_PICOLIBC_BUILD_DIR}/picocrt/crt0.lib"
        "${NXEDK_BUILD_DIR}/libnxedk.lib"
        "${NXEDK_PICOLIBC_BUILD_DIR}/libc.lib"
        "${NXEDK_BUILD_DIR}/xboxkrnl.lib"
        "${NXEDK_BUILD_DIR}/xam.lib"
        "${NXEDK_SYNTHXEX}")
    if(NOT EXISTS "${required_file}")
        message(FATAL_ERROR
            "Required nxedk build output not found: ${required_file}. Build nxedk first.")
    endif()
endforeach()

add_library(nxedk_crt STATIC IMPORTED GLOBAL)
set_target_properties(nxedk_crt PROPERTIES
    IMPORTED_LOCATION "${NXEDK_PICOLIBC_BUILD_DIR}/picocrt/crt0.lib"
)

add_library(nxedk STATIC IMPORTED GLOBAL)
set_target_properties(nxedk PROPERTIES
    IMPORTED_LOCATION "${NXEDK_BUILD_DIR}/libnxedk.lib"
    INTERFACE_INCLUDE_DIRECTORIES "${NXEDK_ROOT}/include"
)

add_library(nxedk_mimalloc STATIC IMPORTED GLOBAL)
set_target_properties(nxedk_mimalloc PROPERTIES
    IMPORTED_LOCATION "${NXEDK_MIMALLOC_LIBRARY}"
)

add_library(nxedk_picolibc STATIC IMPORTED GLOBAL)
set_target_properties(nxedk_picolibc PROPERTIES
    IMPORTED_LOCATION "${NXEDK_PICOLIBC_BUILD_DIR}/libc.lib"
)
target_include_directories(nxedk_picolibc SYSTEM INTERFACE
    "${NXEDK_ROOT}/src/picolibc/libc/machine/powerpc"
    "${NXEDK_PICOLIBC_BUILD_DIR}"
    "${NXEDK_ROOT}/src/picolibc/libc/include"
    "${NXEDK_ROOT}/src/picolibc/libos/semihost/common"
)

add_library(nxedk_xboxkrnl STATIC IMPORTED GLOBAL)
set_target_properties(nxedk_xboxkrnl PROPERTIES
    IMPORTED_LOCATION "${NXEDK_BUILD_DIR}/xboxkrnl.lib"
)

add_library(nxedk_xam STATIC IMPORTED GLOBAL)
set_target_properties(nxedk_xam PROPERTIES
    IMPORTED_LOCATION "${NXEDK_BUILD_DIR}/xam.lib"
)

add_executable(nxedk_exit exit.c)
set_target_properties(nxedk_exit PROPERTIES
    OUTPUT_NAME exit
    SUFFIX ".exe"
    LINK_DEPENDS
        "${NXEDK_PICOLIBC_BUILD_DIR}/picocrt/crt0.lib;${NXEDK_BUILD_DIR}/libnxedk.lib;${NXEDK_MIMALLOC_LIBRARY};${NXEDK_PICOLIBC_BUILD_DIR}/libc.lib;${NXEDK_BUILD_DIR}/xboxkrnl.lib;${NXEDK_BUILD_DIR}/xam.lib"
)
target_link_options(nxedk_exit PRIVATE
    -nostdlib
    -fuse-ld=lld
    "-Wl,/entry:_start"
    "-Wl,/base:0x90010000"
    "-Wl,/align:4096"
    "-Wl,/machine:ppcbe"
)
target_link_libraries(nxedk_exit PRIVATE
    nxedk_crt
    nxedk
    nxedk_mimalloc
    nxedk_picolibc
    nxedk_xboxkrnl
    nxedk_xam
)

set(NXEDK_EXIT_XEX "${CMAKE_CURRENT_BINARY_DIR}/exit.xex")
add_custom_command(TARGET nxedk_exit POST_BUILD
    COMMAND "${NXEDK_SYNTHXEX}"
        -i "$<TARGET_FILE:nxedk_exit>"
        -o "${NXEDK_EXIT_XEX}"
    BYPRODUCTS "${NXEDK_EXIT_XEX}"
    COMMENT "Packaging exit.exe as exit.xex"
    VERBATIM
)
