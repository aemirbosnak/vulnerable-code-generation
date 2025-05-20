//Falcon-180B DATASET v1.0 Category: Sorting ; Style: complex
// This is a complex C program that sorts an array of integers using the Merge Sort algorithm.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000

typedef struct {
    int *arr;
    int size;
} Array;

void merge(Array *left, Array *right, Array *result) {
    int i = 0, j = 0, k = 0;

    while (i < left->size && j < right->size) {
        if (left->arr[i] < right->arr[j]) {
            result->arr[k] = left->arr[i];
            i++;
        } else {
            result->arr[k] = right->arr[j];
            j++;
        }
        k++;
    }

    while (i < left->size) {
        result->arr[k] = left->arr[i];
        i++;
        k++;
    }

    while (j < right->size) {
        result->arr[k] = right->arr[j];
        j++;
        k++;
    }
}

void mergeSort(Array *arr) {
    int mid;

    if (arr->size == 1) {
        return;
    }

    mid = arr->size / 2;

    Array left, right;

    left.arr = (int*)malloc(mid * sizeof(int));
    left.size = mid;

    right.arr = (int*)malloc((arr->size - mid) * sizeof(int));
    right.size = arr->size - mid;

    for (int i = 0; i < mid; i++) {
        left.arr[i] = arr->arr[i];
    }

    for (int i = mid; i < arr->size; i++) {
        right.arr[i - mid] = arr->arr[i];
    }

    mergeSort(&left);
    mergeSort(&right);

    merge(arr, &right, arr);
    merge(arr, &left, arr);

    free(left.arr);
    free(right.arr);
}

void printArray(Array *arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    Array arr;

    arr.arr = (int*)malloc(MAX_SIZE * sizeof(int));
    arr.size = rand() % MAX_SIZE + 1;

    for (int i = 0; i < arr.size; i++) {
        arr.arr[i] = rand() % 1000;
    }

    printf("Unsorted array:\n");
    printArray(&arr);

    mergeSort(&arr);

    printf("Sorted array:\n");
    printArray(&arr);

    return 0;
}