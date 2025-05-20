//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Definition of a struct to represent a memory block
struct mem_block {
    void* data; // Pointer to the data stored in the block
    size_t size; // Size of the data stored in the block
    struct mem_block* next; // Pointer to the next block in the list
};

// Function to allocate a memory block
struct mem_block* alloc_mem(size_t size) {
    struct mem_block* new_block = (struct mem_block*) malloc(size);
    new_block->data = new_block; // Initialize the data pointer to the block itself
    new_block->size = size;
    new_block->next = NULL;
    return new_block;
}

// Function to deallocate a memory block
void dealloc_mem(struct mem_block* block) {
    free(block);
}

// Function to print the memory usage
void print_mem(struct mem_block* block) {
    printf("Memory Usage: %zu bytes\n", block->size);
}

// Example program
int main() {
    // Create a list of memory blocks
    struct mem_block* head = NULL;
    struct mem_block* block1 = alloc_mem(100);
    struct mem_block* block2 = alloc_mem(200);
    struct mem_block* block3 = alloc_mem(300);
    head = block1;

    // Add the blocks to the list
    block1->next = block2;
    block2->next = block3;

    // Print the memory usage
    print_mem(head);

    // Deallocate the blocks
    dealloc_mem(block1);
    dealloc_mem(block2);
    dealloc_mem(block3);

    return 0;
}