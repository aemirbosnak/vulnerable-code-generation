//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function prototypes
void bubbleSort(int arr[], int n);
void mergeSort(int arr[], int l, int r);
void quickSort(int arr[], int low, int high);
void generateRandomArray(int arr[], int n);
void printArray(int arr[], int n);
void measureTime(void (*sortFunc)(int[], int), int arr[], int n, const char *sortName);

int main() {
    const int SIZE = 10000; // Size of the array for sorting
    int *array1 = malloc(SIZE * sizeof(int)); // For bubble sort
    int *array2 = malloc(SIZE * sizeof(int)); // For merge sort
    int *array3 = malloc(SIZE * sizeof(int)); // For quick sort

    if (array1 == NULL || array2 == NULL || array3 == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Generate a random array
    generateRandomArray(array1, SIZE);
    memcpy(array2, array1, SIZE * sizeof(int));
    memcpy(array3, array1, SIZE * sizeof(int));

    // Measure sorting times for different algorithms
    measureTime(bubbleSort, array1, SIZE, "Bubble Sort");
    measureTime(mergeSort, array2, SIZE, "Merge Sort");
    measureTime(quickSort, array3, SIZE, "Quick Sort");

    // Free allocated memory
    free(array1);
    free(array2);
    free(array3);
    
    return 0;
}

// Generate a random array of specified size
void generateRandomArray(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000; // Random numbers between 0 and 9999
    }
}

// Measure and display the time taken by sorting function
void measureTime(void (*sortFunc)(int[], int), int arr[], int n, const char *sortName) {
    clock_t start, end;
    start = clock();
    
    sortFunc(arr, n); // Call the sorting function
    
    end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    
    printf("%s took %f seconds to sort %d elements.\n", sortName, time_spent, n);
}

// Bubble Sort algorithm
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Merge Sort algorithm
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; // Initial index of first sub-array
    j = 0; // Initial index of second sub-array
    k = l; // Initial index of merged sub-array

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

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Quick Sort algorithm
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivot
    int i = (low - 1); // Smallest index

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
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