//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000
#define MAX_BUCKETS 1000

typedef struct {
    int *arr;
    int size;
} Bucket;

void createBuckets(Bucket *buckets, int numBuckets) {
    for (int i = 0; i < numBuckets; i++) {
        buckets[i].arr = (int *) malloc(MAX_SIZE * sizeof(int));
        buckets[i].size = 0;
    }
}

void deleteBuckets(Bucket *buckets, int numBuckets) {
    for (int i = 0; i < numBuckets; i++) {
        free(buckets[i].arr);
    }
}

void bucketSort(int *arr, int size, Bucket *buckets, int numBuckets) {
    for (int i = 0; i < size; i++) {
        int bucketIndex = arr[i] / (MAX_SIZE / numBuckets);
        buckets[bucketIndex].arr[buckets[bucketIndex].size++] = arr[i];
    }

    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        for (int j = 0; j < buckets[i].size; j++) {
            arr[index++] = buckets[i].arr[j];
        }
    }
}

int main() {
    srand(time(NULL));

    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *arr = (int *) malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_SIZE;
    }

    Bucket *buckets = (Bucket *) malloc(MAX_BUCKETS * sizeof(Bucket));
    createBuckets(buckets, MAX_BUCKETS);

    bucketSort(arr, size, buckets, MAX_BUCKETS);

    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    deleteBuckets(buckets, MAX_BUCKETS);
    free(arr);

    return 0;
}