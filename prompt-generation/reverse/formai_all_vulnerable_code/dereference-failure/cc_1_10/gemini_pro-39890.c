//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Custom memory management functions
void* my_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        perror("Error: memory allocation failed");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void my_free(void* ptr) {
    if (ptr != NULL) {
        free(ptr);
    }
}

// Custom data structure with memory management
typedef struct {
    int* data;
    unsigned long length;
} my_array;

// Initialize a my_array with the given length
my_array* my_array_create(unsigned long length) {
    my_array* arr = my_malloc(sizeof(my_array));
    arr->data = my_malloc(length * sizeof(int));
    arr->length = length;
    return arr;
}

// Free the memory of a my_array
void my_array_destroy(my_array* arr) {
    my_free(arr->data);
    my_free(arr);
}

// Print the contents of a my_array
void my_array_print(my_array* arr) {
    for (unsigned long i = 0; i < arr->length; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

// Example usage
int main() {
    // Create an array of 10 integers
    my_array* arr = my_array_create(10);

    // Initialize the array with random values
    for (unsigned long i = 0; i < arr->length; i++) {
        arr->data[i] = rand() % 100;
    }

    // Print the array
    printf("Array: ");
    my_array_print(arr);

    // Free the memory of the array
    my_array_destroy(arr);

    return EXIT_SUCCESS;
}