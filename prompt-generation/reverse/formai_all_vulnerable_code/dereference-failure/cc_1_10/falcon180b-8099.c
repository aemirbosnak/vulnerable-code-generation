//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000

typedef struct {
    int *data;
    int size;
    int capacity;
} IntArray;

IntArray *createIntArray(int size) {
    IntArray *array = (IntArray *)malloc(sizeof(IntArray));
    array->data = (int *)malloc(sizeof(int) * size);
    array->size = 0;
    array->capacity = size;
    return array;
}

void destroyIntArray(IntArray *array) {
    free(array->data);
    free(array);
}

void resizeIntArray(IntArray *array, int newCapacity) {
    int *newData = (int *)malloc(sizeof(int) * newCapacity);
    memcpy(newData, array->data, sizeof(int) * array->size);
    free(array->data);
    array->data = newData;
    array->capacity = newCapacity;
}

void addIntToArray(IntArray *array, int num) {
    if (array->size == array->capacity) {
        resizeIntArray(array, array->capacity * 2);
    }
    array->data[array->size++] = num;
}

int getIntArraySize(IntArray *array) {
    return array->size;
}

int getIntArrayCapacity(IntArray *array) {
    return array->capacity;
}

int *getIntArrayData(IntArray *array) {
    return array->data;
}

int main() {
    IntArray *array = createIntArray(MAX_SIZE);
    int i;

    for (i = 0; i < MAX_SIZE; i++) {
        addIntToArray(array, i);
    }

    printf("Size: %d, Capacity: %d\n", getIntArraySize(array), getIntArrayCapacity(array));

    for (i = 0; i < MAX_SIZE; i++) {
        printf("%d ", getIntArrayData(array)[i]);
    }

    printf("\n");

    destroyIntArray(array);
    return 0;
}