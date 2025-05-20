//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

DynamicArray *createDynamicArray() {
    DynamicArray *array = (DynamicArray *)malloc(sizeof(DynamicArray));
    array->data = (int *)malloc(MAX_SIZE * sizeof(int));
    array->size = 0;
    array->capacity = MAX_SIZE;
    return array;
}

void resizeDynamicArray(DynamicArray *array) {
    array->capacity *= 2;
    int *newData = (int *)malloc(array->capacity * sizeof(int));
    for (int i = 0; i < array->size; i++) {
        newData[i] = array->data[i];
    }
    free(array->data);
    array->data = newData;
}

void addElementToDynamicArray(DynamicArray *array, int element) {
    if (array->size == array->capacity) {
        resizeDynamicArray(array);
    }
    array->data[array->size++] = element;
}

void printDynamicArray(DynamicArray *array) {
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

void main() {
    DynamicArray *array = createDynamicArray();
    srand(time(NULL));
    for (int i = 0; i < 20; i++) {
        int element = rand() % 100;
        addElementToDynamicArray(array, element);
    }
    printDynamicArray(array);
    for (int i = 0; i < 30; i++) {
        int element = rand() % 100;
        addElementToDynamicArray(array, element);
    }
    printDynamicArray(array);
}