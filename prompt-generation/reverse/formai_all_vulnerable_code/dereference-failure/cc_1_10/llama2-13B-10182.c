//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to allocate memory dynamically
void* my_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Error: unable to allocate memory\n");
        exit(1);
    }
    return ptr;
}

// Function to deallocate memory dynamically
void my_free(void* ptr) {
    free(ptr);
}

int main() {
    // Dynamic memory allocation example 1: allocating an array of integers
    int* arr = my_malloc(10 * sizeof(int));
    if (arr == NULL) {
        return 1;
    }
    for (int i = 0; i < 10; i++) {
        arr[i] = i * 2;
    }
    printf("Array: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Dynamic memory allocation example 2: allocating a string
    char* str = my_malloc(20 * sizeof(char));
    if (str == NULL) {
        return 1;
    }
    strcpy(str, "Hello, world!");
    printf("String: %s\n", str);

    // Dynamic memory allocation example 3: allocating a 2D array
    int** matrix = my_malloc(3 * sizeof(int*));
    if (matrix == NULL) {
        return 1;
    }
    for (int i = 0; i < 3; i++) {
        matrix[i] = my_malloc(3 * sizeof(int));
        if (matrix[i] == NULL) {
            return 1;
        }
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = i * j;
        }
    }
    printf("Matrix: \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Deallocating memory
    my_free(arr);
    my_free(str);
    for (int i = 0; i < 3; i++) {
        my_free(matrix[i]);
    }
    my_free(matrix);
    return 0;
}