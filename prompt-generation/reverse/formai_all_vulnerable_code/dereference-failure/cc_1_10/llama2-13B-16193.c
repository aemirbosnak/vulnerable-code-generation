//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 20

// Declare a struct to represent a memory block
struct memory_block {
    void* data; // pointer to the data stored in the block
    size_t size; // size of the data stored in the block
    struct memory_block* next; // pointer to the next block in the list
};

// Declare a function to allocate memory
void* alloc_mem(size_t size) {
    // Check if the size is zero
    if (size == 0) {
        return NULL;
    }

    // Create a new memory block
    struct memory_block* block = (struct memory_block*) malloc(sizeof(struct memory_block));
    block->data = malloc(size);
    block->size = size;
    block->next = NULL;

    return block->data;
}

// Declare a function to deallocate memory
void dealloc_mem(void* data) {
    // Check if the data is NULL
    if (data == NULL) {
        return;
    }

    // Get the memory block associated with the data
    struct memory_block* block = (struct memory_block*) data;

    // Free the data and the memory block
    free(block->data);
    free(block);
}

// Declare a function to print the memory usage
void print_mem(void) {
    // Iterate through the memory blocks and print their sizes
    struct memory_block* block = malloc(sizeof(struct memory_block));
    while (block != NULL) {
        printf("%zu bytes allocated\n", block->size);
        block = block->next;
    }
}

int main() {
    // Allocate some memory
    void* data1 = alloc_mem(10);
    void* data2 = alloc_mem(20);
    void* data3 = alloc_mem(30);

    // Print the memory usage
    print_mem();

    // Deallocate the memory
    dealloc_mem(data1);
    dealloc_mem(data2);
    dealloc_mem(data3);

    // Print the memory usage again
    print_mem();

    return 0;
}