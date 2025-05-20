//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUCKETS 10
#define MAX_ARRAY_SIZE 100

// Fun fact: This is not an actual use for buckets, but we all could use more water!

// A bucket structure that can hold integers
typedef struct Bucket {
    int *array;
    int count;
} Bucket;

// Function to create a bucket
Bucket* createBucket() {
    Bucket* bucket = malloc(sizeof(Bucket));
    bucket->array = malloc(MAX_ARRAY_SIZE * sizeof(int));
    bucket->count = 0;
    return bucket;
}

// Function to clean up the bucket
void destroyBucket(Bucket* bucket) {
    free(bucket->array);
    free(bucket);
}

// Fun function to print out bucket contents
void printBucket(Bucket* bucket, int bucketIndex) {
    if (bucket->count == 0) {
        printf("Bucket %d is empty... kinda like my social life!\n", bucketIndex);
    } else {
        printf("Bucket %d contains: ", bucketIndex);
        for (int i = 0; i < bucket->count; i++) {
            printf("%d ", bucket->array[i]);
        }
        printf("\n");
    }
}

// The magical sorting function
void bucketSort(int *arr, int n) {
    printf("Brace yourselves, sorting is about to happen!\n");

    // Create buckets
    Bucket* buckets[MAX_BUCKETS];
    for (int i = 0; i < MAX_BUCKETS; i++) {
        buckets[i] = createBucket();
    }

    // Distributing the values across buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / (MAX_ARRAY_SIZE / MAX_BUCKETS);
        if (bucketIndex >= MAX_BUCKETS) {
            bucketIndex = MAX_BUCKETS - 1;
        }
        buckets[bucketIndex]->array[buckets[bucketIndex]->count++] = arr[i];
    }

    // Now, let's sort each bucket! How riveting!
    for (int i = 0; i < MAX_BUCKETS; i++) {
        if (buckets[i]->count > 0) {
            printf("Sorting bucket %d...\n", i);
            qsort(buckets[i]->array, buckets[i]->count, sizeof(int), (int (*)(const void*, const void*)) strcmp);
        }
    }

    // Collecting the sorted buckets back
    int index = 0;
    for (int i = 0; i < MAX_BUCKETS; i++) {
        for (int j = 0; j < buckets[i]->count; j++) {
            arr[index++] = buckets[i]->array[j];
        }
        printBucket(buckets[i], i); // Just like show and tell!
    }

    // Clean up the buckets, don't leave your mess for others!
    for (int i = 0; i < MAX_BUCKETS; i++) {
        destroyBucket(buckets[i]);
    }
}

// Let's get our numbers together for a friendships
void fillArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Random numbers between 0 and 99
    }
}

// Let's print the numbers because why not
void printArray(int *arr, int size) {
    printf("The unsorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function, the captain of this ship
int main() {
    int arr[MAX_ARRAY_SIZE];
    int size = rand() % MAX_ARRAY_SIZE + 1; // Length of array up to MAX_ARRAY_SIZE

    fillArray(arr, size);
    printArray(arr, size);
    
    bucketSort(arr, size);

    printf("The sorted array is:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}