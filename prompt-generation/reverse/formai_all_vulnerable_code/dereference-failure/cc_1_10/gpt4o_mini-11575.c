//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10  // Define the number of buckets

// Function to perform insertion sort on an array
void insertionSort(float arr[], int n) {
    int i, j;
    float key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to perform bucket sort
void bucketSort(float arr[], int n) {
    // Create n empty buckets
    float **buckets = (float **)malloc(BUCKET_SIZE * sizeof(float *));
    int *bucketSizes = (int *)malloc(BUCKET_SIZE * sizeof(int));

    for (int i = 0; i < BUCKET_SIZE; i++) {
        buckets[i] = (float *)malloc(n * sizeof(float));  // Allocate memory for each bucket
        bucketSizes[i] = 0;  // Initialize bucket sizes to 0
    }

    // Put array elements into different buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(BUCKET_SIZE * arr[i]); // Calculate bucket index
        if (bucketIndex >= BUCKET_SIZE) {
            bucketIndex = BUCKET_SIZE - 1;  // Place in last bucket if overflow
        }
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];  // Add to bucket and increase size
    }

    // Sort individual buckets and concatenate
    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        // Sort bucket
        if (bucketSizes[i] > 0) {
            insertionSort(buckets[i], bucketSizes[i]);
            // Concatenate sorted bucket into original array
            for (int j = 0; j < bucketSizes[i]; j++) {
                arr[index++] = buckets[i][j];
            }
        }
    }

    // Free allocated memory for buckets
    for (int i = 0; i < BUCKET_SIZE; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketSizes);
}

// Function to print an array
void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

// Main function to test the bucket sort
int main() {
    float arr[] = {0.897, 0.565, 0.656, 0.123, 0.665, 0.343, 0.456, 0.789, 0.212};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}