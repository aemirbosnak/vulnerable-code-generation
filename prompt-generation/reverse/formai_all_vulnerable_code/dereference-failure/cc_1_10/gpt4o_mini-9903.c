//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define BUCKET_COUNT 10 // Define the number of buckets

// Bucket sort implementation in C
void bucketSort(float arr[], int n) {
    // Create buckets
    float **buckets = (float **)malloc(BUCKET_COUNT * sizeof(float *));
    int *bucketSize = (int *)malloc(BUCKET_COUNT * sizeof(int));
    
    for (int i = 0; i < BUCKET_COUNT; i++) {
        buckets[i] = (float *)malloc(MAX * sizeof(float));
        bucketSize[i] = 0;
    }

    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(arr[i] * BUCKET_COUNT); // Get the bucket index
        if (bucketIndex >= BUCKET_COUNT) {
            bucketIndex = BUCKET_COUNT - 1; // Handle the edge case
        }
        buckets[bucketIndex][bucketSize[bucketIndex]++] = arr[i];
    }

    // Sort individual buckets
    for (int i = 0; i < BUCKET_COUNT; i++) {
        // Simple insertion sort for the buckets
        for (int j = 1; j < bucketSize[i]; j++) {
            float key = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }
    }

    // Merge sorted buckets back into arr
    int index = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        for (int j = 0; j < bucketSize[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }

    // Free allocated memory
    for (int i = 0; i < BUCKET_COUNT; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketSize);
}

// Utility function to print the array
void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

// Main function to demonstrate bucket sort
int main() {
    // Visionary demonstration of sorting in a galaxy of floating numbers
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    float *arr = (float *)malloc(n * sizeof(float));
    printf("Enter %d floating point numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }
    
    printf("Unsorted array:\n");
    printArray(arr, n);
    
    // Perform bucket sort
    bucketSort(arr, n);
    
    printf("Sorted array:\n");
    printArray(arr, n);
    
    // Release allocated memory
    free(arr);
    
    return 0;
}