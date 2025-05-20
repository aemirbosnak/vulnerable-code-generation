//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct bucket {
    int start;
    int end;
    int count;
    int *array;
} bucket;

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

void bucketSort(int *array, int size, int numBuckets) {
    // Create buckets
    bucket *buckets = malloc(sizeof(bucket) * numBuckets);
    for (int i = 0; i < numBuckets; i++) {
        buckets[i].start = i * MAX_SIZE / numBuckets;
        buckets[i].end = (i + 1) * MAX_SIZE / numBuckets - 1;
        buckets[i].count = 0;
        buckets[i].array = malloc(sizeof(int) * MAX_SIZE / numBuckets);
    }

    // Distribute elements into buckets
    for (int i = 0; i < size; i++) {
        int bucketIndex = (array[i] * numBuckets) / MAX_SIZE;
        buckets[bucketIndex].array[buckets[bucketIndex].count++] = array[i];
    }

    // Sort elements in each bucket
    for (int i = 0; i < numBuckets; i++) {
        insertionSort(buckets[i].array, buckets[i].count);
    }

    // Merge buckets back into the original array
    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        for (int j = 0; j < buckets[i].count; j++) {
            array[index++] = buckets[i].array[j];
        }

        free(buckets[i].array);
    }

    free(buckets);
}

int main() {
    int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int size = sizeof(array) / sizeof(array[0]);

    bucketSort(array, size, 10);

    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");

    return 0;
}