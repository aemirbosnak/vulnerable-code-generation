//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void fillRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // Generate random number between 0 and 999
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

double measureSortingTime(void (*sortFunc)(int[], int), int arr[], int n) {
    clock_t start, end;
    start = clock();
    sortFunc(arr, n);
    end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

int main() {
    int n;
    printf("Enter the number of elements to sort: ");
    scanf("%d", &n);
    
    int *arr1 = (int *)malloc(n * sizeof(int));
    int *arr2 = (int *)malloc(n * sizeof(int));
    int *arr3 = (int *)malloc(n * sizeof(int));
    
    fillRandomArray(arr1, n);
    for (int i = 0; i < n; i++) {
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
    
    printf("Benchmarking Sorting Algorithms with %d Elements...\n", n);
    
    double bubbleTime = measureSortingTime(bubbleSort, arr1, n);
    printf("Bubble Sort took: %f seconds\n", bubbleTime);
    
    double selectionTime = measureSortingTime(selectionSort, arr2, n);
    printf("Selection Sort took: %f seconds\n", selectionTime);
    
    double quickTime = measureSortingTime(quickSort, arr3, n);
    printf("Quick Sort took: %f seconds\n", quickTime);
    
    free(arr1);
    free(arr2);
    free(arr3);
    
    return 0;
}