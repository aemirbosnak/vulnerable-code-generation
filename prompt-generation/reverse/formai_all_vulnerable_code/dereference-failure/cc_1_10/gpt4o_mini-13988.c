//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define BUCKET_COUNT 10

// Structure to represent a bucket
typedef struct Bucket {
    int *array;
    int size;
} Bucket;

// Function to create a bucket
Bucket* createBucket(int size) {
    Bucket *bucket = (Bucket *)malloc(sizeof(Bucket));
    bucket->array = (int *)malloc(size * sizeof(int));
    bucket->size = 0;
    return bucket;
}

// Function to free a bucket
void freeBucket(Bucket *bucket) {
    free(bucket->array);
    free(bucket);
}

// Function to perform insertion sort within a bucket
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

// Function to implement bucket sort
void bucketSort(int *array, int n) {
    if (n <= 0) {
        printf("Array size must be greater than zero!\n");
        return;
    }
   
    Bucket **buckets = (Bucket **)malloc(BUCKET_COUNT * sizeof(Bucket *));
    for (int i = 0; i < BUCKET_COUNT; i++) {
        buckets[i] = createBucket(n);
    }

    // Calculate the range of input
    int maxValue = INT_MIN, minValue = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (array[i] > maxValue) maxValue = array[i];
        if (array[i] < minValue) minValue = array[i];
    }

    // Distribute the input array into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (array[i] - minValue) * BUCKET_COUNT / (maxValue - minValue + 1);
        if (bucketIndex == BUCKET_COUNT) bucketIndex--; // Avoid overflow
        buckets[bucketIndex]->array[buckets[bucketIndex]->size++] = array[i];
    }

    // Sort individual buckets and collect results
    int index = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        insertionSort(buckets[i]->array, buckets[i]->size);
        for (int j = 0; j < buckets[i]->size; j++) {
            array[index++] = buckets[i]->array[j];
        }
        freeBucket(buckets[i]);
    }

    free(buckets);
}

// Function to print an array
void printArray(int *array, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

// Main function to test the bucket sort
int main() {
    int arr[] = {29, 25, 3, 49, 9, 37, 21, 43};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original Array: \n");
    printArray(arr, n);
    
    bucketSort(arr, n);
    
    printf("Sorted Array: \n");
    printArray(arr, n);
    
    return 0;
}