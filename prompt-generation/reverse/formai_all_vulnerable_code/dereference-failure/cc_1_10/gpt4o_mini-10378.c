//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VALUE 1000
#define BUCKET_SIZE 10

// Bucket sort function
void bucketSort(int arr[], int n) {
    // Create buckets
    int bucketCount = (MAX_VALUE + BUCKET_SIZE - 1) / BUCKET_SIZE;
    int **buckets = (int **)malloc(bucketCount * sizeof(int *));
    int *bucketSizes = (int *)calloc(bucketCount, sizeof(int));

    for (int i = 0; i < bucketCount; i++) {
        buckets[i] = (int *)malloc((n + 1) * sizeof(int)); // Allocate enough space
    }

    // Scatter: Place elements into their respective buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / BUCKET_SIZE;
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
    }

    // Sort individual buckets and gather
    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        // If no elements in the bucket, continue
        if (bucketSizes[i] == 0) {
            continue;
        }
        
        // Sort the current bucket
        for (int j = 0; j < bucketSizes[i]; j++) {
            for (int k = j + 1; k < bucketSizes[i]; k++) {
                if (buckets[i][j] > buckets[i][k]) {
                    // Swap
                    int temp = buckets[i][j];
                    buckets[i][j] = buckets[i][k];
                    buckets[i][k] = temp;
                }
            }
        }
        
        // Gather sorted bucket elements back into original array
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }

    // Free allocated memory
    for (int i = 0; i < bucketCount; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketSizes);
}

// Utility function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[] = {78, 34, 56, 89, 23, 45, 67, 12, 90, 33, 67, 45, 76, 55, 88};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}