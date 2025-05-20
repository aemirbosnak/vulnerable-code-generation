//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 100
#define MAX_BUCKETS 10

// Function to initialize buckets and assign them appropriately
void initializeBuckets(int ***buckets, int *bucketSizes, int bucketCount) {
    *buckets = (int **)malloc(bucketCount * sizeof(int *));
    for (int i = 0; i < bucketCount; i++) {
        *buckets[i] = (int *)malloc(MAX_NUMBERS * sizeof(int)); // allocate max size for simplicity
        bucketSizes[i] = 0; // initialize sizes of each bucket
    }
}

// Function to insert elements into corresponding bucket
void insertIntoBucket(int num, int **buckets, int *bucketSizes, int bucketCount) {
    int index = num * bucketCount / 100; // Simple scaling to map to buckets
    if (index >= bucketCount) index = bucketCount - 1; // Ensure it fits within bounds
    buckets[index][bucketSizes[index]] = num;
    bucketSizes[index]++;
}

// Function to sort individual buckets using Insertion Sort
void insertionSort(int *array, int size) {
    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

// Function to concatenate sorted buckets into a single array
void concatenateBuckets(int **buckets, int *bucketSizes, int bucketCount, int *result) {
    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            result[index++] = buckets[i][j];
        }
    }
}

// The Bucket Sort function
void bucketSort(int *array, int size) {
    int bucketCount = MAX_BUCKETS; 
    int **buckets;
    int *bucketSizes = (int *)malloc(bucketCount * sizeof(int));

    initializeBuckets(&buckets, bucketSizes, bucketCount);

    for (int i = 0; i < size; i++) {
        insertIntoBucket(array[i], buckets, bucketSizes, bucketCount);
    }

    for (int i = 0; i < bucketCount; i++) {
        if (bucketSizes[i] > 0) {
            insertionSort(buckets[i], bucketSizes[i]);
        }
    }

    concatenateBuckets(buckets, bucketSizes, bucketCount, array);

    // Free allocated memory
    for (int i = 0; i < bucketCount; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketSizes);
}

// Function to print an array
void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Main function to demonstrate the bucket sort
int main() {
    int numbers[MAX_NUMBERS];
    int size;

    // Surprising input: generate random numbers!
    printf("Enter the number of elements (max %d): ", MAX_NUMBERS);
    scanf("%d", &size);
    
    if (size > MAX_NUMBERS) {
        printf("Size exceeds maximum limit!\n");
        return 1;
    }

    printf("Generating %d random numbers between 0 and 99...\n", size);
    for (int i = 0; i < size; i++) {
        numbers[i] = rand() % 100;
    }

    printf("Unsorted array: ");
    printArray(numbers, size);
    
    // Sort the random numbers
    bucketSort(numbers, size);
    
    printf("Surprisingly sorted array: ");
    printArray(numbers, size);
    
    return 0;
}