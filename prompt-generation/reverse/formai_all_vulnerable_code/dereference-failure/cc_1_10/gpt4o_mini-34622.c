//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEFAULT_BUCKETS 10
#define MAX_RANDOM_VALUE 100

// Function prototypes
void bucketSort(float arr[], int n, int numBuckets);
void printArray(float arr[], int n);
float* createBuckets(int numBuckets);
void sortBucket(float bucket[], int size);
void distributeToBuckets(float arr[], int n, float buckets[][MAX_RANDOM_VALUE], int size[], int numBuckets);
void collectFromBuckets(float arr[], float buckets[][MAX_RANDOM_VALUE], int size[], int numBuckets);

int main(int argc, char *argv[]) {
    int numElements = 20;
    int numBuckets = DEFAULT_BUCKETS;

    // Read command line arguments for configuration
    if (argc > 1) {
        numElements = atoi(argv[1]);
    }
    if (argc > 2) {
        numBuckets = atoi(argv[2]);
    }

    // Dynamically allocate memory for the array
    float *arr = (float *)malloc(numElements * sizeof(float));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    // Seed for random number generation
    srand(time(0));

    // Fill array with random floating-point numbers
    for (int i = 0; i < numElements; i++) {
        arr[i] = ((float) rand() / RAND_MAX) * MAX_RANDOM_VALUE;
    }

    printf("Original array:\n");
    printArray(arr, numElements);

    // Sort the array using Bucket Sort
    bucketSort(arr, numElements, numBuckets);

    printf("Sorted array:\n");
    printArray(arr, numElements);

    // Free allocated memory
    free(arr);
    
    return 0;
}

// Bucket Sort implementation
void bucketSort(float arr[], int n, int numBuckets) {
    // Create buckets
    float buckets[numBuckets][MAX_RANDOM_VALUE];
    int size[numBuckets];

    for (int i = 0; i < numBuckets; i++) {
        size[i] = 0;
    }

    // Distribute elements into buckets
    distributeToBuckets(arr, n, buckets, size, numBuckets);

    // Sort individual buckets
    for (int i = 0; i < numBuckets; i++) {
        sortBucket(buckets[i], size[i]);
    }

    // Collect sorted elements from the buckets
    collectFromBuckets(arr, buckets, size, numBuckets);
}

// Distribute elements into buckets
void distributeToBuckets(float arr[], int n, float buckets[][MAX_RANDOM_VALUE], int size[], int numBuckets) {
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(arr[i] * numBuckets / MAX_RANDOM_VALUE);
        if (bucketIndex >= numBuckets) {
            bucketIndex = numBuckets - 1;
        }
        buckets[bucketIndex][size[bucketIndex]] = arr[i];
        size[bucketIndex]++;
    }
}

// Sort individual bucket using insertion sort
void sortBucket(float bucket[], int size) {
    for (int i = 1; i < size; i++) {
        float key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

// Collect sorted elements from the buckets
void collectFromBuckets(float arr[], float buckets[][MAX_RANDOM_VALUE], int size[], int numBuckets) {
    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        for (int j = 0; j < size[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

// Print the elements of an array
void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");
}