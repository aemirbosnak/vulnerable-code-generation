//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define INIT_SIZE 10

typedef struct {
    int* data;
    int size;
    int capacity;
} DynamicArray;

DynamicArray* createDynamicArray() {
    DynamicArray* arr = (DynamicArray*) malloc(sizeof(DynamicArray));
    arr->data = (int*) malloc(INIT_SIZE * sizeof(int));
    arr->size = 0;
    arr->capacity = INIT_SIZE;
    return arr;
}

void destroyDynamicArray(DynamicArray* arr) {
    free(arr->data);
    free(arr);
}

void resizeDynamicArray(DynamicArray* arr) {
    int new_capacity = arr->capacity * 2;
    int* new_data = (int*) malloc(new_capacity * sizeof(int));

    for (int i = 0; i < arr->size; i++) {
        new_data[i] = arr->data[i];
    }

    free(arr->data);
    arr->data = new_data;
    arr->capacity = new_capacity;
}

void addElementToDynamicArray(DynamicArray* arr, int element) {
    if (arr->size == arr->capacity) {
        resizeDynamicArray(arr);
    }

    arr->data[arr->size] = element;
    arr->size++;
}

void printDynamicArray(DynamicArray* arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

int main() {
    DynamicArray* arr = createDynamicArray();

    addElementToDynamicArray(arr, 1);
    addElementToDynamicArray(arr, 2);
    addElementToDynamicArray(arr, 3);
    addElementToDynamicArray(arr, 4);

    printDynamicArray(arr);

    destroyDynamicArray(arr);

    return 0;
}