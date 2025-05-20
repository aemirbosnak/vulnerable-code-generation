//FormAI DATASET v1.0 Category: Memory management ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Define the default size of the memory block
#define DEFAULT_SIZE 10

// Define a struct to represent a block of memory
typedef struct {
    void *location;
    size_t size;
} MemoryBlock;

// Define a global array to hold all allocated memory blocks
MemoryBlock *memory_blocks = NULL;

// Define a global variable to keep track of the number of allocated memory blocks
int num_blocks = 0;

// Define a function to allocate memory
void* my_malloc(size_t size) {
    // Allocate memory using the standard malloc function
    void *location = malloc(size);
    if (location == NULL) {
        printf("Error: could not allocate memory\n");
        exit(1);
    }

    // Add the allocated memory block to the array of memory blocks
    num_blocks++;
    memory_blocks = realloc(memory_blocks, num_blocks * sizeof(MemoryBlock));
    if (memory_blocks == NULL) {
        printf("Error: could not allocate memory\n");
        exit(1);
    }
    memory_blocks[num_blocks - 1].location = location;
    memory_blocks[num_blocks - 1].size = size;

    // Return the allocated memory
    return location;
}

// Define a function to free allocated memory
void my_free(void *location) {
    // Find the memory block corresponding to the specified location
    int block_index = -1;
    for (int i = 0; i < num_blocks; i++) {
        if (memory_blocks[i].location == location) {
            block_index = i;
            break;
        }
    }
    if (block_index == -1) {
        printf("Error: invalid memory block\n");
        exit(1);
    }

    // Free the memory using the standard free function
    free(memory_blocks[block_index].location);

    // Remove the memory block from the array of memory blocks
    num_blocks--;
    for (int i = block_index; i < num_blocks; i++) {
        memory_blocks[i] = memory_blocks[i + 1];
    }
    memory_blocks = realloc(memory_blocks, num_blocks * sizeof(MemoryBlock));
    if (memory_blocks == NULL && num_blocks > 0) {
        printf("Error: could not allocate memory\n");
        exit(1);
    }
}

int main() {
    printf("Welcome to the memory management program!\n");

    // Allocate some memory blocks
    printf("Allocating memory...\n");
    int *my_int = (int*) my_malloc(sizeof(int));
    float *my_float = (float*) my_malloc(sizeof(float) * DEFAULT_SIZE);
    char *my_string = (char*) my_malloc(sizeof(char) * 100);

    // Fill the memory blocks with some data
    printf("Filling memory...\n");
    *my_int = 42;
    for (int i = 0; i < DEFAULT_SIZE; i++) {
        my_float[i] = i * 0.5;
    }
    sprintf(my_string, "Hello, world!");

    // Print the data in the memory blocks
    printf("Printing memory...\n");
    printf("my_int = %d\n", *my_int);
    for (int i = 0; i < DEFAULT_SIZE; i++) {
        printf("my_float[%d] = %f\n", i, my_float[i]);
    }
    printf("my_string = %s\n", my_string);

    // Free the memory blocks
    printf("Freeing memory...\n");
    my_free(my_int);
    my_free(my_float);
    my_free(my_string);

    printf("Memory management program complete!\n");
    return 0;
}