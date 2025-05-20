//FormAI DATASET v1.0 Category: Memory management ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate memory for a new string
    char* str = (char*) malloc(10 * sizeof(char));
    if (str == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for string.\n");
        exit(1);
    }

    // Copy "Linux" to the new string
    snprintf(str, 10, "%s", "Linux");

    // Allocate memory for two arrays of integers
    int* arr1 = (int*) calloc(5, sizeof(int));
    int* arr2 = (int*) malloc(5 * sizeof(int));
    if (arr1 == NULL || arr2 == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for arrays.\n");
        exit(1);
    }

    // Initialize the arrays with some values
    for (int i = 0; i < 5; i++) {
        arr1[i] = i;
        *(arr2 + i) = i * 2; // Same as arr2[i] = i * 2;
    }

    // Reallocate memory for arr2 with more space
    arr2 = (int*) realloc(arr2, 10 * sizeof(int));
    if (arr2 == NULL) {
        fprintf(stderr, "Error: Failed to reallocate memory for array.\n");
        exit(1);
    }

    // Initialize the rest of the array with some more values
    for (int i = 5; i < 10; i++) {
        *(arr2 + i) = i * 2; // Same as arr2[i] = i * 2;
    }

    // Print the values of the string and arrays
    printf("String: %s\n", str);
    printf("Array 1: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\nArray 2: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", *(arr2 + i)); // Same as arr2[i]
    }

    // Free the allocated memory before exiting
    free(str);
    free(arr1);
    free(arr2);

    return 0;
}