//Falcon-180B DATASET v1.0 Category: Error handling ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int* data;
    int size;
    int capacity;
} DynamicArray;

DynamicArray* createDynamicArray() {
    DynamicArray* array = (DynamicArray*) malloc(sizeof(DynamicArray));
    array->data = (int*) malloc(MAX_SIZE * sizeof(int));
    array->size = 0;
    array->capacity = MAX_SIZE;
    return array;
}

void destroyDynamicArray(DynamicArray* array) {
    free(array->data);
    free(array);
}

void resizeDynamicArray(DynamicArray* array) {
    array->capacity *= 2;
    int* newData = (int*) malloc(array->capacity * sizeof(int));
    for (int i = 0; i < array->size; i++) {
        newData[i] = array->data[i];
    }
    free(array->data);
    array->data = newData;
}

void addElementToDynamicArray(DynamicArray* array, int element) {
    if (array->size == array->capacity) {
        resizeDynamicArray(array);
    }
    array->data[array->size++] = element;
}

int getElementFromDynamicArray(DynamicArray* array, int index) {
    if (index >= array->size) {
        printf("Index out of bounds!\n");
        exit(1);
    }
    return array->data[index];
}

void main() {
    DynamicArray* array = createDynamicArray();
    addElementToDynamicArray(array, 1);
    addElementToDynamicArray(array, 2);
    addElementToDynamicArray(array, 3);
    addElementToDynamicArray(array, 4);
    addElementToDynamicArray(array, 5);

    printf("Element at index 0: %d\n", getElementFromDynamicArray(array, 0));
    printf("Element at index 1: %d\n", getElementFromDynamicArray(array, 1));
    printf("Element at index 2: %d\n", getElementFromDynamicArray(array, 2));
    printf("Element at index 3: %d\n", getElementFromDynamicArray(array, 3));
    printf("Element at index 4: %d\n", getElementFromDynamicArray(array, 4));

    destroyDynamicArray(array);
}