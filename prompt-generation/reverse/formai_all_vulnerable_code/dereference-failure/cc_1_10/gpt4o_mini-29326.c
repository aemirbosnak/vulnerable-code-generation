//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUCKET_COUNT 10 // Number of buckets
#define ARRAY_SIZE 100  // Size of the array

// Function to perform insertion sort on a bucket
void insertionSort(float *bucket, int bucketSize) {
    for (int i = 1; i < bucketSize; i++) {
        float key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

// Function to perform bucket sort
void bucketSort(float *array, int n) {
    // Create buckets and initialize
    float **buckets = (float **)malloc(BUCKET_COUNT * sizeof(float *));
    int *bucketSizes = (int *)malloc(BUCKET_COUNT * sizeof(int));
    
    for (int i = 0; i < BUCKET_COUNT; i++) {
        buckets[i] = (float *)malloc(n * sizeof(float));
        bucketSizes[i] = 0;
    }

    // Distribute input array elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(BUCKET_COUNT * array[i]);
        // Ensure the index is within the limits
        if (bucketIndex >= BUCKET_COUNT) {
            bucketIndex = BUCKET_COUNT - 1;
        }
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = array[i];
    }

    // Sort each bucket and merge them back into the original array
    int index = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        if (bucketSizes[i] > 0) {
            insertionSort(buckets[i], bucketSizes[i]);
            for (int j = 0; j < bucketSizes[i]; j++) {
                array[index++] = buckets[i][j];
            }
        }
    }

    // Clean up memory
    for (int i = 0; i < BUCKET_COUNT; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketSizes);
}

// Function to generate random floating-point numbers
void generateRandomArray(float *array, int n) {
    for (int i = 0; i < n; i++) {
        array[i] = (float)rand() / RAND_MAX; // Generate numbers in range [0.0, 1.0)
    }
}

// Function to print the array
void printArray(float *array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", array[i]);
    }
    printf("\n");
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create an array to hold the random numbers
    float *array = (float *)malloc(ARRAY_SIZE * sizeof(float));
    
    // Generate random numbers
    generateRandomArray(array, ARRAY_SIZE);

    printf("Original array:\n");
    printArray(array, ARRAY_SIZE);

    // Sort the array using bucket sort
    bucketSort(array, ARRAY_SIZE);

    printf("Sorted array:\n");
    printArray(array, ARRAY_SIZE);

    // Clean up memory
    free(array);

    return 0;
}