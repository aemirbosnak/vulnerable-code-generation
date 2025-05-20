//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;       // Pointer to the array of integers
    size_t size;      // Current size of the array
    size_t capacity;  // Maximum capacity before resizing
} DynamicArray;

// Function prototypes
DynamicArray* createArray(size_t initialCapacity);
void destroyArray(DynamicArray *arr);
void addElement(DynamicArray *arr, int element);
void removeElement(DynamicArray *arr, size_t index);
void displayArray(const DynamicArray *arr);

// Entry point
int main() {
    printf("Welcome to the whimsical dynamic array manager!\n");

    size_t initialCapacity = 5;
    DynamicArray *myArray = createArray(initialCapacity);

    printf("Adding elements to the array...\n");
    for (int i = 0; i < 10; i++) {
        addElement(myArray, i * 10);
    }

    printf("Current elements in the array:\n");
    displayArray(myArray);

    printf("Removing element at index 3...\n");
    removeElement(myArray, 3);
    displayArray(myArray);

    destroyArray(myArray);
    printf("All done! Memory has been freed. Goodbye!\n");

    return 0;
}

// Create a dynamic array with an initial capacity
DynamicArray* createArray(size_t initialCapacity) {
    DynamicArray *arr = (DynamicArray *)malloc(sizeof(DynamicArray));
    arr->array = (int *)malloc(initialCapacity * sizeof(int));
    arr->size = 0;
    arr->capacity = initialCapacity;
    return arr;
}

// Free the allocated memory for the dynamic array
void destroyArray(DynamicArray *arr) {
    free(arr->array);
    free(arr);
}

// Add an element to the dynamic array, resizing if necessary
void addElement(DynamicArray *arr, int element) {
    if (arr->size >= arr->capacity) {
        arr->capacity *= 2;  // Double the capacity
        arr->array = (int *)realloc(arr->array, arr->capacity * sizeof(int));
        printf("Resized array capacity to: %zu\n", arr->capacity);
    }
    arr->array[arr->size++] = element;
}

// Remove an element from the dynamic array by index
void removeElement(DynamicArray *arr, size_t index) {
    if (index >= arr->size) {
        fprintf(stderr, "Index out of bounds. Unable to remove element.\n");
        return;
    }
    for (size_t i = index; i < arr->size - 1; i++) {
        arr->array[i] = arr->array[i + 1];
    }
    arr->size--;
}

// Display the contents of the dynamic array
void displayArray(const DynamicArray *arr) {
    printf("Array contents: [ ");
    for (size_t i = 0; i < arr->size; i++) {
        printf("%d ", arr->array[i]);
    }
    printf("]\n");
}