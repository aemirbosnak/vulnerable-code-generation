//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// A custom memory management function that allocates memory and initializes it to zero.
void *my_calloc(size_t nmemb, size_t size) {
    void *ptr = calloc(nmemb, size);
    if (ptr == NULL) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

// A custom memory management function that reallocates memory and initializes the newly allocated portion to zero.
void *my_realloc(void *ptr, size_t size) {
    ptr = realloc(ptr, size);
    if (ptr == NULL) {
        perror("Error reallocating memory");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

// A custom memory management function that frees memory.
void my_free(void *ptr) {
    free(ptr);
}

// A custom memory management function that prints the memory address of a pointer.
void my_print_address(void *ptr) {
    printf("Memory address: %p\n", ptr);
}

// A custom memory management function that prints the contents of a memory block.
void my_print_memory(void *ptr, size_t size) {
    printf("Memory contents: ");
    for (size_t i = 0; i < size; i++) {
        printf("%02x", ((unsigned char *)ptr)[i]);
    }
    printf("\n");
}

// A custom memory management function that sets all bytes in a memory block to a given value.
void my_memset(void *ptr, int value, size_t size) {
    memset(ptr, value, size);
}

// A custom memory management function that copies a memory block to another memory block.
void my_memcpy(void *dst, void *src, size_t size) {
    memcpy(dst, src, size);
}

// A custom memory management function that compares two memory blocks.
int my_memcmp(void *ptr1, void *ptr2, size_t size) {
    return memcmp(ptr1, ptr2, size);
}

// A custom memory management function that returns the size of a memory block.
size_t my_sizeof(void *ptr) {
    return sizeof(ptr);
}

int main() {
    // Allocate memory for an array of integers.
    int *array = (int *)my_calloc(10, sizeof(int));

    // Initialize the array to zero.
    my_memset(array, 0, 10 * sizeof(int));

    // Print the memory address of the array.
    my_print_address(array);

    // Print the contents of the array.
    my_print_memory(array, 10 * sizeof(int));

    // Reallocate the array to a larger size.
    array = (int *)my_realloc(array, 20 * sizeof(int));

    // Initialize the newly allocated portion of the array to zero.
    my_memset(array + 10, 0, 10 * sizeof(int));

    // Print the contents of the array again.
    my_print_memory(array, 20 * sizeof(int));

    // Free the memory allocated for the array.
    my_free(array);

    return 0;
}