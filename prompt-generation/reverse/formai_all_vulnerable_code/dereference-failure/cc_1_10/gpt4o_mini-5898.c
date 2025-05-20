//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
void bucketSort(float array[], int n);
void insertionSort(float bucket[], int m);
int getBucketIndex(float number, int numBuckets, float maxValue);

// Main Function
int main(void) {
    int n, i;
    float *array;

    // Step 1: Input the size of the array and allocate memory
    printf("Welcome to the Bucket Sort Program!\n");
    printf("Enter the number of elements to sort: ");
    scanf("%d", &n);

    array = (float *) malloc(n * sizeof(float));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    // Step 2: Initialize the array with random floating-point numbers
    printf("Generating %d random float numbers between 0 and 1:\n", n);
    for (i = 0; i < n; i++) {
        array[i] = (float) rand() / (float) RAND_MAX;
        printf("%0.4f ", array[i]);
    }
    printf("\n");

    // Step 3: Perform Bucket Sort
    bucketSort(array, n);

    // Step 4: Output the sorted array
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%0.4f ", array[i]);
    }
    printf("\n");

    // Cleanup
    free(array);
    return EXIT_SUCCESS;
}

// Function to perform Bucket Sort
void bucketSort(float array[], int n) {
    // Step 1: Create buckets
    int numBuckets = 10;
    float **buckets = (float **) malloc(numBuckets * sizeof(float *));
    int *bucketSizes = (int *) malloc(numBuckets * sizeof(int));
    float maxValue = 1.0; // Since we are generating numbers in range [0, 1]

    for (int i = 0; i < numBuckets; i++) {
        buckets[i] = (float *) malloc(n * sizeof(float));
        bucketSizes[i] = 0;
    }

    // Step 2: Distribute input elements into buckets
    for (int i = 0; i < n; i++) {
        int index = getBucketIndex(array[i], numBuckets, maxValue);
        buckets[index][bucketSizes[index]++] = array[i];
    }

    // Step 3: Sort each bucket and concatenate results
    int outputIndex = 0;
    for (int i = 0; i < numBuckets; i++) {
        if (bucketSizes[i] > 0) {
            insertionSort(buckets[i], bucketSizes[i]);
            for (int j = 0; j < bucketSizes[i]; j++) {
                array[outputIndex++] = buckets[i][j];
            }
        }
        free(buckets[i]); // Cleanup for bucket
    }

    // Cleanup
    free(buckets);
    free(bucketSizes);
}

// Function to perform Insertion Sort on a bucket
void insertionSort(float bucket[], int m) {
    for (int i = 1; i < m; i++) {
        float key = bucket[i];
        int j = i - 1;

        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

// Function to get the index of the bucket
int getBucketIndex(float number, int numBuckets, float maxValue) {
    return (int)(number * numBuckets);
}