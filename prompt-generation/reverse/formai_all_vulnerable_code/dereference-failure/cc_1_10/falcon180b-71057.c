//Falcon-180B DATASET v1.0 Category: Error handling ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int* data;
    int size;
    int capacity;
} DynamicArray;

DynamicArray* createArray(int capacity) {
    DynamicArray* array = (DynamicArray*) malloc(sizeof(DynamicArray));
    if (array == NULL) {
        printf("Error: Failed to allocate memory\n");
        exit(1);
    }
    array->data = (int*) malloc(capacity * sizeof(int));
    if (array->data == NULL) {
        printf("Error: Failed to allocate memory\n");
        exit(1);
    }
    array->size = 0;
    array->capacity = capacity;
    return array;
}

void destroyArray(DynamicArray* array) {
    free(array->data);
    free(array);
}

void resizeArray(DynamicArray* array, int newCapacity) {
    int* newData = (int*) malloc(newCapacity * sizeof(int));
    if (newData == NULL) {
        printf("Error: Failed to allocate memory\n");
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

void pushBack(DynamicArray* array, int value) {
    if (array->size == array->capacity) {
        resizeArray(array, array->capacity * 2);
    }
    array->data[array->size++] = value;
}

int popBack(DynamicArray* array) {
    if (array->size == 0) {
        printf("Error: Array is empty\n");
        exit(1);
    }
    return array->data[--array->size];
}

int main() {
    DynamicArray* array = createArray(MAX_SIZE);
    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        pushBack(array, i);
    }
    int j;
    for (j = 0; j < MAX_SIZE; j++) {
        printf("%d ", popBack(array));
    }
    destroyArray(array);
    return 0;
}