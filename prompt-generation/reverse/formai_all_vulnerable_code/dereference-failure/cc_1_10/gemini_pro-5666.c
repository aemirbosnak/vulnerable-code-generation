//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Constants
#define MEMORY_SIZE 1024 * 1024 * 1024
#define BLOCK_SIZE 1024 * 1024

// Data structures
typedef struct {
    void *ptr;
    size_t size;
} Block;

typedef struct {
    Block *blocks;
    size_t num_blocks;
} MemoryPool;

// Function prototypes
MemoryPool *memory_pool_init();
void memory_pool_free(MemoryPool *pool);
void *memory_pool_alloc(MemoryPool *pool, size_t size);
void memory_pool_free_block(MemoryPool *pool, Block *block);
void memory_pool_print_stats(MemoryPool *pool);

// Main function
int main() {
    // Initialize memory pool
    MemoryPool *pool = memory_pool_init();

    // Allocate memory blocks
    void *ptr1 = memory_pool_alloc(pool, 1024);
    void *ptr2 = memory_pool_alloc(pool, 2048);
    void *ptr3 = memory_pool_alloc(pool, 4096);

    // Print memory pool statistics
    memory_pool_print_stats(pool);

    // Free memory blocks
    memory_pool_free_block(pool, ptr1);
    memory_pool_free_block(pool, ptr2);
    memory_pool_free_block(pool, ptr3);

    // Free memory pool
    memory_pool_free(pool);

    return 0;
}

// Memory pool initialization function
MemoryPool *memory_pool_init() {
    // Allocate memory for the memory pool
    MemoryPool *pool = malloc(sizeof(MemoryPool));
    if (pool == NULL) {
        return NULL;
    }

    // Initialize memory pool data
    pool->blocks = NULL;
    pool->num_blocks = 0;

    return pool;
}

// Memory pool free function
void memory_pool_free(MemoryPool *pool) {
    // Free memory blocks
    for (size_t i = 0; i < pool->num_blocks; i++) {
        memory_pool_free_block(pool, &pool->blocks[i]);
    }

    // Free memory pool
    free(pool);
}

// Memory pool allocation function
void *memory_pool_alloc(MemoryPool *pool, size_t size) {
    // Round up size to block size
    size = (size + BLOCK_SIZE - 1) & ~(BLOCK_SIZE - 1);

    // Allocate memory block
    void *ptr = malloc(size);
    if (ptr == NULL) {
        return NULL;
    }

    // Add memory block to pool
    Block block = {
        .ptr = ptr,
        .size = size,
    };
    pool->blocks = realloc(pool->blocks, sizeof(Block) * (pool->num_blocks + 1));
    pool->blocks[pool->num_blocks] = block;
    pool->num_blocks++;

    return ptr;
}

// Memory pool free block function
void memory_pool_free_block(MemoryPool *pool, Block *block) {
    // Find memory block in pool
    size_t index = 0;
    while (index < pool->num_blocks && pool->blocks[index].ptr != block->ptr) {
        index++;
    }

    // If memory block was found, remove it from pool
    if (index < pool->num_blocks) {
        pool->num_blocks--;
        pool->blocks[index] = pool->blocks[pool->num_blocks];
        pool->blocks = realloc(pool->blocks, sizeof(Block) * pool->num_blocks);
    }

    // Free memory block
    free(block->ptr);
}

// Memory pool print statistics function
void memory_pool_print_stats(MemoryPool *pool) {
    // Calculate total memory used
    size_t total_memory = 0;
    for (size_t i = 0; i < pool->num_blocks; i++) {
        total_memory += pool->blocks[i].size;
    }

    // Print memory pool statistics
    printf("Memory pool statistics:\n");
    printf("Number of blocks: %zu\n", pool->num_blocks);
    printf("Total memory used: %zu bytes\n", total_memory);
}