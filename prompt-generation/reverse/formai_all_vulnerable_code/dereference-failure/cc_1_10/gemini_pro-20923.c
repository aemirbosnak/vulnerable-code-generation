//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Define memory block sizes
#define BLOCK_SIZE_SMALL 1024
#define BLOCK_SIZE_MEDIUM 4096
#define BLOCK_SIZE_LARGE 16384

// Define memory pool structures
typedef struct MemPool {
    void* base;
    size_t size;
    size_t used;
    struct MemPool* next;
} MemPool;

// Define memory block structures
typedef struct MemBlock {
    void* addr;
    size_t size;
    struct MemBlock* next;
} MemBlock;

// Create a new memory pool
MemPool* mem_pool_new(size_t size) {
    MemPool* pool = malloc(sizeof(MemPool));
    pool->base = malloc(size);
    pool->size = size;
    pool->used = 0;
    pool->next = NULL;
    return pool;
}

// Destroy a memory pool
void mem_pool_destroy(MemPool* pool) {
    while (pool) {
        MemPool* next = pool->next;
        free(pool->base);
        free(pool);
        pool = next;
    }
}

// Allocate a memory block from a pool
MemBlock* mem_block_alloc(MemPool* pool, size_t size) {
    if (pool->used + size > pool->size) {
        return NULL;
    }

    MemBlock* block = malloc(sizeof(MemBlock));
    block->addr = pool->base + pool->used;
    block->size = size;
    block->next = NULL;

    pool->used += size;

    return block;
}

// Free a memory block
void mem_block_free(MemBlock* block) {
    free(block);
}

// Main function
int main() {
    // Create a small memory pool
    MemPool* smallPool = mem_pool_new(BLOCK_SIZE_SMALL);

    // Allocate a block from the small pool
    MemBlock* smallBlock = mem_block_alloc(smallPool, 512);

    // Check if the block was allocated successfully
    if (smallBlock) {
        printf("Allocated a small block of size %lu bytes\n", smallBlock->size);
    } else {
        printf("Failed to allocate a small block\n");
    }

    // Create a medium memory pool
    MemPool* mediumPool = mem_pool_new(BLOCK_SIZE_MEDIUM);

    // Allocate a block from the medium pool
    MemBlock* mediumBlock = mem_block_alloc(mediumPool, 2048);

    // Check if the block was allocated successfully
    if (mediumBlock) {
        printf("Allocated a medium block of size %lu bytes\n", mediumBlock->size);
    } else {
        printf("Failed to allocate a medium block\n");
    }

    // Create a large memory pool
    MemPool* largePool = mem_pool_new(BLOCK_SIZE_LARGE);

    // Allocate a block from the large pool
    MemBlock* largeBlock = mem_block_alloc(largePool, 8192);

    // Check if the block was allocated successfully
    if (largeBlock) {
        printf("Allocated a large block of size %lu bytes\n", largeBlock->size);
    } else {
        printf("Failed to allocate a large block\n");
    }

    // Free the allocated blocks
    mem_block_free(smallBlock);
    mem_block_free(mediumBlock);
    mem_block_free(largeBlock);

    // Destroy the memory pools
    mem_pool_destroy(smallPool);
    mem_pool_destroy(mediumPool);
    mem_pool_destroy(largePool);

    return 0;
}