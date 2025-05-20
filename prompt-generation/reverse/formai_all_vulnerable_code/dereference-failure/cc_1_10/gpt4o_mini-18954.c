//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate an array of random integers
void generateRandomArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000; // Random integers from 0 to 9999
    }
}

// Bubble Sort Algorithm
void bubbleSort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Partition function for Quick Sort
int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
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

// Quick Sort Algorithm
void quickSort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Merge function for Merge Sort
void merge(int *arr, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp arrays
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copy data to temp arrays
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into arr[left..right]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

// Merge Sort Algorithm
void mergeSort(int *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Function to time the sorting algorithms
void benchmarkSorting(int *arr, int size) {
    int *arrCopy = malloc(size * sizeof(int));
    
    // Benchmark Bubble Sort
    for (int i = 0; i < size; i++) arrCopy[i] = arr[i];
    clock_t start = clock();
    bubbleSort(arrCopy, size);
    clock_t end = clock();
    printf("Bubble Sort took: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Benchmark Quick Sort
    for (int i = 0; i < size; i++) arrCopy[i] = arr[i];
    start = clock();
    quickSort(arrCopy, 0, size - 1);
    end = clock();
    printf("Quick Sort took: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Benchmark Merge Sort
    for (int i = 0; i < size; i++) arrCopy[i] = arr[i];
    start = clock();
    mergeSort(arrCopy, 0, size - 1);
    end = clock();
    printf("Merge Sort took: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(arrCopy);
}

int main() {
    srand(time(NULL));
    int size = 10000; // Size of the array
    int *arr = malloc(size * sizeof(int));
    generateRandomArray(arr, size);
    
    // Run the benchmarking
    benchmarkSorting(arr, size);
    
    free(arr);
    return 0;
}