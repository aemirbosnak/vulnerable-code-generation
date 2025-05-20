//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Bubble Sort Algorithm
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Quick Sort Algorithm
void quickSort(int arr[], int low, int high) {
    if (low < high) {
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
        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to fill an array with random numbers
void fillArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000; // Random numbers from 0 to 999
    }
}

int main() {
    srand(time(0)); // Seed for random number generation

    // Size of the array
    int size = 1000;
    int *arr1 = malloc(size * sizeof(int));
    int *arr2 = malloc(size * sizeof(int));
    
    // Fill arrays with random numbers
    fillArray(arr1, size);
    for (int i = 0; i < size; i++) {
        arr2[i] = arr1[i]; // Copy for quicksort
    }

    // Start benchmarking Bubble Sort
    clock_t start = clock();
    bubbleSort(arr1, size);
    clock_t end = clock();
    double time_taken_bubble = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by Bubble Sort: %f seconds\n", time_taken_bubble);

    // Start benchmarking Quick Sort
    start = clock();
    quickSort(arr2, 0, size - 1);
    end = clock();
    double time_taken_quick = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by Quick Sort: %f seconds\n", time_taken_quick);

    // Optional: Print sorted arrays
    // printf("Sorted array (Bubble Sort): \n");
    // printArray(arr1, size);
    // printf("Sorted array (Quick Sort): \n");
    // printArray(arr2, size);

    // Free allocated memory
    free(arr1);
    free(arr2);

    return 0;
}