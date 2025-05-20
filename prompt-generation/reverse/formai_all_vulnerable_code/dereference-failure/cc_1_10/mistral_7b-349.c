//MISTRAL-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define MAX_ELEMENTS 1000
#define VALLEY_WIDTH 50
#define MIN_ELEM 0
#define MAX_ELEM INT_MAX

typedef struct {
    int top;
    int capacity;
    int *array;
} Bucket;

void initializeBucket(Bucket *bucket, int capacity) {
    bucket->capacity = capacity;
    bucket->top = -1;
    bucket->array = (int *)calloc(capacity, sizeof(int));
}

bool isFull(Bucket *bucket) {
    return bucket->top == bucket->capacity - 1;
}

void pushBucket(Bucket *bucket, int element) {
    if (isFull(bucket)) {
        fprintf(stderr, "Bucket is full.\n");
        exit(EXIT_FAILURE);
    }
    bucket->array[++bucket->top] = element;
}

int popBucket(Bucket *bucket) {
    if (bucket->top < 0) {
        fprintf(stderr, "Bucket is empty.\n");
        exit(EXIT_FAILURE);
    }
    return bucket->array[bucket->top--];
}

int getBucketIndex(int element, int numberOfBuckets) {
    return (element - MIN_ELEM) % numberOfBuckets;
}

void bucketSort(int array[], int size, int numberOfBuckets) {
    int i;
    Bucket *pools = (Bucket *)calloc(numberOfBuckets, sizeof(Bucket));

    for (i = 0; i < numberOfBuckets; i++) {
        initializeBucket(&pools[i], VALLEY_WIDTH);
    }

    for (i = 0; i < size; i++) {
        int bucketIndex = getBucketIndex(array[i], numberOfBuckets);
        pushBucket(&pools[bucketIndex], array[i]);
    }

    int index = 0;
    int j = 0;
    for (i = 0; i < numberOfBuckets; i++) {
        while (!isFull(&pools[i])) {
            int pebble = popBucket(&pools[i]);
            array[j++] = pebble;
        }
    }

    for (i = 0; i < numberOfBuckets; i++) {
        free(pools[i].array);
    }
    free(pools);
}

void printArray(int array[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[] = { 12, 11, 13, 5, 6, 7 };
    int size = sizeof(array) / sizeof(array[0]);

    int numberOfBuckets = 3;

    printf("Before Sorting:\n");
    printArray(array, size);

    bucketSort(array, size, numberOfBuckets);

    printf("After Sorting:\n");
    printArray(array, size);

    return 0;
}