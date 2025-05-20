//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Define the maximum value and the number of buckets
#define MAX_VALUE 100
#define NUM_BUCKETS 10

// Define the number of elements in the input array
#define NUM_ELEMENTS 20

// Function to generate a random array of integers
int* generateRandomArray(int n) {
    int* arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % MAX_VALUE;
    }
    return arr;
}

// Function to print an array
void printArray(int* arr, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Generate a random array of integers
    int* arr = generateRandomArray(NUM_ELEMENTS);

    // Create buckets
    int buckets[NUM_BUCKETS][NUM_ELEMENTS];
    int bucketSizes[NUM_BUCKETS] = {0};

    // Determine the maximum value in the array
    int maxValue = 0;
    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }

    // Determine the divisor for each bucket
    int divisor = (maxValue + 1) / NUM_BUCKETS;

    // Distribute the elements into the buckets
    for (int i = 0; i < NUM_ELEMENTS; ++i) {
        int bucketIndex = arr[i] / divisor;
        buckets[bucketIndex][bucketSizes[bucketIndex]] = arr[i];
        ++bucketSizes[bucketIndex];
    }

    // Sort the elements in each bucket using insertion sort
    for (int i = 0; i < NUM_BUCKETS; ++i) {
        int n = bucketSizes[i];
        for (int j = 1; j < n; ++j) {
            int key = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                --k;
            }
            buckets[i][k + 1] = key;
        }
    }

    // Concatenate the sorted buckets to get the sorted array
    int index = 0;
    for (int i = 0; i < NUM_BUCKETS; ++i) {
        for (int j = 0; j < bucketSizes[i]; ++j) {
            arr[index] = buckets[i][j];
            ++index;
        }
    }

    // Print the sorted array
    printArray(arr, NUM_ELEMENTS);

    // Free the memory allocated for the array
    free(arr);

    return 0;
}