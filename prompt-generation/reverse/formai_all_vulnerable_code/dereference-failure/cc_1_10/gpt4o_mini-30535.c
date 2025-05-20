//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10 // Size of each bucket
#define NUM_BUCKETS 10 // Number of buckets

// Function to perform insertion sort on a bucket
void insertionSort(int* bucket, int n) {
    for (int i = 1; i < n; i++) {
        int key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    // Create an array of buckets
    int** buckets = (int**)malloc(NUM_BUCKETS * sizeof(int*));
    int* bucketSizes = (int*)malloc(NUM_BUCKETS * sizeof(int));

    // Initialize buckets and their sizes
    for (int i = 0; i < NUM_BUCKETS; i++) {
        buckets[i] = (int*)malloc(BUCKET_SIZE * sizeof(int));
        bucketSizes[i] = 0;
    }

    // Distribute input array values into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / (BUCKET_SIZE + 1);
        if (bucketIndex >= NUM_BUCKETS) {
            bucketIndex = NUM_BUCKETS - 1; // Put in last bucket if it exceeds limit
        }
        if (bucketSizes[bucketIndex] < BUCKET_SIZE) {
            buckets[bucketIndex][bucketSizes[bucketIndex]] = arr[i];
            bucketSizes[bucketIndex]++;
        }
    }

    // Sort each bucket and collect sorted elements
    int index = 0;
    for (int i = 0; i < NUM_BUCKETS; i++) {
        if (bucketSizes[i] > 0) {
            insertionSort(buckets[i], bucketSizes[i]);
            for (int j = 0; j < bucketSizes[i]; j++) {
                arr[index++] = buckets[i][j];
            }
        }
    }

    // Free the allocated memory for buckets
    for (int i = 0; i < NUM_BUCKETS; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketSizes);
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Driver program
int main() {
    int arr[] = {29, 25, 3, 49, 9, 37, 21, 43};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}