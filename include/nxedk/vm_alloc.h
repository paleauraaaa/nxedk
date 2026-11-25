#pragma once

#include <stddef.h>
#include <stdint.h>

#include <sys/mman.h>

#define VM_PAGE_4K_MIN  0x40000000
#define VM_PAGE_64K_MIN 0x80000000
#define VM_PAGE_4K_MAX  (VM_PAGE_64K_MIN - 1)
#define VM_PAGE_64K_MAX 0xFFFFFFFF

typedef uintptr_t vm_paddr_t;
#define VM_PHYS_NULL 0

typedef enum vm_page_size {
    VM_PAGE_SIZE_4K,
    VM_PAGE_SIZE_64K
} vm_page_size_t;

typedef enum vm_prot {
    VM_PROT_NONE    = PROT_NONE,
    VM_PROT_READ    = PROT_READ,
    VM_PROT_WRITE   = PROT_WRITE,
    VM_PROT_EXEC    = PROT_EXEC
} vm_prot_t;

typedef enum vm_flags {
    VM_PHYSICALLY_CONTIGUOUS    = 0x00000001,
    VM_WRITE_COMBINING          = 0x00000002,
    VM_NO_CACHE                 = 0x00000004
} vm_flags_t;

void* vm_alloc_pages(size_t page_count, vm_page_size_t page_size,
                     int vm_prot, int vm_flags);

void vm_free_pages(void *p);    
    