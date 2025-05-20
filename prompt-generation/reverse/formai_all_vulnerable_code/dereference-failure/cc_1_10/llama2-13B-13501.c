//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 256
#define MAX_ARRAY_SIZE 1024

// Structure to represent a block of memory
typedef struct {
    void* data; // Pointer to the data stored in the block
    size_t size; // Size of the block in bytes
    struct _mem_block* next; // Pointer to the next block in the list
} mem_block;

// Global variable to store the head of the memory block list
mem_block* mem_block_list = NULL;

// Function to allocate memory from the heap
void* alloc_mem(size_t size) {
    // Check if the size is zero
    if (size == 0) {
        return NULL;
    }

    // Create a new block of memory
    mem_block* new_block = (mem_block*) malloc(sizeof(mem_block));
    new_block->data = NULL;
    new_block->size = size;
    new_block->next = NULL;

    // If the list is empty, make the new block the head
    if (mem_block_list == NULL) {
        mem_block_list = new_block;
    } else {
        // Otherwise, add the new block to the end of the list
        mem_block_list->next = new_block;
    }

    // Return the address of the new block
    return new_block->data;
}

// Function to deallocate memory to the heap
void free_mem(void* data) {
    // Check if the data is NULL
    if (data == NULL) {
        return;
    }

    // Find the block of memory that contains the data
    mem_block* block = mem_block_list;
    while (block != NULL && block->data != data) {
        block = block->next;
    }

    // If the block is found, remove it from the list
    if (block != NULL) {
        if (block == mem_block_list) {
            mem_block_list = block->next;
        }
        free(block);
    }
}

int main() {
    // Allocate some memory for a string
    char* str = alloc_mem(256);
    if (str == NULL) {
        printf("Failed to allocate memory for string\n");
        return 1;
    }

    // Fill the string with some random characters
    for (int i = 0; i < 256; i++) {
        str[i] = (char) (rand() % 256);
    }

    // Allocate some memory for an array of integers
    int* arr = alloc_mem(1024 * sizeof(int));
    if (arr == NULL) {
        printf("Failed to allocate memory for array\n");
        return 1;
    }

    // Fill the array with some random integers
    for (int i = 0; i < 1024; i++) {
        arr[i] = (int) (rand() % 1024);
    }

    // Deallocate the memory for the string and the array
    free_mem(str);
    free_mem(arr);

    return 0;
}