//Falcon-180B DATASET v1.0 Category: Memory management ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int size;
    int capacity;
    int *data;
} DynamicArray;

DynamicArray *createDynamicArray(int capacity) {
    DynamicArray *array = (DynamicArray *) malloc(sizeof(DynamicArray));
    array->size = 0;
    array->capacity = capacity;
    array->data = (int *) malloc(sizeof(int) * capacity);
    return array;
}

void resizeDynamicArray(DynamicArray *array, int newCapacity) {
    int *tempData = (int *) malloc(sizeof(int) * newCapacity);
    for (int i = 0; i < array->size; i++) {
        tempData[i] = array->data[i];
    }
    free(array->data);
    array->data = tempData;
    array->capacity = newCapacity;
}

void addElementDynamicArray(DynamicArray *array, int element) {
    if (array->size == array->capacity) {
        resizeDynamicArray(array, array->capacity * 2);
    }
    array->data[array->size++] = element;
}

void printDynamicArray(DynamicArray *array) {
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

int main() {
    DynamicArray *array = createDynamicArray(MAX_SIZE);
    for (int i = 0; i < 10; i++) {
        addElementDynamicArray(array, i * 10);
    }
    printDynamicArray(array);

    for (int i = 0; i < 5; i++) {
        addElementDynamicArray(array, MAX_SIZE - 5 + i);
    }
    printDynamicArray(array);

    for (int i = 0; i < 10; i++) {
        addElementDynamicArray(array, 2 * i * MAX_SIZE - 1);
    }
    printDynamicArray(array);

    return 0;
}