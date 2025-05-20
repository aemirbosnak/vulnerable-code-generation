//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to allocate memory for a string
void* my_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

// Function to deallocate memory for a string
void my_free(void* ptr) {
    free(ptr);
}

// Function to allocate memory for an array of strings
void** my_calloc(size_t nmemb, size_t size) {
    void** arr = calloc(nmemb, size);
    if (arr == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return arr;
}

// Function to deallocate memory for an array of strings
void my_free_arr(void** arr) {
    free(arr);
}

int main() {
    // Allocate memory for an array of strings
    int n = 5;
    void** arr = my_calloc(n, 20);
    if (arr == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for each element in the array
    for (int i = 0; i < n; i++) {
        arr[i] = my_malloc(20);
        if (arr[i] == NULL) {
            fprintf(stderr, "Error: Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
    }

    // Use the allocated memory
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }

    // Deallocate memory for each element in the array
    for (int i = 0; i < n; i++) {
        my_free(arr[i]);
    }

    // Deallocate memory for the array
    my_free_arr(arr);

    return 0;
}