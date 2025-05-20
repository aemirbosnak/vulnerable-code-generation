//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform insertion sort on a bucket
void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to perform Bucket Sort
void bucketSort(float arr[], int n) {
    if (n <= 0) return;

    // 1. Create `n` empty buckets
    float **buckets = (float**) malloc(n * sizeof(float*));
    int *bucketSizes = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        buckets[i] = (float*) malloc(n * sizeof(float));
        bucketSizes[i] = 0;
    }

    // 2. Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(n * arr[i]); // Index range 0 to n-1
        if (bucketIndex >= n) bucketIndex = n - 1; 
        buckets[bucketIndex][bucketSizes[bucketIndex]] = arr[i];
        bucketSizes[bucketIndex]++;
    }

    // 3. Sort individual buckets
    for (int i = 0; i < n; i++) {
        if (bucketSizes[i] > 0) {
            insertionSort(buckets[i], bucketSizes[i]);
        }
    }

    // 4. Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }

    // Free dynamically allocated memory
    for (int i = 0; i < n; i++) {
        free(buckets[i]);
    }
    
    free(buckets);
    free(bucketSizes);
}

// Helper function to print the array
void printArray(float arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int n = 10; // Number of elements
    float *arr = (float*) malloc(n * sizeof(float));
    
    // Seed for random number generation
    srand(time(NULL));

    // Generate random numbers between 0.0 and 1.0
    for (int i = 0; i < n; i++) {
        arr[i] = (float)rand() / (float)(RAND_MAX);
    }

    printf("Original array:\n");
    printArray(arr, n);

    // Perform Bucket Sort
    bucketSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    // Free the allocated memory for arr
    free(arr);

    return 0;
}