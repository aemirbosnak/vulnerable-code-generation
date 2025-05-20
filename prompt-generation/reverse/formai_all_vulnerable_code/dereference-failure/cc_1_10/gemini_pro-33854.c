//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: single-threaded
#include <stdlib.h>
#include <stdio.h>

// Define a custom memory allocator
void *my_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Error: Out of memory!\n");
        exit(1);
    }
    return ptr;
}

// Define a custom memory deallocator
void my_free(void *ptr) {
    free(ptr);
}

// Create a custom memory pool
void *my_pool = NULL;
size_t my_pool_size = 0;

// Initialize the memory pool
void my_pool_init(size_t size) {
    my_pool = malloc(size);
    if (my_pool == NULL) {
        fprintf(stderr, "Error: Out of memory!\n");
        exit(1);
    }
    my_pool_size = size;
}

// Allocate memory from the memory pool
void *my_pool_alloc(size_t size) {
    if (size > my_pool_size) {
        fprintf(stderr, "Error: Not enough memory in the pool!\n");
        exit(1);
    }
    void *ptr = my_pool;
    my_pool += size;
    my_pool_size -= size;
    return ptr;
}

// Deallocate memory from the memory pool
void my_pool_free(void *ptr) {
    my_pool = ptr;
    my_pool_size += sizeof(ptr);
}

// Use the custom memory management functions
int main() {
    // Allocate memory using the custom allocator
    int *ptr1 = (int *)my_malloc(sizeof(int));
    *ptr1 = 42;

    // Allocate memory from the custom pool
    int *ptr2 = (int *)my_pool_alloc(sizeof(int));
    *ptr2 = 21;

    // Print the values of the allocated memory
    printf("ptr1: %d\n", *ptr1);
    printf("ptr2: %d\n", *ptr2);

    // Deallocate the memory using the custom deallocator
    my_free(ptr1);
    my_pool_free(ptr2);

    return 0;
}