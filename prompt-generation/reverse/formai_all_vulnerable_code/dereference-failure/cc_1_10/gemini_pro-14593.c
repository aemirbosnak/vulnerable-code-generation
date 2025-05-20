//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Custom memory allocator
void *my_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

// Custom memory deallocator
void my_free(void *ptr) {
    if (ptr != NULL) {
        free(ptr);
    }
}

// Custom memory pool
typedef struct {
    void *base;
    size_t size;
    size_t used;
} MemoryPool;

MemoryPool *my_pool_create(size_t size) {
    MemoryPool *pool = my_malloc(sizeof(MemoryPool));
    pool->base = my_malloc(size);
    pool->size = size;
    pool->used = 0;
    return pool;
}

void my_pool_destroy(MemoryPool *pool) {
    if (pool != NULL) {
        if (pool->base != NULL) {
            my_free(pool->base);
        }
        my_free(pool);
    }
}

void *my_pool_alloc(MemoryPool *pool, size_t size) {
    if (pool == NULL) {
        return NULL;
    }
    if (pool->used + size > pool->size) {
        return NULL;
    }
    void *ptr = pool->base + pool->used;
    pool->used += size;
    return ptr;
}

void my_pool_free(MemoryPool *pool, void *ptr) {
    if (pool == NULL || ptr == NULL) {
        return;
    }
    if (ptr < pool->base || ptr >= pool->base + pool->size) {
        return;
    }
    pool->used -= ptr - pool->base;
}

// Custom memory leak detector
#ifdef __has_feature
#if __has_feature(memory_sanitizer)
#define MSAN_ENABLED
#endif
#endif

#ifdef MSAN_ENABLED
#include <sanitizer/msan_interface.h>
#endif

void my_leak_detector(void) {
#ifdef MSAN_ENABLED
    __msan_print_shadow();
#endif
}

int main() {
    // Allocate and deallocate memory using the custom allocator and deallocator
    int *p1 = my_malloc(sizeof(int));
    *p1 = 42;
    printf("Allocated integer: %d\n", *p1);
    my_free(p1);

    // Create and destroy a memory pool
    MemoryPool *pool = my_pool_create(1024);
    int *p2 = my_pool_alloc(pool, sizeof(int));
    *p2 = 100;
    printf("Allocated integer from pool: %d\n", *p2);
    my_pool_free(pool, p2);
    my_pool_destroy(pool);

    // Run the memory leak detector to check for leaks
    my_leak_detector();

    return 0;
}