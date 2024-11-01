// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
    // Verify if the size is valid
	if (size == 0) {
		return NULL;
    }
    void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    if (ptr == MAP_FAILED) {
        exit(1);
    }
    return ptr;
}

void *calloc(size_t nmemb, size_t size)
{
    // Calculating the total size for malloc
	size_t total_size = nmemb * size;
    void *ptr = malloc(total_size);
    if (ptr) {
        memset(ptr, 0, total_size);
    }
    return ptr;
}

void free(void *ptr)
{
    // Source: https://stackoverflow.com/
    int *plen = (int*)ptr;
    int len;
    plen--;
    len = *plen;
    munmap((void*)plen, len);
}

void *realloc(void *ptr, size_t size)
{
    if (!ptr) {
        return malloc(size);
    }

    if (size == 0) {
        free(ptr);
        exit(1);
    }

    void *new_ptr = malloc(size);
    if (new_ptr) {
        memcpy(new_ptr, ptr, size);
        free(ptr);
    }
    return new_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    // Potential overflow
    if (nmemb > 0 && nmemb < size) {
        return NULL;
    }

    void *new_ptr = realloc(ptr, nmemb * size);

    return new_ptr;
}
