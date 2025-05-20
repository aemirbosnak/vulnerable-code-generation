//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);
        int partitionIndex = i + 1;

        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int leftSize = m - l + 1;
    int rightSize = r - m;

    int *L = (int *)malloc(leftSize * sizeof(int));
    int *R = (int *)malloc(rightSize * sizeof(int));

    for (i = 0; i < leftSize; i++)
        L[i] = arr[l + i];
    for (j = 0; j < rightSize; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < leftSize && j < rightSize) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < leftSize) {
        arr[k++] = L[i++];
    }

    while (j < rightSize) {
        arr[k++] = R[j++];
    }

    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
}

int main() {
    srand(time(NULL));
    int n = 10;
    int *arr = (int *)malloc(n * sizeof(int));

    generateRandomArray(arr, n);
    printf("Original array:\n");
    printArray(arr, n);

    printf("\nSorting using Bubble Sort:\n");
    bubbleSort(arr, n);
    printArray(arr, n);

    generateRandomArray(arr, n);
    printf("\nOriginal array:\n");
    printArray(arr, n);

    printf("\nSorting using Insertion Sort:\n");
    insertionSort(arr, n);
    printArray(arr, n);

    generateRandomArray(arr, n);
    printf("\nOriginal array:\n");
    printArray(arr, n);

    printf("\nSorting using Selection Sort:\n");
    selectionSort(arr, n);
    printArray(arr, n);

    generateRandomArray(arr, n);
    printf("\nOriginal array:\n");
    printArray(arr, n);

    printf("\nSorting using Quick Sort:\n");
    quickSort(arr, 0, n - 1);
    printArray(arr, n);

    generateRandomArray(arr, n);
    printf("\nOriginal array:\n");
    printArray(arr, n);

    printf("\nSorting using Merge Sort:\n");
    mergeSort(arr, 0, n - 1);
    printArray(arr, n);

    free(arr);
    return 0;
}