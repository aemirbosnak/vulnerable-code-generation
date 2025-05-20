//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a dynamic array
typedef struct {
    int *data;        // Pointer to the data
    size_t size;      // Current size of the array
    size_t capacity;  // Maximum capacity of the array
} DynamicArray;

// Function to initialize the dynamic array
DynamicArray* createArray(size_t initialCapacity) {
    DynamicArray *array = (DynamicArray *)malloc(sizeof(DynamicArray));
    if (!array) {
        perror("Failed to allocate memory for the array.");
        exit(EXIT_FAILURE);
    }
    array->data = (int *)malloc(initialCapacity * sizeof(int));
    if (!array->data) {
        perror("Failed to allocate memory for the data.");
        free(array);
        exit(EXIT_FAILURE);
    }
    array->size = 0;
    array->capacity = initialCapacity;
    return array;
}

// Function to add an element to the dynamic array
void addElement(DynamicArray *array, int value) {
    // Check if reallocation is needed
    if (array->size >= array->capacity) {
        array->capacity *= 2; // Double the capacity
        array->data = (int *)realloc(array->data, array->capacity * sizeof(int));
        if (!array->data) {
            perror("Failed to reallocate memory for the data.");
            exit(EXIT_FAILURE);
        }
    }
    array->data[array->size++] = value; // Add value and increment size
}

// Function to print the dynamic array
void printArray(DynamicArray *array) {
    printf("Dynamic Array: [ ");
    for (size_t i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("]\n");
}

// Function to free the memory allocated for the dynamic array
void freeArray(DynamicArray *array) {
    free(array->data); // Free the data array
    free(array);       // Free the array structure
}

// Main function
int main() {
    DynamicArray *myArray = createArray(2); // Start with a capacity of 2

    // Simulate adding elements to the dynamic array
    for (int i = 0; i < 10; i++) {
        addElement(myArray, i * 10); // Add multiples of 10
        printArray(myArray);          // Print the array after each addition
    }

    // Free the allocated memory before exiting
    freeArray(myArray);

    return 0;
}