//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Define a custom memory manager
typedef struct {
    void *start;
    size_t size;
    size_t used;
} memory_pool;

// Initialize the memory manager
memory_pool *init_memory_pool(void *start, size_t size) {
    memory_pool *pool = malloc(sizeof(memory_pool));
    if (pool == NULL) {
        return NULL;
    }

    pool->start = start;
    pool->size = size;
    pool->used = 0;

    return pool;
}

// Allocate memory from the pool
void *malloc_protected(memory_pool *pool, size_t size) {
    // Check if there is enough space in the pool
    if (pool->used + size > pool->size) {
        return NULL;
    }

    // Allocate the memory
    void *ptr = pool->start + pool->used;
    pool->used += size;

    return ptr;
}

// Free memory back to the pool
void free_protected(memory_pool *pool, void *ptr) {
    // Check if the pointer is within the pool
    if (ptr < pool->start || ptr >= pool->start + pool->size) {
        return;
    }

    // Free the memory
    pool->used -= (ptr - pool->start);
}

// Example usage
int main() {
    // Create a memory pool
    memory_pool *pool = init_memory_pool(malloc(1024), 1024);
    if (pool == NULL) {
        return 1;
    }

    // Allocate memory from the pool
    int *ptr = malloc_protected(pool, sizeof(int));
    if (ptr == NULL) {
        return 1;
    }

    // Use the memory
    *ptr = 42;

    // Free the memory back to the pool
    free_protected(pool, ptr);

    // Destroy the memory pool
    free(pool->start);
    free(pool);

    return 0;
}