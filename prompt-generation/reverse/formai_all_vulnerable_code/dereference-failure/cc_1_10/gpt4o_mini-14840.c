//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_COUNT 10 // Number of buckets

// Function to perform bucket sort
void bucketSort(float arr[], int n) {
    // Create an array of buckets
    float **buckets = malloc(BUCKET_COUNT * sizeof(float *));
    int *bucketSizes = malloc(BUCKET_COUNT * sizeof(int));

    // Initialize the buckets and their sizes
    for (int i = 0; i < BUCKET_COUNT; i++) {
        buckets[i] = malloc(n * sizeof(float)); // each bucket can hold up to n elements
        bucketSizes[i] = 0; // start with empty buckets
    }

    // Place each element in a bucket
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(BUCKET_COUNT * arr[i]); // Determine which bucket to put the element into
        if (bucketIndex >= BUCKET_COUNT) {
            bucketIndex = BUCKET_COUNT - 1; // Handle overflow index
        }
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i]; // Add the element to the appropriate bucket
    }

    // Sort each bucket and reassemble the array
    int index = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        // Sort individual buckets (using insertion sort for simplicity)
        for (int j = 1; j < bucketSizes[i]; j++) {
            float key = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }
        // Collect sorted elements from each bucket into the array
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }

    // Free memory
    for (int i = 0; i < BUCKET_COUNT; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketSizes);
}

// Function to print the array
void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");
}

// Main function to test the bucketSort function
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    float *arr = malloc(n * sizeof(float));
    printf("Enter %d floating-point numbers (between 0 and 1):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    printf("Original array:\n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    free(arr);
    return 0;
}