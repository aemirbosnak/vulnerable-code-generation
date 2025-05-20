//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a bucket
struct Bucket {
    int *arr;
    int size;
    int capacity;
};

// Function to create a new bucket
struct Bucket *createBucket(int capacity) {
    struct Bucket *bucket = (struct Bucket *)malloc(sizeof(struct Bucket));
    bucket->arr = (int *)malloc(sizeof(int) * capacity);
    bucket->size = 0;
    bucket->capacity = capacity;
    return bucket;
}

// Function to insert an element into a bucket
void insertIntoBucket(struct Bucket *bucket, int value) {
    if (bucket->size == bucket->capacity) {
        // If the bucket is full, double its capacity
        bucket->arr = (int *)realloc(bucket->arr, sizeof(int) * bucket->capacity * 2);
        bucket->capacity *= 2;
    }
    bucket->arr[bucket->size++] = value;
}

// Function to sort a bucket using insertion sort
void sortBucket(struct Bucket *bucket) {
    int i, j, key;
    for (i = 1; i < bucket->size; i++) {
        key = bucket->arr[i];
        j = i - 1;
        while (j >= 0 && bucket->arr[j] > key) {
            bucket->arr[j + 1] = bucket->arr[j];
            j--;
        }
        bucket->arr[j + 1] = key;
    }
}

// Function to perform bucket sort on an array
void bucketSort(int *arr, int n) {
    // Create an array of buckets
    struct Bucket **buckets = (struct Bucket **)malloc(sizeof(struct Bucket *) * n);
    for (int i = 0; i < n; i++) {
        buckets[i] = createBucket(n);
    }

    // Distribute the elements of the array into the buckets
    for (int i = 0; i < n; i++) {
        // The bucket index is determined by the element's value
        int bucketIndex = arr[i] / n;
        insertIntoBucket(buckets[bucketIndex], arr[i]);
    }

    // Sort each bucket
    for (int i = 0; i < n; i++) {
        sortBucket(buckets[i]);
    }

    // Concatenate the sorted buckets into the original array
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i]->size; j++) {
            arr[index++] = buckets[i]->arr[j];
        }
    }

    // Free the buckets
    for (int i = 0; i < n; i++) {
        free(buckets[i]->arr);
        free(buckets[i]);
    }
    free(buckets);
}

// Function to print an array
void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {5, 3, 1, 7, 4, 1, 2, 8, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);
    printArray(arr, n);

    return 0;
}