//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_COUNT 10
#define MAX_VALUE 100

// Function to insert an element into a bucket
void insertIntoBucket(int* bucket, int value) {
    bucket[value] = 1;
}

// Function to sort the array using bucket sort
void bucketSort(int* arr, int size) {
    // Create buckets
    int** buckets = (int**)malloc(sizeof(int*) * BUCKET_COUNT);
    for (int i = 0; i < BUCKET_COUNT; i++) {
        buckets[i] = (int*)calloc(MAX_VALUE, sizeof(int));
    }

    // Insert elements into buckets
    for (int i = 0; i < size; i++) {
        insertIntoBucket(buckets[arr[i]], arr[i]);
    }

    // Sort each bucket
    for (int i = 0; i < BUCKET_COUNT; i++) {
        qsort(buckets[i], MAX_VALUE, sizeof(int), NULL);
    }

    // Concatenate buckets into the sorted array
    int index = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        for (int j = 0; j < MAX_VALUE; j++) {
            if (buckets[i][j]) {
                arr[index++] = j;
            }
        }
        free(buckets[i]);
    }
    free(buckets);
}

// Function to print the array
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {4, 2, 1, 3, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    printArray(arr, size);

    bucketSort(arr, size);

    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}