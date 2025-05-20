//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define BUCKETS 10

// Structure to represent a bucket
typedef struct Bucket {
    int *array;
    int size;
    int capacity;
} Bucket;

// Function to create a new bucket
Bucket *createBucket(int capacity) {
    Bucket *bucket = (Bucket *)malloc(sizeof(Bucket));
    bucket->array = (int *)malloc(sizeof(int) * capacity);
    bucket->size = 0;
    bucket->capacity = capacity;
    return bucket;
}

// Function to insert an element into a bucket
void insertIntoBucket(Bucket *bucket, int element) {
    if (bucket->size == bucket->capacity) {
        // Double the capacity of the bucket
        bucket->capacity *= 2;
        bucket->array = (int *)realloc(bucket->array, sizeof(int) * bucket->capacity);
    }
    bucket->array[bucket->size++] = element;
}

// Function to sort a bucket
void sortBucket(Bucket *bucket) {
    for (int i = 0; i < bucket->size - 1; i++) {
        for (int j = i + 1; j < bucket->size; j++) {
            if (bucket->array[i] > bucket->array[j]) {
                int temp = bucket->array[i];
                bucket->array[i] = bucket->array[j];
                bucket->array[j] = temp;
            }
        }
    }
}

// Function to perform bucket sort on an array
void bucketSort(int *array, int size) {
    // Create an array of buckets
    Bucket *buckets[BUCKETS];
    for (int i = 0; i < BUCKETS; i++) {
        buckets[i] = createBucket(size / BUCKETS);
    }

    // Distribute elements into buckets
    for (int i = 0; i < size; i++) {
        int bucketIndex = array[i] / BUCKETS;
        insertIntoBucket(buckets[bucketIndex], array[i]);
    }

    // Sort each bucket
    for (int i = 0; i < BUCKETS; i++) {
        sortBucket(buckets[i]);
    }

    // Concatenate the sorted buckets into the original array
    int index = 0;
    for (int i = 0; i < BUCKETS; i++) {
        for (int j = 0; j < buckets[i]->size; j++) {
            array[index++] = buckets[i]->array[j];
        }
    }

    // Free the memory allocated for the buckets
    for (int i = 0; i < BUCKETS; i++) {
        free(buckets[i]->array);
        free(buckets[i]);
    }
}

// Function to print an array
void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    // Get the input array
    int array[] = {4, 2, 1, 5, 3, 7, 6, 9, 8};
    int size = sizeof(array) / sizeof(array[0]);

    // Sort the array using bucket sort
    bucketSort(array, size);

    // Print the sorted array
    printArray(array, size);

    return 0;
}