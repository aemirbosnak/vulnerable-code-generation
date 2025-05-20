//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 20
#define MAX_ARR_SIZE 10

// Structure to store memory block
typedef struct {
    char *addr;
    size_t size;
} mem_block_t;

// Function to allocate memory block
mem_block_t *allocate_mem(size_t size) {
    // Check if size is negative
    if (size < 0) {
        return NULL;
    }

    // Allocate memory using malloc
    void *ptr = malloc(size);
    if (ptr == NULL) {
        return NULL;
    }

    // Create a new memory block struct
    mem_block_t *block = (mem_block_t *) malloc(sizeof(mem_block_t));
    block->addr = ptr;
    block->size = size;

    return block;
}

// Function to deallocate memory block
void deallocate_mem(mem_block_t *block) {
    // Check if block is NULL
    if (block == NULL) {
        return;
    }

    // Free the memory using free
    free(block->addr);
    free(block);
}

// Function to print memory block information
void print_mem_info(mem_block_t *block) {
    if (block == NULL) {
        printf("No memory block to print\n");
        return;
    }

    printf("Memory block address: %p\n", block->addr);
    printf("Memory block size: %zu\n", block->size);
}

// Function to main function
int main() {
    // Allocate memory for a string
    char *str = allocate_mem(10);
    if (str == NULL) {
        printf("Error: Unable to allocate memory for string\n");
        return 1;
    }

    // Allocate memory for an array
    int arr[MAX_ARR_SIZE];
    mem_block_t *arr_block = allocate_mem(sizeof(int) * MAX_ARR_SIZE);
    if (arr_block == NULL) {
        printf("Error: Unable to allocate memory for array\n");
        return 1;
    }

    // Print memory block information
    print_mem_info(arr_block);

    // Deallocate memory for array
    deallocate_mem(arr_block);

    // Print memory block information again
    print_mem_info(arr_block);

    // Deallocate memory for string
    deallocate_mem(str);

    return 0;
}