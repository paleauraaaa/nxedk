cmake_minimum_required(VERSION 3.20)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(NXEDK_TOOLCHAIN_DIR "${CMAKE_CURRENT_SOURCE_DIR}/toolchain")
set(NXEDK_TOOLCHAIN_INCLUDE_DIR "${NXEDK_TOOLCHAIN_DIR}/include")
set(NXEDK_TOOLCHAIN_RESOURCE_DIR "${NXEDK_TOOLCHAIN_INCLUDE_DIR}/clang/23")

if(CMAKE_HOST_WIN32)
    set(NXEDK_TOOLCHAIN_PLATFORM_DIR "${NXEDK_TOOLCHAIN_DIR}/win32")
    set(NXEDK_TOOLCHAIN_BIN_DIR "${NXEDK_TOOLCHAIN_PLATFORM_DIR}/bin/llvm")
    set(NXEDK_TOOLCHAIN_LIB_DIR "${NXEDK_TOOLCHAIN_PLATFORM_DIR}/lib")
else()
    message(FATAL_ERROR "The bundled NXEDK toolchain currently supports Windows hosts only")
endif()

if(NOT DEFINED CMAKE_C_COMPILER OR CMAKE_C_COMPILER STREQUAL "")
    set(CMAKE_C_COMPILER "${NXEDK_TOOLCHAIN_BIN_DIR}/clang.exe")
endif()

if (NOT DEFINED CMAKE_CXX_COMPILER OR CMAKE_CXX_COMPILER STREQUAL "")
    set(CMAKE_CXX_COMPILER "${NXEDK_TOOLCHAIN_BIN_DIR}/clang++.exe")
endif()

if (NOT DEFINED CMAKE_ASM_COMPILER OR CMAKE_ASM_COMPILER STREQUAL "")
    set(CMAKE_ASM_COMPILER "${NXEDK_TOOLCHAIN_BIN_DIR}/clang.exe")
endif()

if (NOT DEFINED CMAKE_C_LINKER OR CMAKE_C_LINKER STREQUAL "")
    set(CMAKE_C_LINKER "${NXEDK_TOOLCHAIN_BIN_DIR}/lld-link.exe")
endif()

if (NOT DEFINED CMAKE_AR OR CMAKE_AR STREQUAL "")
    set(CMAKE_AR "${NXEDK_TOOLCHAIN_BIN_DIR}/llvm-ar.exe")
endif()

set(NXEDK_COMMON_FLAGS "--target=powerpc64-microsoft-xbox360 -mcpu=xenon -resource-dir \"${NXEDK_TOOLCHAIN_RESOURCE_DIR}\"")
set(CMAKE_C_FLAGS_INIT "${NXEDK_COMMON_FLAGS}")
set(CMAKE_CXX_FLAGS_INIT "${NXEDK_COMMON_FLAGS}")
set(CMAKE_ASM_FLAGS_INIT "${NXEDK_COMMON_FLAGS}")
if(NOT DEFINED CMAKE_RANLIB)
    set(CMAKE_RANLIB ":" CACHE INTERNAL "COFF archives do not require ranlib")
endif()

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR powerpc)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

project(nxedk LANGUAGES C ASM)

find_package(Python3 REQUIRED COMPONENTS Interpreter)

set(PICOLIBC_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/picolibc")
set(PICOLIBC_BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}/picolibc")
set(PICOLIBC_CROSS_FILE "${PICOLIBC_SOURCE_DIR}/scripts/cross-xbox360.txt")
set(NXEDK_PICOLIBC_CROSS_FILE
    "${CMAKE_CURRENT_SOURCE_DIR}/toolchain/win32/config/picolibc-config.txt")
set(PICOLIBC_LIBRARY "${PICOLIBC_BUILD_DIR}/libc.lib")
set(PICOLIBC_CRT "${PICOLIBC_BUILD_DIR}/picocrt/crt0.lib")

foreach(cross_file IN ITEMS
        "${PICOLIBC_CROSS_FILE}"
        "${NXEDK_PICOLIBC_CROSS_FILE}")
    if(NOT EXISTS "${cross_file}")
        message(FATAL_ERROR "Picolibc cross file not found: ${cross_file}")
    endif()
endforeach()

set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS
    "${PICOLIBC_CROSS_FILE}"
    "${NXEDK_PICOLIBC_CROSS_FILE}")

