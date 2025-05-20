//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000000

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

DynamicArray *createDynamicArray() {
    DynamicArray *array = (DynamicArray *)malloc(sizeof(DynamicArray));
    if (array == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
    return array;
}

void destroyDynamicArray(DynamicArray *array) {
    if (array->data!= NULL) {
        free(array->data);
    }
    free(array);
}

void resizeDynamicArray(DynamicArray *array, int newCapacity) {
    int *newData = (int *)malloc(newCapacity * sizeof(int));
    if (newData == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    memcpy(newData, array->data, array->size * sizeof(int));
    free(array->data);
    array->data = newData;
    array->capacity = newCapacity;
}

void addElementToDynamicArray(DynamicArray *array, int element) {
    if (array->size == array->capacity) {
        resizeDynamicArray(array, array->capacity * 2);
    }
    array->data[array->size++] = element;
}

int getElementFromDynamicArray(DynamicArray *array, int index) {
    if (index >= array->size) {
        printf("Error: Index out of bounds\n");
        exit(1);
    }
    return array->data[index];
}

void printDynamicArray(DynamicArray *array) {
    int i;
    for (i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

int main() {
    DynamicArray *array = createDynamicArray();
    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        addElementToDynamicArray(array, i);
    }
    printDynamicArray(array);
    destroyDynamicArray(array);
    return 0;
}