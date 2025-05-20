//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 20
#define MAX_ARRAY_LEN 10

// Function to allocate memory for a string
void* my_strdup(const char* str) {
    // Calculate the size of the string including the null terminator
    size_t len = strlen(str) + 1;

    // Allocate memory for the string using malloc
    void* ret = malloc(len);

    // Copy the string to the allocated memory
    memcpy(ret, str, len);

    return ret;
}

// Function to allocate memory for an array
void* my_malloc_array(size_t num_elems, size_t elem_size) {
    // Calculate the total size of the array
    size_t total_size = num_elems * elem_size;

    // Allocate memory for the array using malloc
    void* ret = malloc(total_size);

    return ret;
}

// Function to deallocate memory for a string
void my_free(void* str) {
    free(str);
}

// Function to deallocate memory for an array
void my_free_array(void* arr, size_t num_elems) {
    free(arr);
}

int main() {
    // Allocate memory for a string
    char* str = my_strdup("Hello, world!");

    // Print the allocated string
    printf("Allocated string: %s\n", str);

    // Allocate memory for an array of integers
    int* arr = my_malloc_array(5, sizeof(int));

    // Initialize the array elements
    for (size_t i = 0; i < 5; i++) {
        arr[i] = i * 2;
    }

    // Print the array elements
    for (size_t i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Deallocate memory for the string
    my_free(str);

    // Deallocate memory for the array
    my_free_array(arr, 5);

    return 0;
}