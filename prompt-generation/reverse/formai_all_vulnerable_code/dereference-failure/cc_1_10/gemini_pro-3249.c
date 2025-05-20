//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Define memory management configuration
#define MEM_SIZE 1024 // Size of memory pool in bytes
#define MEM_BLOCK_SIZE 64 // Size of each memory block in bytes
#define MEM_BLOCK_COUNT (MEM_SIZE / MEM_BLOCK_SIZE) // Number of memory blocks

// Define memory pool and block management structures
typedef struct mem_block {
    void* ptr;
    struct mem_block* next;
} mem_block;

mem_block* mem_pool = NULL; // Memory pool
mem_block* free_list = NULL; // Free list of memory blocks

// Initialize memory management system
void mem_init() {
    // Allocate memory pool
    mem_pool = malloc(MEM_SIZE);
    if (mem_pool == NULL) {
        printf("Error: Failed to allocate memory pool.\n");
        exit(1);
    }

    // Initialize free list
    for (int i = 0; i < MEM_BLOCK_COUNT; i++) {
        mem_block* block = (mem_block*) (mem_pool + i * MEM_BLOCK_SIZE);
        block->ptr = mem_pool + i * MEM_BLOCK_SIZE;
        block->next = free_list;
        free_list = block;
    }
}

// Allocate memory from pool
void* mem_malloc(size_t size) {
    // Check if requested size is valid
    if (size > MEM_BLOCK_SIZE) {
        printf("Error: Requested memory size exceeds block size.\n");
        return NULL;
    }

    // Check if there are free blocks available
    if (free_list == NULL) {
        printf("Error: Memory pool is full.\n");
        return NULL;
    }

    // Get a free block
    mem_block* block = free_list;
    free_list = free_list->next;

    // Return the memory pointer
    return block->ptr;
}

// Free memory back to pool
void mem_free(void* ptr) {
    // Check if memory pointer is valid
    if (ptr < mem_pool || ptr >= mem_pool + MEM_SIZE) {
        printf("Error: Invalid memory pointer.\n");
        return;
    }

    // Get the memory block
    mem_block* block = (mem_block*) ptr;

    // Add block to free list
    block->next = free_list;
    free_list = block;
}

// Print memory usage statistics
void mem_stats() {
    int used_blocks = 0;
    mem_block* block = free_list;
    while (block != NULL) {
        used_blocks++;
        block = block->next;
    }

    printf("Memory usage statistics:\n");
    printf("Total blocks: %d\n", MEM_BLOCK_COUNT);
    printf("Used blocks: %d\n", used_blocks);
    printf("Free blocks: %d\n", MEM_BLOCK_COUNT - used_blocks);
}

// Test memory management system
int main() {
    // Initialize memory management system
    mem_init();

    // Allocate memory blocks
    void* ptr1 = mem_malloc(32);
    void* ptr2 = mem_malloc(64);
    void* ptr3 = mem_malloc(16);

    // Free memory blocks
    mem_free(ptr2);
    mem_free(ptr3);

    // Print memory usage statistics
    mem_stats();

    // Free remaining memory block
    mem_free(ptr1);

    // Print memory usage statistics
    mem_stats();

    return 0;
}