//Falcon-180B DATASET v1.0 Category: Memory management ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Function to dynamically allocate memory
void* my_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    return ptr;
}

// Function to free memory
void my_free(void* ptr) {
    free(ptr);
}

// Function to reallocate memory
void* my_realloc(void* ptr, size_t size) {
    void* new_ptr = realloc(ptr, size);
    if (new_ptr == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    return new_ptr;
}

// Function to print memory usage statistics
void print_memory_usage() {
    printf("Current memory usage: %lu bytes\n", my_malloc(0));
}

int main() {
    // Allocate some memory
    void* memory1 = my_malloc(1024);
    void* memory2 = my_malloc(2048);
    void* memory3 = my_malloc(4096);

    // Print memory usage
    print_memory_usage();

    // Free some memory
    my_free(memory1);

    // Print memory usage
    print_memory_usage();

    // Reallocate some memory
    memory2 = my_realloc(memory2, 8192);

    // Print memory usage
    print_memory_usage();

    // Free remaining memory
    my_free(memory2);
    my_free(memory3);

    return 0;
}