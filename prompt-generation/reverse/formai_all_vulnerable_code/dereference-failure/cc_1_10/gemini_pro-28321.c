//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define bucket structure
typedef struct Bucket {
    int start;
    int end;
    int *array;
    int size;
} Bucket;

// Create a bucket
Bucket *createBucket(int start, int end) {
    Bucket *bucket = malloc(sizeof(Bucket));
    bucket->start = start;
    bucket->end = end;
    bucket->array = malloc(sizeof(int) * (end - start + 1));
    bucket->size = 0;
    return bucket;
}

// Insert an element into a bucket
void insertIntoBucket(Bucket *bucket, int value) {
    if (bucket->size >= (bucket->end - bucket->start + 1)) {
        // Reallocate the array if necessary
        bucket->array = realloc(bucket->array, sizeof(int) * (bucket->end - bucket->start + 1) * 2);
    }
    bucket->array[bucket->size++] = value;
}

// Merge two buckets
Bucket *mergeBuckets(Bucket *bucket1, Bucket *bucket2) {
    if (bucket1 == NULL) {
        return bucket2;
    }
    if (bucket2 == NULL) {
        return bucket1;
    }

    // Create a new bucket
    Bucket *mergedBucket = createBucket(bucket1->start, bucket2->end);

    // Copy the elements from the first bucket
    for (int i = 0; i < bucket1->size; i++) {
        insertIntoBucket(mergedBucket, bucket1->array[i]);
    }

    // Copy the elements from the second bucket
    for (int i = 0; i < bucket2->size; i++) {
        insertIntoBucket(mergedBucket, bucket2->array[i]);
    }

    // Free the memory of the two original buckets
    free(bucket1->array);
    free(bucket1);
    free(bucket2->array);
    free(bucket2);

    return mergedBucket;
}

// Sort an array using bucket sort
int *bucketSort(int *array, int size) {
    // Create buckets for each range of values
    int min = array[0];
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
        if (array[i] > max) {
            max = array[i];
        }
    }

    int numBuckets = 10;
    Bucket **buckets = malloc(sizeof(Bucket *) * numBuckets);
    for (int i = 0; i < numBuckets; i++) {
        int start = min + (max - min) * i / numBuckets;
        int end = min + (max - min) * (i + 1) / numBuckets - 1;
        buckets[i] = createBucket(start, end);
    }

    // Insert each element into a bucket
    for (int i = 0; i < size; i++) {
        int bucketIndex = (array[i] - min) * numBuckets / (max - min);
        insertIntoBucket(buckets[bucketIndex], array[i]);
    }

    // Sort each bucket
    for (int i = 0; i < numBuckets; i++) {
        buckets[i] = bucketSort(buckets[i]->array, buckets[i]->size);
    }

    // Merge the buckets
    Bucket *mergedBucket = NULL;
    for (int i = 0; i < numBuckets; i++) {
        mergedBucket = mergeBuckets(mergedBucket, buckets[i]);
    }

    // Free the memory of the buckets
    for (int i = 0; i < numBuckets; i++) {
        free(buckets[i]);
    }
    free(buckets);

    // Return the sorted array
    return mergedBucket->array;
}

// Print an array
void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    // Generate a random array
    int size = 100;
    int *array = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 1000;
    }

    // Sort the array using bucket sort
    int *sortedArray = bucketSort(array, size);

    // Print the original array
    printf("Original array:\n");
    printArray(array, size);

    // Print the sorted array
    printf("Sorted array:\n");
    printArray(sortedArray, size);

    // Free the memory of the arrays
    free(array);
    free(sortedArray);

    return 0;
}