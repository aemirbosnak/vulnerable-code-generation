//FormAI DATASET v1.0 Category: Memory management ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Define a structure for holding memory blocks
typedef struct {
    int size;
    char *block;
} MemoryBlock;

// Define a structure for holding allocated memory blocks
typedef struct {
    MemoryBlock blocks[MAX_SIZE];
    int num_blocks;
} MemoryPool;

// Global variable for our memory pool
MemoryPool pool;

// Calculate the total size of all allocated memory blocks
int get_total_size() {
    int total_size = 0;
    for (int i=0; i<pool.num_blocks; i++) {
        total_size += pool.blocks[i].size;
    }
    return total_size;
}

// Allocate a block of memory of the given size
void* allocate(int size) {
    // Check if there is enough space in the pool
    if (get_total_size() + size > MAX_SIZE) {
        printf("Memory pool full!");
        return NULL;
    }

    // Allocate the memory block
    MemoryBlock block;
    block.block = (char*) malloc(size);
    block.size = size;

    // Add the block to the pool
    pool.blocks[pool.num_blocks++] = block;

    // Return a pointer to the block
    return block.block;
}

// Free a block of memory at the given pointer
void deallocate(void *ptr) {
    // Find the block in the pool
    int index = -1;
    for (int i=0; i<pool.num_blocks; i++) {
        if (pool.blocks[i].block == ptr) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Block not found!");
        return;
    }

    // Free the memory block
    free(pool.blocks[index].block);

    // Remove the block from the pool
    for (int i=index; i<pool.num_blocks-1; i++) {
        pool.blocks[i] = pool.blocks[i+1];
    }
    pool.num_blocks--;
}

// Main function for testing our memory management
int main() {
    // Allocate some memory blocks
    int *a = (int*) allocate(sizeof(int));
    int *b = (int*) allocate(sizeof(int));
    char *c = (char*) allocate(sizeof(char)*10);

    // Test the memory blocks
    *a = 10;
    *b = 20;
    c[0] = 'h';
    c[1] = 'e';
    c[2] = 'l';
    c[3] = 'l';
    c[4] = 'o';
    c[5] = '\0';

    printf("a = %d\n", *a);
    printf("b = %d\n", *b);
    printf("c = %s\n", c);

    // Free some memory blocks
    deallocate(a);
    deallocate(b);

    // Try to allocate more memory than is available
    int *d = (int*) allocate(MAX_SIZE);
    if (d == NULL) {
        printf("Allocation failed!\n");
    }

    // Free the remaining memory blocks
    deallocate(c);
    deallocate(d);

    return 0;
}