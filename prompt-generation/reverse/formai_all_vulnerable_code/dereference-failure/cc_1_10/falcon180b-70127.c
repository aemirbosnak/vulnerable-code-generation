//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int capacity;
    int size;
} DynamicArray;

// Function to create an empty dynamic array with the specified capacity
DynamicArray *createDynamicArray(int capacity) {
    DynamicArray *array = (DynamicArray *) malloc(sizeof(DynamicArray));
    array->data = (int *) malloc(capacity * sizeof(int));
    array->capacity = capacity;
    array->size = 0;
    return array;
}

// Function to add an element to the end of the dynamic array
void addElement(DynamicArray *array, int value) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->data = (int *) realloc(array->data, array->capacity * sizeof(int));
    }
    array->data[array->size++] = value;
}

// Function to print the elements of the dynamic array
void printArray(DynamicArray *array) {
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

// Function to free the memory used by the dynamic array
void freeDynamicArray(DynamicArray *array) {
    free(array->data);
    free(array);
}

int main() {
    DynamicArray *array = createDynamicArray(5);
    addElement(array, 1);
    addElement(array, 2);
    addElement(array, 3);
    addElement(array, 4);
    addElement(array, 5);
    addElement(array, 6);
    printArray(array);
    freeDynamicArray(array);
    return 0;
}