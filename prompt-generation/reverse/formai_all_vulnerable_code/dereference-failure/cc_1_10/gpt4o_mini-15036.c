//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;       // Pointer to the dynamic array
    size_t size;     // Current size of the array
    size_t capacity; // Maximum capacity of the array
} DynamicArray;

// Function to initialize the dynamic array
DynamicArray* createDynamicArray(size_t initialCapacity) {
    DynamicArray *array = malloc(sizeof(DynamicArray));
    if (!array) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    array->data = malloc(initialCapacity * sizeof(int));
    if (!array->data) {
        fprintf(stderr, "Memory allocation failed\n");
        free(array);
        exit(EXIT_FAILURE);
    }
    array->size = 0;
    array->capacity = initialCapacity;
    return array;
}

// Function to add an element to the dynamic array
void addElement(DynamicArray *array, int element) {
    if (array->size == array->capacity) {
        // Increase capacity if needed
        size_t newCapacity = array->capacity * 2;
        int *newData = realloc(array->data, newCapacity * sizeof(int));
        if (!newData) {
            fprintf(stderr, "Memory reallocation failed\n");
            free(array->data);
            free(array);
            exit(EXIT_FAILURE);
        }
        array->data = newData;
        array->capacity = newCapacity;
    }
    array->data[array->size++] = element;
}

// Function to display the contents of the dynamic array
void displayArray(const DynamicArray *array) {
    printf("Dynamic Array Contents: ");
    for (size_t i = 0; i < array->size; ++i) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

// Function to free the allocated memory for the dynamic array
void freeDynamicArray(DynamicArray *array) {
    free(array->data);
    free(array);
}

// Main function
int main() {
    size_t initialCapacity = 4; // Initial capacity of the dynamic array
    DynamicArray *myArray = createDynamicArray(initialCapacity);

    // Add elements to the dynamic array
    for (int i = 1; i <= 10; ++i) {
        addElement(myArray, i);
        displayArray(myArray);
    }

    // Free the allocated memory
    freeDynamicArray(myArray);

    return 0;
}