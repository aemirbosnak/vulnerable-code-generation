//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000

typedef struct {
    int *data;
    int size;
} IntArray;

IntArray* createArray(int size) {
    IntArray *array = (IntArray*) malloc(sizeof(IntArray));
    array->data = (int*) malloc(sizeof(int) * size);
    array->size = size;
    return array;
}

void destroyArray(IntArray *array) {
    free(array->data);
    free(array);
}

void printArray(IntArray *array) {
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

void addArray(IntArray *array1, IntArray *array2) {
    for (int i = 0; i < array1->size; i++) {
        array1->data[i] += array2->data[i];
    }
}

void multiplyArray(IntArray *array, int scalar) {
    for (int i = 0; i < array->size; i++) {
        array->data[i] *= scalar;
    }
}

int main() {
    IntArray *array1 = createArray(MAX_SIZE);
    IntArray *array2 = createArray(MAX_SIZE);

    for (int i = 0; i < MAX_SIZE; i++) {
        array1->data[i] = i;
        array2->data[i] = MAX_SIZE - i;
    }

    printf("Array 1:\n");
    printArray(array1);

    printf("Array 2:\n");
    printArray(array2);

    addArray(array1, array2);

    printf("Sum:\n");
    printArray(array1);

    multiplyArray(array1, 2);

    printf("Multiplied by 2:\n");
    printArray(array1);

    destroyArray(array1);
    destroyArray(array2);

    return 0;
}