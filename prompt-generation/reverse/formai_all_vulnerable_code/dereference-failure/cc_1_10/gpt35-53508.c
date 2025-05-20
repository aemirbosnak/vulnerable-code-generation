//FormAI DATASET v1.0 Category: Memory management ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX 1024            // Maximum buffer size
#define BLOCK_SIZE 128      // Size of each memory block
#define BLOCKS_NUM MAX/BLOCK_SIZE   // Number of memory blocks
#define MAGIC_NUM 0xDEADBEEF // Random magic number for security purposes

// Memory block data structure
typedef struct block {
    int size;               // Size of the block
    unsigned char *data;    // Actual data
    int magic;              // Magic number to ensure block validity
} block_t;

// Global memory pool data structure
typedef struct mempool {
    int initialized;        // Whether pool has been initialized
    unsigned char *pool;    // Actual memory pool
    block_t blocks[BLOCKS_NUM];     // Block array
} mempool_t;

// Global memory pool variable
static mempool_t mempool = { 0 };

// Function to initialize the memory pool
void mempool_init(void) {
    if (mempool.initialized == 0) {
        mempool.pool = (unsigned char*)malloc(MAX);
        int i;
        for (i = 0; i < BLOCKS_NUM; i++) {
            mempool.blocks[i].size = 0;
            mempool.blocks[i].data = NULL;
        }
        mempool.initialized = 1;
    }
}

// Function to allocate a memory block of specified size
void* mempool_alloc(size_t size) {
    // Initialize pool if not already done
    mempool_init();

    // Find first free block that can hold size bytes
    int i;
    for (i = 0; i < BLOCKS_NUM; i++) {
        if (mempool.blocks[i].size == 0 || 
            mempool.blocks[i].size >= size) {
            break;
        }
    }

    // If no block found, out of memory
    if (i == BLOCKS_NUM) {
        return NULL;
    }

    // Allocate memory in block
    mempool.blocks[i].data = (unsigned char*)malloc(size);
    mempool.blocks[i].size = size;
    mempool.blocks[i].magic = MAGIC_NUM;

    // Return pointer to allocated memory
    return (void*)mempool.blocks[i].data;
}

// Function to free a memory block
void mempool_free(void* ptr) {
    // Find corresponding block
    int i;
    for (i = 0; i < BLOCKS_NUM; i++) {
        if (mempool.blocks[i].data == ptr) {
            break;
        }
    }

    // If block found, free it and set block size to 0
    if (i < BLOCKS_NUM) {
        if (mempool.blocks[i].magic == MAGIC_NUM) {
            free(mempool.blocks[i].data);
            mempool.blocks[i].size = 0;
            mempool.blocks[i].data = NULL;
        }
        else {
            printf("Error: block corrupted\n");
            exit(1);
        }
    }
}

// Example usage
int main(void) {
    // Allocate memory block of size 20
    int *ptr = (int*)mempool_alloc(20);
    if (ptr != NULL) {
        *ptr = 42;
        printf("Value: %d\n", *ptr);
        mempool_free(ptr);
    }
    else {
        printf("Error: out of memory\n");
    }
    return 0;
}