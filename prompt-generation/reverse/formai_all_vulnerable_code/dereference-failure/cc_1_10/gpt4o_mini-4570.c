//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int arr[], int size);
void swap(int *a, int *b);
void selectionSort(int arr[], int n);
int* generateRandomArray(int size, int maxVal);

int main() {
    int size = 10;
    int maxVal = 100;
    
    srand(time(NULL));
    
    int *arr = generateRandomArray(size, maxVal);
    
    printf("Original array:\n");
    printArray(arr, size);
    
    selectionSort(arr, size);
    
    printf("Sorted array:\n");
    printArray(arr, size);
    
    free(arr);
    return 0;
}

int* generateRandomArray(int size, int maxVal) {
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % maxVal;
    }
    return arr;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n) {
    int i, j, minIdx;

    for (i = 0; i < n - 1; i++) {
        minIdx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(&arr[minIdx], &arr[i]);
    }
}