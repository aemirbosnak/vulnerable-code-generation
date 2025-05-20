//FormAI DATASET v1.0 Category: Sorting ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    fflush(stdout);
    scanf("%d", &n);

    int *arr = (int*) malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        printf("Enter element #%d: ", i+1);
        fflush(stdout);
        scanf("%d", &arr[i]);
    }
    
    printf("\nOriginal array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bubbleSort(arr, n);
    printf("\n\nSorting using Bubble Sort: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    selectionSort(arr, n);
    printf("\n\nSorting using Selection Sort: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    insertionSort(arr, n);
    printf("\n\nSorting using Insertion Sort: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}