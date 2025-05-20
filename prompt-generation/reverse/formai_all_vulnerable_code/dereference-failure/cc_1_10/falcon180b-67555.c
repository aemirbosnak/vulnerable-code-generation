//Falcon-180B DATASET v1.0 Category: Memory management ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

DynamicArray *createDynamicArray(int size) {
    DynamicArray *array = (DynamicArray *) malloc(sizeof(DynamicArray));
    if (array == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    array->data = (int *) malloc(sizeof(int) * size);
    if (array->data == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    array->size = 0;
    array->capacity = size;
    return array;
}

void destroyDynamicArray(DynamicArray *array) {
    free(array->data);
    free(array);
}

void resizeDynamicArray(DynamicArray *array, int newCapacity) {
    int *newData = (int *) malloc(sizeof(int) * newCapacity);
    if (newData == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    int i;
    for (i = 0; i < array->size; i++) {
        newData[i] = array->data[i];
    }
    free(array->data);
    array->data = newData;
    array->capacity = newCapacity;
}

void addElement(DynamicArray *array, int element) {
    if (array->size >= array->capacity) {
        resizeDynamicArray(array, array->capacity * 2);
    }
    array->data[array->size++] = element;
}

void removeElement(DynamicArray *array, int index) {
    if (index < 0 || index >= array->size) {
        printf("Error: Index out of bounds.\n");
        exit(1);
    }
    int i;
    for (i = index; i < array->size - 1; i++) {
        array->data[i] = array->data[i + 1];
    }
    array->size--;
}

void printDynamicArray(DynamicArray *array) {
    int i;
    for (i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

int main() {
    DynamicArray *array = createDynamicArray(MAX_SIZE);
    addElement(array, 1);
    addElement(array, 2);
    addElement(array, 3);
    printDynamicArray(array);
    removeElement(array, 1);
    printDynamicArray(array);
    destroyDynamicArray(array);
    return 0;
}