set(picolibc_setup_args)
if(EXISTS "${PICOLIBC_BUILD_DIR}/meson-private/coredata.dat")
    list(APPEND picolibc_setup_args --reconfigure)
endif()

execute_process(
    COMMAND "${Python3_EXECUTABLE}" -m mesonbuild.mesonmain setup
        ${picolibc_setup_args}
        "${PICOLIBC_BUILD_DIR}"
        "${PICOLIBC_SOURCE_DIR}"
        --cross-file "${PICOLIBC_CROSS_FILE}"
        --cross-file "${NXEDK_PICOLIBC_CROSS_FILE}"
    RESULT_VARIABLE picolibc_setup_result
)
if(NOT "${picolibc_setup_result}" STREQUAL "0")
    message(FATAL_ERROR
        "Meson failed to configure Picolibc (exit code: ${picolibc_setup_result})")
endif()

add_custom_target(picolibc_build
    COMMAND "${Python3_EXECUTABLE}" -m mesonbuild.mesonmain compile
        -C "${PICOLIBC_BUILD_DIR}"
    BYPRODUCTS "${PICOLIBC_LIBRARY}" "${PICOLIBC_CRT}"
    COMMENT "Building Xbox 360 Picolibc"
    VERBATIM
)

add_library(c STATIC IMPORTED GLOBAL)
set_target_properties(c PROPERTIES
    IMPORTED_LOCATION "${PICOLIBC_LIBRARY}"
)

set(PICOLIBC_INCLUDE_DIRS)
foreach(include_dir IN ITEMS
        "${PICOLIBC_SOURCE_DIR}/libc/machine/powerpc"
        "${PICOLIBC_SOURCE_DIR}/libc/machine/powerpc/include"
        "${PICOLIBC_BUILD_DIR}"
        "${PICOLIBC_SOURCE_DIR}/libc/include"
        "${PICOLIBC_SOURCE_DIR}/libos/semihost/common")
    if(EXISTS "${include_dir}")
        list(APPEND PICOLIBC_INCLUDE_DIRS "${include_dir}")
    endif()
endforeach()
target_include_directories(c SYSTEM INTERFACE ${PICOLIBC_INCLUDE_DIRS})

set(MI_BUILD_SHARED OFF)
set(MI_BUILD_STATIC ON)
set(MI_BUILD_OBJECT OFF)
set(MI_BUILD_TESTS OFF)
set(MI_OVERRIDE ON)
set(MI_PROFILE OFF CACHE STRING "Enable mimalloc profiling" FORCE)
set(MI_STATS OFF CACHE STRING "Enable mimalloc statistics" FORCE)
add_subdirectory(src/mimalloc mimalloc)
set_target_properties(mimalloc-static PROPERTIES SUFFIX ".lib")
target_include_directories(mimalloc-static PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
target_include_directories(mimalloc-static SYSTEM PRIVATE
    $<TARGET_PROPERTY:c,INTERFACE_INCLUDE_DIRECTORIES>
)

function(add_xbox_import_library target output def_file)
    set(output_path "${CMAKE_CURRENT_BINARY_DIR}/${output}")
    set(def_path "${CMAKE_CURRENT_SOURCE_DIR}/${def_file}")

    add_custom_command(
        OUTPUT "${output_path}"
        COMMAND "${CMAKE_C_LINKER}"
            /lib
            "/def:${def_path}"
            /machine:ppcbe
            "/out:${output_path}"
        DEPENDS "${def_path}"
        COMMENT "Generating ${output} from ${def_file}"
        VERBATIM
    )
    add_custom_target(${target} DEPENDS "${output_path}")
    set(${target}_FILE "${output_path}" PARENT_SCOPE)
endfunction()

add_xbox_import_library(xboxkrnl_import_lib xboxkrnl.lib src/native/xboxkrnl.def)
add_xbox_import_library(xam_import_lib xam.lib src/native/xam.def)

add_library(nxedk STATIC
    src/nxedk.c
    src/mem/vm_alloc.c
)
set_target_properties(nxedk PROPERTIES SUFFIX ".lib")
add_dependencies(nxedk picolibc_build)
target_include_directories(nxedk PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
target_link_libraries(nxedk PUBLIC
    mimalloc-static
    c
    "${xboxkrnl_import_lib_FILE}"
    "${xam_import_lib_FILE}"
)
add_dependencies(nxedk xboxkrnl_import_lib xam_import_lib)
