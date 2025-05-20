//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: minimalist
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
    IntArray *array = (IntArray *)malloc(sizeof(IntArray));
    if (array == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    array->data = (int *)malloc(sizeof(int) * size);
    if (array->data == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    array->size = size;
    return array;
}

void destroyIntArray(IntArray *array) {
    free(array->data);
    free(array);
}

void fillIntArray(IntArray *array, int value) {
    int i;
    for (i = 0; i < array->size; i++) {
        array->data[i] = value;
    }
}

void printIntArray(IntArray *array) {
    int i;
    for (i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

int main() {
    IntArray *array1, *array2, *result;
    int i, j, k;

    srand(time(NULL));

    array1 = createIntArray(MAX_SIZE);
    array2 = createIntArray(MAX_SIZE);

    for (i = 0; i < MAX_SIZE; i++) {
        array1->data[i] = rand() % 1000;
        array2->data[i] = rand() % 1000;
    }

    result = (IntArray *)malloc(sizeof(IntArray));
    if (result == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }

    for (i = 0; i < MAX_SIZE; i++) {
        result->data[i] = array1->data[i] + array2->data[i];
    }

    printIntArray(array1);
    printIntArray(array2);
    printIntArray(result);

    destroyIntArray(array1);
    destroyIntArray(array2);
    destroyIntArray(result);

    return 0;
}