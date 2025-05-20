//Falcon-180B DATASET v1.0 Category: Recursive ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int size;
    int *array;
} Array;

void createArray(Array *arr, int size) {
    arr->size = size;
    arr->array = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        arr->array[i] = 0;
    }
}

void printArray(Array arr) {
    for (int i = 0; i < arr.size; i++) {
        printf("%d ", arr.array[i]);
    }
    printf("\n");
}

void mergeArrays(Array *arr1, Array *arr2) {
    int i = 0, j = 0, k = 0;
    while (i < arr1->size && j < arr2->size) {
        if (arr1->array[i] < arr2->array[j]) {
            arr1->array[k++] = arr1->array[i++];
        } else {
            arr1->array[k++] = arr2->array[j++];
        }
    }
    while (i < arr1->size) {
        arr1->array[k++] = arr1->array[i++];
    }
    while (j < arr2->size) {
        arr1->array[k++] = arr2->array[j++];
    }
    arr1->size += arr2->size;
}

void mergeSort(Array *arr) {
    if (arr->size < 2) {
        return;
    }
    int mid = arr->size / 2;
    Array left, right;
    createArray(&left, mid);
    createArray(&right, arr->size - mid);
    for (int i = 0; i < mid; i++) {
        left.array[i] = arr->array[i];
    }
    for (int i = mid; i < arr->size; i++) {
        right.array[i - mid] = arr->array[i];
    }
    mergeSort(&left);
    mergeSort(&right);
    mergeArrays(arr, &left);
    mergeArrays(arr, &right);
}

int main() {
    Array arr;
    createArray(&arr, MAX_SIZE);
    printf("Enter elements of the array:\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        scanf("%d", &arr.array[i]);
    }
    mergeSort(&arr);
    printf("Sorted array:\n");
    printArray(arr);
    return 0;
}