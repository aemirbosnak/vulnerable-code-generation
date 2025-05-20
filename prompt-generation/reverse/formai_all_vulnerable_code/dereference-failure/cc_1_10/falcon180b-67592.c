//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MAX_BUCKETS 1000000

typedef struct {
    int *data;
    int size;
} Bucket;

void initBuckets(Bucket *buckets, int numBuckets) {
    for (int i = 0; i < numBuckets; i++) {
        buckets[i].data = (int *) malloc(MAX_SIZE * sizeof(int));
        buckets[i].size = 0;
    }
}

void freeBuckets(Bucket *buckets, int numBuckets) {
    for (int i = 0; i < numBuckets; i++) {
        free(buckets[i].data);
    }
}

void bucketSort(int *arr, int size, Bucket *buckets, int numBuckets) {
    for (int i = 0; i < size; i++) {
        int bucketIndex = arr[i] % numBuckets;
        buckets[bucketIndex].data[buckets[bucketIndex].size++] = arr[i];
    }

    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        for (int j = 0; j < buckets[i].size; j++) {
            arr[index++] = buckets[i].data[j];
        }
    }
}

void generateRandomArray(int *arr, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_SIZE;
    }
}

int main() {
    int size = MAX_SIZE;
    int numBuckets = 10;

    int *arr = (int *) malloc(size * sizeof(int));
    Bucket *buckets = (Bucket *) malloc(numBuckets * sizeof(Bucket));

    initBuckets(buckets, numBuckets);

    generateRandomArray(arr, size);

    printf("Before Sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, size, buckets, numBuckets);

    printf("After Sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    freeBuckets(buckets, numBuckets);
    free(arr);

    return 0;
}