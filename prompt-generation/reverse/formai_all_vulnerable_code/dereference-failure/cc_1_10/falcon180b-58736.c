//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000000

typedef struct {
    int *data;
    int size;
} IntArray;

IntArray *createIntArray(int size) {
    IntArray *array = malloc(sizeof(IntArray));
    array->data = malloc(size * sizeof(int));
    array->size = size;
    return array;
}

void destroyIntArray(IntArray *array) {
    free(array->data);
    free(array);
}

void fillIntArray(IntArray *array, int value) {
    for (int i = 0; i < array->size; i++) {
        array->data[i] = value;
    }
}

void printIntArray(IntArray *array) {
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

void addIntArrays(IntArray *array1, IntArray *array2, IntArray *result) {
    for (int i = 0; i < array1->size; i++) {
        result->data[i] = array1->data[i] + array2->data[i];
    }
}

int main() {
    IntArray *array1 = createIntArray(MAX_SIZE);
    IntArray *array2 = createIntArray(MAX_SIZE);
    IntArray *result = createIntArray(MAX_SIZE);

    fillIntArray(array1, 1);
    fillIntArray(array2, 2);

    addIntArrays(array1, array2, result);

    printf("Result:\n");
    printIntArray(result);

    destroyIntArray(array1);
    destroyIntArray(array2);
    destroyIntArray(result);

    return 0;
}