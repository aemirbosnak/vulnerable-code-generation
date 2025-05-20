//Falcon-180B DATASET v1.0 Category: Sorting ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

typedef struct {
    int *arr;
    int size;
} Array;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(Array *arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int partition(Array *arr, int low, int high) {
    int pivot = arr->arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr->arr[j] < pivot) {
            i++;
            swap(&arr->arr[i], &arr->arr[j]);
        }
    }
    swap(&arr->arr[i + 1], &arr->arr[high]);
    return i + 1;
}

void printArray(Array *arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->arr[i]);
    }
    printf("\n");
}

int main() {
    Array arr;
    arr.arr = malloc(MAX_SIZE * sizeof(int));
    arr.size = 0;

    int n, m;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr.arr[i]);
        arr.size++;
    }

    printf("Enter the number of elements to sort: ");
    scanf("%d", &m);

    if (m > n) {
        printf("Error: Cannot sort more elements than the size of the array.\n");
        exit(1);
    }

    quickSort(&arr, 0, m - 1);
    printf("Sorted array:\n");
    printArray(&arr);

    free(arr.arr);
    return 0;
}