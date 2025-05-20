//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of buckets
#define MAX_BUCKETS 10

// Function to perform bucket sort
void bucketSort(float arr[], int n) {
    // Check if the array is empty or has only one element
    if (n <= 0) return;

    // Create buckets
    float **buckets = malloc(MAX_BUCKETS * sizeof(float *));
    int *bucketCounts = malloc(MAX_BUCKETS * sizeof(int));

    // Initialize the buckets and their counts
    for (int i = 0; i < MAX_BUCKETS; i++) {
        buckets[i] = malloc(n * sizeof(float)); // Allocate memory for each bucket
        bucketCounts[i] = 0; // Initialize the count for each bucket
    }

    // Distribute the elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(arr[i] * MAX_BUCKETS); // Determine bucket index
        if (bucketIndex >= MAX_BUCKETS) bucketIndex = MAX_BUCKETS - 1; // Handle edge case
        buckets[bucketIndex][bucketCounts[bucketIndex]] = arr[i]; // Add element to the bucket
        bucketCounts[bucketIndex]++; // Increment the count for this bucket
    }

    // Sort individual buckets and concatenate results
    float *sortedArr = malloc(n * sizeof(float));
    int idx = 0;

    for (int i = 0; i < MAX_BUCKETS; i++) {
        if (bucketCounts[i] > 0) {
            // Simple insertion sort for the individual bucket
            for (int j = 1; j < bucketCounts[i]; j++) {
                float temp = buckets[i][j];
                int k = j - 1;
                while (k >= 0 && buckets[i][k] > temp) {
                    buckets[i][k + 1] = buckets[i][k]; // Shift elements to the right
                    k--;
                }
                buckets[i][k + 1] = temp; // Insert the element at the correct position
            }
            // Copy sorted bucket to the main sorted array
            for (int j = 0; j < bucketCounts[i]; j++) {
                sortedArr[idx++] = buckets[i][j]; // Concatenate
            }
        }
    }

    // Copy sorted array back to original array
    for (int i = 0; i < n; i++) {
        arr[i] = sortedArr[i]; // Update original array
    }

    // Free allocated memory
    for (int i = 0; i < MAX_BUCKETS; i++) {
        free(buckets[i]); // Free each bucket
    }
    free(buckets);
    free(bucketCounts);
    free(sortedArr);
}

// Function to print an array
void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

// Main function to demonstrate bucket sort
int main() {
    srand(time(NULL)); // Seed random number generation

    // Specify number of elements
    int num_elements = 20;
    float *data = malloc(num_elements * sizeof(float));

    // Generate random float numbers between 0.0 and 1.0
    for (int i = 0; i < num_elements; i++) {
        data[i] = (float)rand() / (float)(RAND_MAX); // Normalized float
    }

    printf("Original array:\n");
    printArray(data, num_elements); // Print original array

    // Sort the array using bucket sort
    bucketSort(data, num_elements);

    printf("Sorted array:\n");
    printArray(data, num_elements); // Print sorted array

    // Free allocated memory
    free(data);
    
    return 0;
}