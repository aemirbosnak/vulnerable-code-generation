//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// A custom memory allocator
void* my_malloc(size_t size) {
    void* ptr = malloc(size + sizeof(size_t));
    if (ptr == NULL) {
        return NULL;
    }
    // Store the size of the allocated memory at the beginning of the block
    *(size_t*)ptr = size;
    // Return a pointer to the start of the actual memory block
    return (char*)ptr + sizeof(size_t);
}

// A custom memory deallocator
void my_free(void* ptr) {
    if (ptr == NULL) {
        return;
    }
    // Get the pointer to the actual memory block
    void* real_ptr = (char*)ptr - sizeof(size_t);
    // Get the size of the allocated memory
    size_t size = *(size_t*)real_ptr;
    // Free the memory block
    free(real_ptr);
}

// A custom memory debugger
void my_mem_debug() {
    // Iterate over all memory blocks and print their information
    void* ptr = malloc(1);
    while (ptr != NULL) {
        // Get the size of the allocated memory
        size_t size = *(size_t*)ptr;
        // Get the pointer to the actual memory block
        void* real_ptr = (char*)ptr + sizeof(size_t);
        // Print the memory block information
        printf("Memory block: %p, size: %zu\n", real_ptr, size);
        // Get the next memory block
        ptr = (char*)ptr + size + sizeof(size_t);
    }
}

int main() {
    // Allocate some memory using the custom allocator
    int* ptr = my_malloc(sizeof(int));
    *ptr = 10;

    // Print the memory block information
    my_mem_debug();

    // Deallocate the memory using the custom deallocator
    my_free(ptr);

    // Print the memory block information again
    my_mem_debug();

    return 0;
}