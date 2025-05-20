//FormAI DATASET v1.0 Category: Memory management ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Global configuration macros
#define INITIAL_SIZE 10
#define GROWTH_FACTOR 2
#define SHRINK_FACTOR 0.5
#define MIN_SIZE 5

// Struct for dynamically allocated array
typedef struct {
    int* data;
    int size;
    int capacity;
} Array;

// Function to initialize array
void initArray(Array* arr) {
    arr->data = (int*) malloc(INITIAL_SIZE * sizeof(int));
    arr->size = 0;
    arr->capacity = INITIAL_SIZE;
}

// Function to add element to array
void addElement(Array* arr, int element) {
    // Check if array is full
    if (arr->size == arr->capacity) {
        // Increase capacity by growth factor
        arr->capacity *= GROWTH_FACTOR;
        arr->data = (int*) realloc(arr->data, arr->capacity * sizeof(int));
    }
    // Add element to array
    arr->data[arr->size] = element;
    arr->size++;
}

// Function to remove element from array
void removeElement(Array* arr, int index) {
    // Check if index is out of bounds
    if (index >= arr->size || index < 0) {
        printf("Index out of bounds.\n");
        return;
    }
    // Shift elements left to fill gap
    for (int i = index; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i+1];
    }
    // Decrement size
    arr->size--;
    // Check if array is too small
    if (arr->size > MIN_SIZE && arr->size < arr->capacity * SHRINK_FACTOR) {
        // Decrease capacity by shrink factor
        arr->capacity *= SHRINK_FACTOR;
        arr->data = (int*) realloc(arr->data, arr->capacity * sizeof(int));
    }
}

int main() {
    // Initialize array
    Array arr;
    initArray(&arr);

    // Add elements to array
    addElement(&arr, 5);
    addElement(&arr, 10);
    addElement(&arr, 15);
    addElement(&arr, 20);

    // Remove element from array
    printf("Before removal: ");
    for (int i = 0; i < arr.size; i++) {
        printf("%d ", arr.data[i]);
    }
    printf("\n");

    removeElement(&arr, 1);

    printf("After removal: ");
    for (int i = 0; i < arr.size; i++) {
        printf("%d ", arr.data[i]);
    }
    printf("\n");

    // Free dynamically allocated memory
    free(arr.data);

    return 0;
}