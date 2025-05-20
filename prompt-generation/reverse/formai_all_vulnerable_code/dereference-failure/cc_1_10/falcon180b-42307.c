//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define INITIAL_CAPACITY 10

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

void initArray(DynamicArray *array) {
    array->data = (int *)malloc(INITIAL_CAPACITY * sizeof(int));
    array->size = 0;
    array->capacity = INITIAL_CAPACITY;
}

void resizeArray(DynamicArray *array) {
    array->capacity *= 2;
    int *newData = (int *)malloc(array->capacity * sizeof(int));
    memcpy(newData, array->data, array->size * sizeof(int));
    free(array->data);
    array->data = newData;
}

void addElement(DynamicArray *array, int element) {
    if (array->size == array->capacity) {
        resizeArray(array);
    }
    array->data[array->size++] = element;
}

void printArray(DynamicArray *array) {
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

int main() {
    DynamicArray arr;
    initArray(&arr);

    addElement(&arr, 10);
    addElement(&arr, 20);
    addElement(&arr, 30);
    addElement(&arr, 40);
    addElement(&arr, 50);

    printArray(&arr);

    return 0;
}