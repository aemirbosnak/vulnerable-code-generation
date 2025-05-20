//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void initializeArray(int **array, int size);
void printArray(int *array, int size);
void resizeArray(int **array, int *currentSize, int newSize);
void freeArray(int **array);

// Main program
int main() {
    int *array = NULL;       // Pointer to hold the base address of the array
    int currentSize = 0;    // The current size of allocated memory
    int newSize = 5;        // Initial size for the dynamic array
    int i;                  // Loop counter

    // Step 1: Initialize the dynamic array with allocated memory
    initializeArray(&array, newSize);
    printf("Initialized array of size %d:\n", newSize);
    printArray(array, newSize);

    // Step 2: Resize the array larger
    newSize = 10; // New size for resizing
    resizeArray(&array, &currentSize, newSize);
    printf("Resized array to size %d:\n", newSize);
    printArray(array, newSize);

    // Step 3: Fill the resized array with values and print
    for (i = 5; i < newSize; i++) {
        array[i] = i * 2; // Filling new elements
    }
    printf("Filled array after resizing:\n");
    printArray(array, newSize);

    // Step 4: Resize the array smaller
    newSize = 8; // New size for resizing
    resizeArray(&array, &currentSize, newSize);
    printf("Resized array to size %d:\n", newSize);
    printArray(array, newSize);

    // Step 5: Free the allocated memory
    freeArray(&array);
    printf("Freed array memory.\n");

    return 0;
}

// Function to initialize the array with zeros
void initializeArray(int **array, int size) {
    *array = (int *)malloc(size * sizeof(int));
    if (*array == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < size; i++) {
        (*array)[i] = 0; // Initialize all elements to 0
    }
}

// Function to print the elements of the array
void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Function to resize the array
void resizeArray(int **array, int *currentSize, int newSize) {
    int *temp = (int *)realloc(*array, newSize * sizeof(int));
    if (temp == NULL) {
        fprintf(stderr, "Memory reallocation failed!\n");
        freeArray(array);
        exit(EXIT_FAILURE);
    }
    *array = temp; // Assign the reallocated memory back to the original pointer
    // Initialize new elements if the array was enlarged
    for (int i = *currentSize; i < newSize; i++) {
        (*array)[i] = 0; // Initialize new elements to 0
    }
    *currentSize = newSize; // Update the current size
}

// Function to free the allocated memory of the array
void freeArray(int **array) {
    if (*array != NULL) {
        free(*array);
        *array = NULL; // Set pointer to NULL after freeing
    }
}