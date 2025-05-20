//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: safe
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *elements;
    size_t size;
    size_t capacity;
} DynamicArray;

void initArray(DynamicArray *array, size_t initialCapacity) {
    array->capacity = initialCapacity;
    array->size = 0;
    array->elements = (int *) malloc(initialCapacity * sizeof(int));
    if (array->elements == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
}

void freeArray(DynamicArray *array) {
    free(array->elements);
    array->elements = NULL; // Prevent dangling pointer
    array->size = 0;
    array->capacity = 0;
}

void resizeArray(DynamicArray *array, size_t newCapacity) {
    int *newElements = (int *) realloc(array->elements, newCapacity * sizeof(int));
    if (newElements == NULL) {
        perror("Failed to resize memory");
        freeArray(array); // Clean up before exiting
        exit(EXIT_FAILURE);
    }
    array->elements = newElements;
    array->capacity = newCapacity;
}

void addElement(DynamicArray *array, int element) {
    if (array->size >= array->capacity) {
        resizeArray(array, array->capacity * 2); // Double the capacity
    }
    array->elements[array->size++] = element;
}

void removeElement(DynamicArray *array) {
    if (array->size > 0) {
        array->size--;
        if (array->size < array->capacity / 4) {
            resizeArray(array, array->capacity / 2); // Halve the capacity if too many empty slots
        }
    } else {
        printf("Array is already empty!\n");
    }
}

void displayArray(const DynamicArray *array) {
    if (array->size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Dynamic Array: ");
    for (size_t i = 0; i < array->size; i++) {
        printf("%d ", array->elements[i]);
    }
    printf("\n");
}

int main() {
    DynamicArray array;
    initArray(&array, 4); // Start with an initial capacity of 4

    addElement(&array, 10);
    addElement(&array, 20);
    addElement(&array, 30);
    addElement(&array, 40);
    
    displayArray(&array);
    
    addElement(&array, 50); // Should trigger a resize
    displayArray(&array);
    
    removeElement(&array);
    displayArray(&array);
    
    // Continue adding and removing elements
    for (int i = 60; i <= 80; i += 10) {
        addElement(&array, i);
    }
    
    displayArray(&array);
    
    for (int i = 0; i < 4; i++) {
        removeElement(&array);
    }
    
    displayArray(&array);
    
    freeArray(&array);

    return 0;
}