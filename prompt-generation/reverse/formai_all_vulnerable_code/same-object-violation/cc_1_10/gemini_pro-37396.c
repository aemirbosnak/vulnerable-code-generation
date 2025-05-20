//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Define a custom memory allocator that allocates memory from a fixed-size pool.
typedef struct {
    void *pool;
    size_t pool_size;
    size_t alloc_size;
    void **free_list;
    size_t free_list_size;
} pool_allocator_t;

// Initialize the memory pool allocator.
void pool_allocator_init(pool_allocator_t *allocator, void *pool, size_t pool_size) {
    allocator->pool = pool;
    allocator->pool_size = pool_size;
    allocator->alloc_size = 0;
    allocator->free_list = NULL;
    allocator->free_list_size = 0;
}

// Allocate memory from the memory pool allocator.
void *pool_allocator_alloc(pool_allocator_t *allocator, size_t size) {
    // Check if the requested size is valid.
    if (size <= 0 || size > allocator->pool_size) {
        return NULL;
    }

    // Check if there are any free blocks in the free list.
    void *block = NULL;
    if (allocator->free_list_size > 0) {
        block = allocator->free_list[allocator->free_list_size - 1];
        allocator->free_list_size--;
    }

    // If there are no free blocks in the free list, allocate a new block from the memory pool.
    if (block == NULL) {
        block = allocator->pool + allocator->alloc_size;
        allocator->alloc_size += size;
    }

    // Return the allocated block.
    return block;
}

// Free memory back to the memory pool allocator.
void pool_allocator_free(pool_allocator_t *allocator, void *block) {
    // Check if the block is valid.
    if (block == NULL || block < allocator->pool || block >= allocator->pool + allocator->alloc_size) {
        return;
    }

    // Add the block to the free list.
    allocator->free_list[allocator->free_list_size++] = block;
}

// Destroy the memory pool allocator.
void pool_allocator_destroy(pool_allocator_t *allocator) {
    // Free all the blocks in the free list.
    for (size_t i = 0; i < allocator->free_list_size; i++) {
        free(allocator->free_list[i]);
    }

    // Free the free list.
    free(allocator->free_list);

    // Free the memory pool.
    free(allocator->pool);
}

// Create a custom memory manager.
typedef struct {
    pool_allocator_t pool_allocator;
    void *memory_pool;
    size_t memory_pool_size;
} memory_manager_t;

// Initialize the custom memory manager.
void memory_manager_init(memory_manager_t *manager, size_t memory_pool_size) {
    // Allocate the memory pool.
    manager->memory_pool = malloc(memory_pool_size);
    if (manager->memory_pool == NULL) {
        return;
    }

    // Initialize the memory pool allocator.
    pool_allocator_init(&manager->pool_allocator, manager->memory_pool, memory_pool_size);

    // Set the memory pool size.
    manager->memory_pool_size = memory_pool_size;
}

// Allocate memory from the custom memory manager.
void *memory_manager_alloc(memory_manager_t *manager, size_t size) {
    // Allocate memory from the memory pool allocator.
    void *block = pool_allocator_alloc(&manager->pool_allocator, size);

    // Return the allocated block.
    return block;
}

// Free memory back to the custom memory manager.
void memory_manager_free(memory_manager_t *manager, void *block) {
    // Free memory back to the memory pool allocator.
    pool_allocator_free(&manager->pool_allocator, block);
}

// Destroy the custom memory manager.
void memory_manager_destroy(memory_manager_t *manager) {
    // Destroy the memory pool allocator.
    pool_allocator_destroy(&manager->pool_allocator);

    // Free the memory pool.
    free(manager->memory_pool);
}

// Create a custom memory allocator that uses a custom memory manager.
typedef struct {
    memory_manager_t *memory_manager;
} custom_allocator_t;

// Initialize the custom memory allocator.
void custom_allocator_init(custom_allocator_t *allocator, memory_manager_t *memory_manager) {
    allocator->memory_manager = memory_manager;
}

// Allocate memory from the custom memory allocator.
void *custom_allocator_alloc(custom_allocator_t *allocator, size_t size) {
    // Allocate memory from the custom memory manager.
    void *block = memory_manager_alloc(allocator->memory_manager, size);

    // Return the allocated block.
    return block;
}

// Free memory back to the custom memory allocator.
void custom_allocator_free(custom_allocator_t *allocator, void *block) {
    // Free memory back to the custom memory manager.
    memory_manager_free(allocator->memory_manager, block);
}

// Destroy the custom memory allocator.
void custom_allocator_destroy(custom_allocator_t *allocator) {
    // Destroy the custom memory manager.
    memory_manager_destroy(allocator->memory_manager);
}

// Create a custom memory manager and use it to allocate and free memory.
int main() {
    // Create a custom memory manager.
    memory_manager_t memory_manager;
    memory_manager_init(&memory_manager, 1024);

    // Create a custom memory allocator.
    custom_allocator_t custom_allocator;
    custom_allocator_init(&custom_allocator, &memory_manager);

    // Allocate memory from the custom memory allocator.
    void *block1 = custom_allocator_alloc(&custom_allocator, 100);
    void *block2 = custom_allocator_alloc(&custom_allocator, 200);
    void *block3 = custom_allocator_alloc(&custom_allocator, 300);

    // Free memory back to the custom memory allocator.
    custom_allocator_free(&custom_allocator, block1);
    custom_allocator_free(&custom_allocator, block2);
    custom_allocator_free(&custom_allocator, block3);

    // Destroy the custom memory allocator.
    custom_allocator_destroy(&custom_allocator);

    // Destroy the custom memory manager.
    memory_manager_destroy(&memory_manager);

    return 0;
}