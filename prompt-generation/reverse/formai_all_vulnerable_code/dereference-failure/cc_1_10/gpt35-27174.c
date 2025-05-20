//FormAI DATASET v1.0 Category: Memory management ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Define the number of blocks
#define NUM_BLOCKS 10

// Define the size of each block
#define BLOCK_SIZE 100

// Define a struct for our memory block
typedef struct block_t {
    char data[BLOCK_SIZE];
    int in_use;
} block;

// Define our memory area and an array of blocks
char memory[NUM_BLOCKS * BLOCK_SIZE];
block* block_array[NUM_BLOCKS];

void initialize_memory() {
    // Initialize each block in the array
    for (int i=0; i<NUM_BLOCKS; i++) {
        block_array[i] = (block*) &memory[i*BLOCK_SIZE];
        block_array[i]->in_use = 0;
    }
}

void* allocate_memory(int size) {
    // Find a free block of the appropriate size
    for (int i=0; i<NUM_BLOCKS; i++) {
        if (!block_array[i]->in_use && BLOCK_SIZE >= size) {
            block_array[i]->in_use = 1;
            return (void*) block_array[i]->data;
        }
    }
    
    // If we didn't find a free block, return NULL
    return NULL;
}

void free_memory(void* ptr) {
    // Find the block that ptr points to and free it
    for (int i=0; i<NUM_BLOCKS; i++) {
        if (ptr == (void*) block_array[i]->data) {
            block_array[i]->in_use = 0;
            break;
        }
    }
}

int main() {
    // Initialize our memory area
    initialize_memory();
    
    // Allocate some memory and print the address
    char* ptr1 = (char*) allocate_memory(20);
    printf("ptr1 = %p\n", ptr1);
    
    // Allocate some more memory and print the address
    char* ptr2 = (char*) allocate_memory(50);
    printf("ptr2 = %p\n", ptr2);
    
    // Free the first block of memory
    free_memory((void*) ptr1);
    
    // Allocate another block and print the address
    char* ptr3 = (char*) allocate_memory(30);
    printf("ptr3 = %p\n", ptr3);
    
    // Free the remaining blocks of memory
    free_memory((void*) ptr2);
    free_memory((void*) ptr3);
    
    return 0;
}