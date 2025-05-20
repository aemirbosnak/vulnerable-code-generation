//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000

typedef struct {
    int size;
    int *arr;
} Array;

void initArray(Array *arr, int size) {
    arr->size = size;
    arr->arr = (int *)malloc(sizeof(int) * size);
}

void freeArray(Array *arr) {
    free(arr->arr);
}

void fillArray(Array *arr, int value) {
    for (int i = 0; i < arr->size; i++) {
        arr->arr[i] = value;
    }
}

void printArray(Array arr) {
    for (int i = 0; i < arr.size; i++) {
        printf("%d ", arr.arr[i]);
    }
    printf("\n");
}

void shiftArray(Array *arr, int shift) {
    int temp = arr->arr[0];
    for (int i = 0; i < arr->size - 1; i++) {
        arr->arr[i] = arr->arr[i + 1];
    }
    arr->arr[arr->size - 1] = temp;
}

int main() {
    Array arr1, arr2;
    initArray(&arr1, 5);
    initArray(&arr2, 5);

    fillArray(&arr1, 1);
    fillArray(&arr2, 2);

    printf("Array 1: ");
    printArray(arr1);
    printf("Array 2: ");
    printArray(arr2);

    shiftArray(&arr1, 2);
    shiftArray(&arr2, -3);

    printf("Shifted Array 1: ");
    printArray(arr1);
    printf("Shifted Array 2: ");
    printArray(arr2);

    freeArray(&arr1);
    freeArray(&arr2);

    return 0;
}