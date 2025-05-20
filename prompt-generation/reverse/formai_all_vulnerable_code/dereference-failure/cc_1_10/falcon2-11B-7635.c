//Falcon2-11B DATASET v1.0 Category: Memory management ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Structure for a memory block
struct mem_block {
    int size;
    struct mem_block* next;
};

// Structure for memory management system
struct memory_manager {
    struct mem_block* free_list;
    struct mem_block* allocated_list;
    int size;
};

// Allocate a memory block of the specified size
struct mem_block* allocate_block(struct memory_manager* manager, int size) {
    // Check if there are free blocks
    if (manager->free_list!= NULL) {
        // Remove a block from the free list
        struct mem_block* block = manager->free_list;
        manager->free_list = block->next;
        
        // Initialize the new block
        block->size = size;
        block->next = NULL;
        
        // Move the block to the allocated list
        manager->allocated_list = block;
        
        // Return the block
        return block;
    }
    
    // No free blocks, return NULL
    return NULL;
}

// Free a memory block
void free_block(struct memory_manager* manager, struct mem_block* block) {
    // Check if the block is already free
    if (block->next == NULL) {
        // Add the block to the free list
        block->next = manager->free_list;
        manager->free_list = block;
    }
    
    // Otherwise, the block is already in the free list
    // Remove it and add it back to the free list
    else {
        struct mem_block* prev_block = block;
        while (prev_block->next!= NULL) {
            prev_block = prev_block->next;
        }
        
        prev_block->next = block->next;
        block->next = NULL;
    }
}

// Main function
int main() {
    struct memory_manager manager;
    manager.size = 100; // Size of memory blocks in bytes
    
    // Initialize free list
    manager.free_list = NULL;
    
    // Initialize allocated list
    manager.allocated_list = NULL;
    
    // Allocate memory blocks
    struct mem_block* block1 = allocate_block(&manager, 10);
    struct mem_block* block2 = allocate_block(&manager, 20);
    struct mem_block* block3 = allocate_block(&manager, 30);
    
    // Free memory blocks
    free_block(&manager, block1);
    free_block(&manager, block2);
    free_block(&manager, block3);
    
    // Print allocated memory blocks
    printf("Allocated memory blocks:\n");
    struct mem_block* curr_block = manager.allocated_list;
    while (curr_block!= NULL) {
        printf("Block size: %d bytes\n", curr_block->size);
        curr_block = curr_block->next;
    }
    
    return 0;
}