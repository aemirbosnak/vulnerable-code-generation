//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random array
void generateRandomArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; 
    }
}

// Function to print the array
void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Recursive function to perform Quick Sort
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

void quickSort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Bubble Sort Function
void bubbleSort(int *arr, int n) {
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

// Function to perform Merge
void merge(int *arr, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
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

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}

// Function to implement Merge Sort
void mergeSort(int *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Function to test sorting algorithms
void testSortingAlgorithms(int *arr, int n) {
    int *copyArr;

    // Test Quick Sort
    copyArr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) copyArr[i] = arr[i];
    printf("Original Array:\n");
    printArray(copyArr, n);
    quickSort(copyArr, 0, n - 1);
    printf("Sorted Array using Quick Sort:\n");
    printArray(copyArr, n);
    free(copyArr);

    // Test Bubble Sort
    copyArr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) copyArr[i] = arr[i];
    bubbleSort(copyArr, n);
    printf("Sorted Array using Bubble Sort:\n");
    printArray(copyArr, n);
    free(copyArr);

    // Test Merge Sort
    copyArr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) copyArr[i] = arr[i];
    mergeSort(copyArr, 0, n - 1);
    printf("Sorted Array using Merge Sort:\n");
    printArray(copyArr, n);
    free(copyArr);
}

int main() {
    srand(time(0));
    int n = 20; // Size of the array
    int *arr = (int *)malloc(n * sizeof(int));
    generateRandomArray(arr, n);

    // Test sorting algorithms
    testSortingAlgorithms(arr, n);

    // Free allocated memory
    free(arr);
    return 0;
}