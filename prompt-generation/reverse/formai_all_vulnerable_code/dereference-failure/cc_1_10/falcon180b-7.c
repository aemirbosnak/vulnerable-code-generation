//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000000

typedef struct {
    int *data;
    int size;
} IntArray;

IntArray *createIntArray(int size) {
    IntArray *array = (IntArray *) malloc(sizeof(IntArray));
    array->data = (int *) malloc(sizeof(int) * size);
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

void sortIntArray(IntArray *array) {
    for (int i = 0; i < array->size - 1; i++) {
        for (int j = i + 1; j < array->size; j++) {
            if (array->data[i] > array->data[j]) {
                int temp = array->data[i];
                array->data[i] = array->data[j];
                array->data[j] = temp;
            }
        }
    }
}

int main() {
    srand(time(NULL));

    IntArray *array1 = createIntArray(MAX_SIZE);
    IntArray *array2 = createIntArray(MAX_SIZE);

    fillIntArray(array1, rand() % 100);
    fillIntArray(array2, rand() % 100);

    printf("Before sorting:\n");
    printIntArray(array1);
    printIntArray(array2);

    sortIntArray(array1);
    sortIntArray(array2);

    printf("After sorting:\n");
    printIntArray(array1);
    printIntArray(array2);

    destroyIntArray(array1);
    destroyIntArray(array2);

    return 0;
}