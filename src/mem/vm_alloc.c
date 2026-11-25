#include "nxedk/vm_alloc.h"

#include <errno.h>

#include <stdlib.h>
#include <pthread.h>
#include <sys/mman.h>

#include <xboxkrnl.h>

typedef struct vm_alloc_info {
    void*                   p;
    size_t                  size;
    int                     vm_flags;
    struct vm_alloc_info   *next;
} vm_alloc_info_t;

static vm_alloc_info_t *vm_alloc_list = NULL;

static pthread_mutex_t vm_alloc_list_mutex = PTHREAD_MUTEX_INITIALIZER;

static int vm_lock() {
    return pthread_mutex_lock(&vm_alloc_list_mutex);
}

static int vm_unlock() {
    return pthread_mutex_unlock(&vm_alloc_list_mutex);
}

static size_t vm_page_size_in_bytes(vm_page_size_t page_size) {
    switch (page_size) {
        case VM_PAGE_SIZE_4K:
            return 4 * 1024;
        case VM_PAGE_SIZE_64K:
            return 64 * 1024;
        default:
            return 0;
    }
}

static int vm_prot_to_nt(int vm_prot) {
    if (vm_prot & ~(VM_PROT_READ | VM_PROT_WRITE | VM_PROT_EXEC)) {
        errno = EINVAL;
        return -1;
    }

    if (vm_prot & VM_PROT_EXEC) {
        errno = ENOTSUP;
        return -1;
    }

    if (vm_prot == 0)
        return PAGE_NOACCESS;

    int nt_prot = PAGE_NOACCESS;
    if (vm_prot & VM_PROT_READ) {
        if (vm_prot & VM_PROT_WRITE)
            nt_prot = PAGE_READWRITE;
        else
            nt_prot = PAGE_READONLY;
    } else if (vm_prot & VM_PROT_WRITE) {
        nt_prot = PAGE_WRITECOPY;
    }

    return nt_prot;
}

static void* vm_alloc_physically_contiguous(
    size_t size, vm_page_size_t page_size, 
    int vm_prot, int vm_flags, 
    vm_paddr_t min, vm_paddr_t max) 
{
    if (max == 0)
        max = 0xFFFFFFFF;

    int nt_prot = vm_prot_to_nt(vm_prot);
    if (nt_prot == -1)
        return NULL;
    DWORD prot = (DWORD)nt_prot;

    if (page_size == VM_PAGE_SIZE_64K)
        prot |= MEM_LARGE_PAGES;
    if (vm_flags & VM_WRITE_COMBINING)
        prot |= PAGE_WRITECOMBINE;
    if (vm_flags & VM_NO_CACHE)
        prot |= PAGE_NOCACHE;

    void *p = MmAllocatePhysicalMemoryEx(0, size, prot, min, max,
                                         (DWORD)vm_page_size_in_bytes(page_size));
    if (!p)
        errno = ENOMEM;
    return p;
}

static void vm_free_physically_contiguous(void* p) {
    MmFreePhysicalMemory(0, p);
}

void* vm_alloc_pages(size_t page_count, 
                     vm_page_size_t page_size, 
                     int vm_prot, int vm_flags) 
{
    size_t page_size_bytes = vm_page_size_in_bytes(page_size);
    if (page_size_bytes == 0) {
        errno = EINVAL;
        return NULL;
    }

    if (page_count == 0) {
        errno = EINVAL;
        return NULL;
    }

    if (page_count > SIZE_MAX / page_size_bytes) {
        errno = EOVERFLOW;
        return NULL;
    }

    size_t size = page_count * page_size_bytes;
    
    int flags = MAP_PRIVATE | MAP_ANONYMOUS;
    if (page_size == VM_PAGE_SIZE_64K)
        flags |= MAP_LARGE_PAGES;

    void *p = NULL;
    if ((vm_flags & VM_PHYSICALLY_CONTIGUOUS) == 0) {
        p = mmap(NULL, size, vm_prot, flags, -1, 0);
            if (p == MAP_FAILED) 
                return NULL;
    } else {
        p = vm_alloc_physically_contiguous(size, page_size, 
                                           vm_prot, vm_flags, 
                                           VM_PHYS_NULL, VM_PHYS_NULL);
        if (!p)
            return NULL;
    }
    
    int error = 0;
    vm_alloc_info_t* info = malloc(sizeof(*info));
    if (!info) {
        error = ENOMEM;
        goto fail;
    }

    int ret = vm_lock();
    if (ret != 0) {
        free(info);
        error = ret;
        goto fail;
    }

    info->p         = p;
    info->size      = size;
    info->vm_flags  = vm_flags;
    info->next      = vm_alloc_list;

    vm_alloc_list = info;
    ret = vm_unlock();
    if (ret != 0) {
        // The allocation is already tracked; do not free its backing pages.
        errno = ret;
        return p;
    }

    return p;
    
fail:
    if (p) {
        if (vm_flags & VM_PHYSICALLY_CONTIGUOUS)
            vm_free_physically_contiguous(p);
        else
            munmap(p, size);
    }
    if (error != 0)
        errno = error;
    return NULL;
}

void vm_free_pages(void *p) {
    if (!p)
        return;

    int ret = vm_lock();
    if (ret != 0)
        return;

    vm_alloc_info_t *info = vm_alloc_list;
    if (!info)
        goto done;

    do {
        if (info->p != p) {
            info = info->next;
            continue;
        }

        if (info->vm_flags & VM_PHYSICALLY_CONTIGUOUS) {
            vm_free_physically_contiguous(info->p);
        } else if (munmap(info->p, info->size) != 0) {
            int error = errno;
            vm_unlock();
            errno = error;
            return;
        }

        // Remove from list
        if (info == vm_alloc_list) {
            vm_alloc_list = info->next;
        } else {
            vm_alloc_info_t *prev = vm_alloc_list;
            while (prev && prev->next != info)
                prev = prev->next;
            if (prev)
                prev->next = info->next;
        }
        free(info);
        break;
    } while (info);

done:
    vm_unlock();
}
