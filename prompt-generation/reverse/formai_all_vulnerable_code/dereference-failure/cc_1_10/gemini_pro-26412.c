//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// Define the memory pool structure
typedef struct mem_pool {
    void *start;
    size_t size;
    struct mem_pool *next;
} mem_pool;

// Define the memory block structure
typedef struct mem_block {
    size_t size;
    struct mem_block *next;
} mem_block;

// Create a new memory pool
mem_pool *mem_pool_create(size_t size) {
    mem_pool *pool = malloc(sizeof(mem_pool));
    if (pool == NULL) {
        return NULL;
    }

    pool->start = malloc(size);
    if (pool->start == NULL) {
        free(pool);
        return NULL;
    }

    pool->size = size;
    pool->next = NULL;

    return pool;
}

// Destroy a memory pool
void mem_pool_destroy(mem_pool *pool) {
    mem_pool *next;

    while (pool != NULL) {
        next = pool->next;
        free(pool->start);
        free(pool);
        pool = next;
    }
}

// Allocate a memory block from a memory pool
mem_block *mem_block_alloc(mem_pool *pool, size_t size) {
    mem_block *block;

    // Check if the pool has enough space
    if (pool->size < size) {
        return NULL;
    }

    // Allocate the memory block
    block = malloc(sizeof(mem_block));
    if (block == NULL) {
        return NULL;
    }

    block->size = size;
    block->next = NULL;

    // Add the memory block to the pool
    pool->size -= size;
    block->next = pool->start;
    pool->start = block;

    return block;
}

// Free a memory block
void mem_block_free(mem_block *block) {
    free(block);
}

// Get the total size of all the memory pools
size_t mem_pool_total_size(mem_pool *pool) {
    size_t total_size = 0;

    while (pool != NULL) {
        total_size += pool->size;
        pool = pool->next;
    }

    return total_size;
}

// Get the total size of all the memory blocks
size_t mem_block_total_size(mem_block *block) {
    size_t total_size = 0;

    while (block != NULL) {
        total_size += block->size;
        block = block->next;
    }

    return total_size;
}

// Print the memory usage
void mem_usage_print(mem_pool *pool, mem_block *block) {
    printf("Total memory pool size: %zu bytes\n", mem_pool_total_size(pool));
    printf("Total memory block size: %zu bytes\n", mem_block_total_size(block));
}

// Main function
int main(void) {
    // Create a memory pool
    mem_pool *pool = mem_pool_create(1024);
    if (pool == NULL) {
        printf("Error creating memory pool\n");
        return EXIT_FAILURE;
    }

    // Allocate some memory blocks
    mem_block *block1 = mem_block_alloc(pool, 128);
    if (block1 == NULL) {
        printf("Error allocating memory block 1\n");
        mem_pool_destroy(pool);
        return EXIT_FAILURE;
    }

    mem_block *block2 = mem_block_alloc(pool, 256);
    if (block2 == NULL) {
        printf("Error allocating memory block 2\n");
        mem_block_free(block1);
        mem_pool_destroy(pool);
        return EXIT_FAILURE;
    }

    // Free the memory blocks
    mem_block_free(block1);
    mem_block_free(block2);

    // Destroy the memory pool
    mem_pool_destroy(pool);

    // Print the memory usage
    mem_usage_print(NULL, NULL);

    return EXIT_SUCCESS;
}