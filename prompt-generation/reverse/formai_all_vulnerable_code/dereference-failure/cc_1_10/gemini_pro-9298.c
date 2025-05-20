//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Define a custom memory pool structure.
typedef struct memory_pool {
    void *base;
    size_t size;
    size_t allocated;
} memory_pool;

// Initialize a memory pool.
void memory_pool_init(memory_pool *pool, void *base, size_t size) {
    pool->base = base;
    pool->size = size;
    pool->allocated = 0;
}

// Allocate memory from a memory pool.
void *memory_pool_alloc(memory_pool *pool, size_t size) {
    if (pool->allocated + size > pool->size) {
        return NULL;
    }

    void *ptr = pool->base + pool->allocated;
    pool->allocated += size;
    return ptr;
}

// Free memory to a memory pool.
void memory_pool_free(memory_pool *pool, void *ptr) {
    if (ptr < pool->base || ptr >= pool->base + pool->allocated) {
        return;
    }

    pool->allocated -= ptr - (pool->base + pool->allocated);
}

// Destroy a memory pool.
void memory_pool_destroy(memory_pool *pool) {
    free(pool->base);
}

// Create a scalable memory manager.
typedef struct memory_manager {
    memory_pool *pools;
    size_t num_pools;
    size_t max_pool_size;
} memory_manager;

// Initialize a memory manager.
void memory_manager_init(memory_manager *manager, size_t max_pool_size, size_t num_pools) {
    manager->pools = malloc(sizeof(memory_pool) * num_pools);
    manager->num_pools = num_pools;
    manager->max_pool_size = max_pool_size;

    for (size_t i = 0; i < num_pools; i++) {
        void *base = malloc(max_pool_size);
        memory_pool_init(&manager->pools[i], base, max_pool_size);
    }
}

// Allocate memory from a memory manager.
void *memory_manager_alloc(memory_manager *manager, size_t size) {
    for (size_t i = 0; i < manager->num_pools; i++) {
        void *ptr = memory_pool_alloc(&manager->pools[i], size);
        if (ptr != NULL) {
            return ptr;
        }
    }

    return NULL;
}

// Free memory to a memory manager.
void memory_manager_free(memory_manager *manager, void *ptr) {
    for (size_t i = 0; i < manager->num_pools; i++) {
        memory_pool_free(&manager->pools[i], ptr);
    }
}

// Destroy a memory manager.
void memory_manager_destroy(memory_manager *manager) {
    for (size_t i = 0; i < manager->num_pools; i++) {
        memory_pool_destroy(&manager->pools[i]);
    }

    free(manager->pools);
}

// Example usage.
int main() {
    // Create a memory manager with 10 pools, each with a maximum size of 1MB.
    memory_manager manager;
    memory_manager_init(&manager, 1024 * 1024, 10);

    // Allocate 100MB of memory from the manager.
    void *ptr = memory_manager_alloc(&manager, 100 * 1024 * 1024);
    if (ptr == NULL) {
        printf("Failed to allocate memory.\n");
        return 1;
    }

    // Free the memory back to the manager.
    memory_manager_free(&manager, ptr);

    // Destroy the memory manager.
    memory_manager_destroy(&manager);

    return 0;
}