//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform insertion sort on a bucket
void insertionSort(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to perform bucket sort
void bucketSort(int* arr, int n) {
    // Step 1: Create N empty buckets
    int bucketCount = n; // In this case, we create n buckets
    int** buckets = (int**)malloc(bucketCount * sizeof(int*));
    int* bucketSizes = (int*)malloc(bucketCount * sizeof(int));
    
    for (int i = 0; i < bucketCount; i++) {
        buckets[i] = (int*)malloc(n * sizeof(int));
        bucketSizes[i] = 0; // Initialize sizes of all buckets to 0
    }

    // Step 2: Insert elements into buckets
    for (int i = 0; i < n; i++) {
        int index = (arr[i] * bucketCount) / (RAND_MAX + 1); // Hashing function to choose bucket
        buckets[index][bucketSizes[index]] = arr[i];
        bucketSizes[index]++;
    }

    // Step 3: Sort each bucket and concatenate the results
    int idx = 0;
    for (int i = 0; i < bucketCount; i++) {
        if (bucketSizes[i] > 0) {
            insertionSort(buckets[i], bucketSizes[i]);
            for (int j = 0; j < bucketSizes[i]; j++) {
                arr[idx++] = buckets[i][j];
            }
        }
    }

    // Step 4: Free allocated memory
    for (int i = 0; i < bucketCount; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketSizes);
}

// Function to generate random integers
void generateRandomIntegers(int* arr, int n, int max) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % max; // Generate random integers in range [0, max)
    }
}

// Function to print the array
void printArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to demonstrate the bucket sort algorithm
int main() {
    int n = 20; // Size of the array
    int* arr = (int*)malloc(n * sizeof(int));
    
    // Generate random integers
    generateRandomIntegers(arr, n, 100);
    
    printf("Original array:\n");
    printArray(arr, n);
    
    // Perform bucket sort
    bucketSort(arr, n);
    
    printf("Sorted array:\n");
    printArray(arr, n);
    
    // Free allocated memory
    free(arr);
    
    return 0;
}