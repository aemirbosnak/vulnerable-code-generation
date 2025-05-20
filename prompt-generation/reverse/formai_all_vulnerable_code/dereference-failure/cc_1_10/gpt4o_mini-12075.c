//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void generateRandomArray(int arr[], int size);
void printArray(int arr[], int size);
void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void insertionSort(int arr[], int size);
void swap(int *a, int *b);
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

int main() {
    int size = 10;
    int *arr = (int *)malloc(size * sizeof(int));

    // Seed the random number generator
    srand(time(NULL));

    // Generate random array
    generateRandomArray(arr, size);
    
    printf("Original Array:\n");
    printArray(arr, size);
    
    // Bubble Sort
    printf("\nSorting using Bubble Sort:\n");
    bubbleSort(arr, size);
    printArray(arr, size);

    // Regenerate random array
    generateRandomArray(arr, size);
    printf("\nRegenerated Array:\n");
    printArray(arr, size);

    // Selection Sort
    printf("\nSorting using Selection Sort:\n");
    selectionSort(arr, size);
    printArray(arr, size);
    
    // Regenerate random array
    generateRandomArray(arr, size);
    printf("\nRegenerated Array:\n");
    printArray(arr, size);

    // Insertion Sort
    printf("\nSorting using Insertion Sort:\n");
    insertionSort(arr, size);
    printArray(arr, size);

    // Regenerate random array
    generateRandomArray(arr, size);
    printf("\nRegenerated Array:\n");
    printArray(arr, size);

    // Merge Sort
    printf("\nSorting using Merge Sort:\n");
    mergeSort(arr, 0, size - 1);
    printArray(arr, size);
    
    // Regenerate random array
    generateRandomArray(arr, size);
    printf("\nRegenerated Array:\n");
    printArray(arr, size);

    // Quick Sort
    printf("\nSorting using Quick Sort:\n");
    quickSort(arr, 0, size - 1);
    printArray(arr, size);

    // Free allocated memory
    free(arr);
    
    return 0;
}

// Generate an array of random integers
void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Random numbers between 0 and 99
    }
}

// Print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Bubble Sort implementation
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Selection Sort implementation
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}

// Insertion Sort implementation
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Merge function for Merge Sort
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; 
    j = 0; 
    k = l; 
    
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

// Merge Sort implementation
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Quick Sort implementation
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Partition function for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1); 
}