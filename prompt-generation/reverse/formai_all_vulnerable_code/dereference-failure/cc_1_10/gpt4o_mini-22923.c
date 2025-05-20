//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define BUCKET_SIZE 10

// Define the structure of a bucket
typedef struct Bucket {
    int *items;
    int count;
} Bucket;

// Function to create a new bucket
Bucket* createBucket() {
    Bucket *bucket = (Bucket *)malloc(sizeof(Bucket));
    bucket->items = (int *)malloc(BUCKET_SIZE * sizeof(int));
    bucket->count = 0;
    return bucket;
}

// Function to free a bucket
void freeBucket(Bucket *bucket) {
    if (bucket) {
        free(bucket->items);
        free(bucket);
    }
}

// Function to add item to the bucket
void addItem(Bucket *bucket, int item) {
    if (bucket->count < BUCKET_SIZE) {
        bucket->items[bucket->count++] = item;
    }
}

// Function to perform insertion sort on the bucket
void bucketSort(Bucket *bucket) {
    for (int i = 1; i < bucket->count; i++) {
        int key = bucket->items[i];
        int j = i - 1;
        while (j >= 0 && bucket->items[j] > key) {
            bucket->items[j + 1] = bucket->items[j];
            j--;
        }
        bucket->items[j + 1] = key;
    }
}

// Main bucket sort function
void bucketSortAlgorithm(int *array, int size) {
    Bucket **buckets = (Bucket **)malloc(sizeof(Bucket *) * size);
    for (int i = 0; i < size; i++) {
        buckets[i] = createBucket();
    }

    // Distribute the input array values into buckets
    for (int i = 0; i < size; i++) {
        int bucketIndex = array[i] / BUCKET_SIZE;
        addItem(buckets[bucketIndex], array[i]);
    }

    // Sort each bucket and gather results
    int index = 0;
    for (int i = 0; i < size; i++) {
        if (buckets[i]->count > 0) {
            bucketSort(buckets[i]);
            for (int j = 0; j < buckets[i]->count; j++) {
                array[index++] = buckets[i]->items[j];
            }
        }
        freeBucket(buckets[i]);
    }

    free(buckets);
}

// Function to print the array
void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Function to generate random numbers for testing
void generateRandomNumbers(int *array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % (size * BUCKET_SIZE); // Random numbers within a defined range
    }
}

int main() {
    int size = MAX_ITEMS; // Define number of elements
    int *array = (int *)malloc(size * sizeof(int));

    // Generate random numbers
    srand(42); // Seed for reproducibility
    generateRandomNumbers(array, size);

    printf("Original array:\n");
    printArray(array, size);

    // Sorting the array
    bucketSortAlgorithm(array, size);

    // Print the sorted array
    printf("Sorted array:\n");
    printArray(array, size);

    free(array);
    return 0;
}