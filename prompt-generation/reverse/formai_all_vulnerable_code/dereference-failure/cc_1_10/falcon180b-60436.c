//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1000000

typedef struct {
    int *data;
    int size;
} IntArray;

void initArray(IntArray *array, int size) {
    array->data = (int*) malloc(sizeof(int) * size);
    array->size = size;
}

void destroyArray(IntArray *array) {
    free(array->data);
}

void fillArray(IntArray *array, int value) {
    int i;
    for (i = 0; i < array->size; i++) {
        array->data[i] = value;
    }
}

void printArray(IntArray *array) {
    int i;
    for (i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

int main() {
    IntArray array1, array2;
    initArray(&array1, MAX_SIZE);
    initArray(&array2, MAX_SIZE);

    fillArray(&array1, 1);
    fillArray(&array2, 2);

    int sum = 0;
    clock_t start = clock();
    for (int i = 0; i < MAX_SIZE; i++) {
        sum += array1.data[i] + array2.data[i];
    }
    clock_t end = clock();
    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sum: %d\n", sum);
    printf("Elapsed time: %lf seconds\n", elapsed);

    destroyArray(&array1);
    destroyArray(&array2);

    return 0;
}