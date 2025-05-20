//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: safe
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 1000

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

DynamicArray *createArray() {
    DynamicArray *array = (DynamicArray *)malloc(sizeof(DynamicArray));
    array->data = (int *)malloc(MAX_SIZE * sizeof(int));
    array->size = 0;
    array->capacity = MAX_SIZE;
    return array;
}

void destroyArray(DynamicArray *array) {
    free(array->data);
    free(array);
}

void addElement(DynamicArray *array, int element) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->data = (int *)realloc(array->data, array->capacity * sizeof(int));
    }
    array->data[array->size++] = element;
}

int findElement(DynamicArray *array, int element) {
    for (int i = 0; i < array->size; i++) {
        if (array->data[i] == element) {
            return i;
        }
    }
    return -1;
}

int main() {
    DynamicArray *array = createArray();
    for (int i = 0; i < 10; i++) {
        addElement(array, i);
    }
    int index = findElement(array, 5);
    printf("Index of 5 is: %d\n", index);
    destroyArray(array);
    return 0;
}