//Falcon-180B DATASET v1.0 Category: Sorting ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MAX_VALUE 1000

typedef struct {
    int *data;
    int size;
} Array;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(Array arr) {
    for (int i = 0; i < arr.size; i++) {
        printf("%d ", arr.data[i]);
    }
    printf("\n");
}

void quickSort(Array arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int partition(Array arr, int low, int high) {
    int pivot = arr.data[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr.data[j] < pivot) {
            i++;
            swap(&arr.data[i], &arr.data[j]);
        }
    }
    swap(&arr.data[i + 1], &arr.data[high]);
    return i + 1;
}

void generateArray(Array *arr) {
    srand(time(NULL));
    for (int i = 0; i < MAX_SIZE; i++) {
        (*arr).data[i] = rand() % MAX_VALUE;
    }
    (*arr).size = MAX_SIZE;
}

int main() {
    Array arr;
    generateArray(&arr);
    printf("Unsorted array:\n");
    printArray(arr);
    quickSort(arr, 0, arr.size - 1);
    printf("Sorted array:\n");
    printArray(arr);
    return 0;
}