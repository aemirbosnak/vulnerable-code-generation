//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// A custom memory allocator
void* my_malloc(size_t size) {
    // Allocate memory from the operating system
    void* ptr = malloc(size);

    // If the allocation failed, return NULL
    if (!ptr) {
        return NULL;
    }

    // Initialize the allocated memory to zero
    memset(ptr, 0, size);

    // Return the allocated memory
    return ptr;
}

// A custom memory deallocator
void my_free(void* ptr) {
    // Free the memory back to the operating system
    free(ptr);
}

// A custom memory reallocator
void* my_realloc(void* ptr, size_t size) {
    // Reallocate the memory from the operating system
    void* new_ptr = realloc(ptr, size);

    // If the reallocation failed, return NULL
    if (!new_ptr) {
        return NULL;
    }

    // Return the reallocated memory
    return new_ptr;
}

int main() {
    // Allocate some memory using my_malloc()
    int* array = (int*) my_malloc(sizeof(int) * 10);

    // Use the allocated memory
    for (int i = 0; i < 10; i++) {
        array[i] = i;
    }

    // Reallocate the memory using my_realloc()
    array = (int*) my_realloc(array, sizeof(int) * 20);

    // Use the reallocated memory
    for (int i = 10; i < 20; i++) {
        array[i] = i;
    }

    // Free the memory using my_free()
    my_free(array);

    return 0;
}