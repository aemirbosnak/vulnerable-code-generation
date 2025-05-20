//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// The introspective memory manager

// The memory manager's data structures

typedef struct {
    void *ptr;
    size_t size;
} allocation;

typedef struct {
    size_t capacity;
    size_t used;
    allocation *allocations;
} memory_pool;

// The memory manager's functions

memory_pool *memory_pool_create(size_t capacity) {
    memory_pool *pool = malloc(sizeof(memory_pool));
    pool->capacity = capacity;
    pool->used = 0;
    pool->allocations = malloc(sizeof(allocation) * capacity);
    return pool;
}

void memory_pool_destroy(memory_pool *pool) {
    for (size_t i = 0; i < pool->used; i++) {
        free(pool->allocations[i].ptr);
    }
    free(pool->allocations);
    free(pool);
}

void *memory_pool_malloc(memory_pool *pool, size_t size) {
    if (pool->used == pool->capacity) {
        pool->capacity *= 2;
        pool->allocations = realloc(pool->allocations, sizeof(allocation) * pool->capacity);
    }
    allocation *allocation = &pool->allocations[pool->used++];
    allocation->size = size;
    allocation->ptr = malloc(size);
    return allocation->ptr;
}

void memory_pool_free(memory_pool *pool, void *ptr) {
    for (size_t i = 0; i < pool->used; i++) {
        if (pool->allocations[i].ptr == ptr) {
            free(ptr);
            pool->used--;
            // Move the last allocation to the freed allocation's place
            pool->allocations[i] = pool->allocations[pool->used];
            return;
        }
    }
}

// The introspective memory manager's functions

void memory_pool_print_stats(memory_pool *pool) {
    printf("Memory pool statistics:\n");
    printf("  Capacity: %zu\n", pool->capacity);
    printf("  Used: %zu\n", pool->used);
    printf("  Allocations:\n");
    for (size_t i = 0; i < pool->used; i++) {
        printf("    - Pointer: %p\n", pool->allocations[i].ptr);
        printf("      Size: %zu\n", pool->allocations[i].size);
    }
}

// The introspective memory manager's main function

int main() {
    // Create a memory pool
    memory_pool *pool = memory_pool_create(1024);

    // Allocate some memory from the pool
    void *ptr1 = memory_pool_malloc(pool, 100);
    void *ptr2 = memory_pool_malloc(pool, 200);
    void *ptr3 = memory_pool_malloc(pool, 300);

    // Print the memory pool's statistics
    memory_pool_print_stats(pool);

    // Free some memory from the pool
    memory_pool_free(pool, ptr2);

    // Print the memory pool's statistics again
    memory_pool_print_stats(pool);

    // Destroy the memory pool
    memory_pool_destroy(pool);

    return 0;
}