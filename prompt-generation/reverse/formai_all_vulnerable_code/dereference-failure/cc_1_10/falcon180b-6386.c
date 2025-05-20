//Falcon-180B DATASET v1.0 Category: Memory management ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

DynamicArray *createDynamicArray() {
    DynamicArray *arr = (DynamicArray *)malloc(sizeof(DynamicArray));
    if (arr == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    arr->data = (int *)malloc(MAX_SIZE * sizeof(int));
    if (arr->data == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    arr->size = 0;
    arr->capacity = MAX_SIZE;
    return arr;
}

void resizeDynamicArray(DynamicArray *arr) {
    int *newData = (int *)malloc(arr->capacity * 2 * sizeof(int));
    if (newData == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    memcpy(newData, arr->data, arr->size * sizeof(int));
    free(arr->data);
    arr->data = newData;
    arr->capacity *= 2;
}

void addElementToDynamicArray(DynamicArray *arr, int element) {
    if (arr->size == arr->capacity) {
        resizeDynamicArray(arr);
    }
    arr->data[arr->size] = element;
    arr->size++;
}

void deleteElementFromDynamicArray(DynamicArray *arr, int index) {
    if (index >= arr->size) {
        printf("Index out of bounds\n");
        return;
    }
    for (int i = index; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    arr->size--;
    if (arr->size < arr->capacity / 4) {
        resizeDynamicArray(arr);
    }
}

void printDynamicArray(DynamicArray *arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

int main() {
    DynamicArray *arr = createDynamicArray();
    addElementToDynamicArray(arr, 1);
    addElementToDynamicArray(arr, 2);
    addElementToDynamicArray(arr, 3);
    printDynamicArray(arr);
    deleteElementFromDynamicArray(arr, 1);
    printDynamicArray(arr);
    deleteElementFromDynamicArray(arr, 0);
    printDynamicArray(arr);
    deleteElementFromDynamicArray(arr, 1);
    printDynamicArray(arr);
    free(arr->data);
    free(arr);
    return 0;
}