//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MAX_RANGE 1000

typedef struct {
    int *arr;
    int size;
    int range;
} Bucket;

void createBuckets(Bucket *buckets, int size, int range) {
    for (int i = 0; i < size; i++) {
        buckets[i].arr = malloc(range * sizeof(int));
        buckets[i].size = 0;
        buckets[i].range = range;
    }
}

void freeBuckets(Bucket *buckets, int size) {
    for (int i = 0; i < size; i++) {
        free(buckets[i].arr);
    }
}

void bucketSort(int *arr, int size, int range) {
    Bucket *buckets = malloc(size * sizeof(Bucket));
    createBuckets(buckets, size, range);

    for (int i = 0; i < size; i++) {
        int index = arr[i] / range;
        buckets[index].arr[buckets[index].size++] = arr[i];
    }

    int index = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < buckets[i].size; j++) {
            arr[index++] = buckets[i].arr[j];
        }
    }

    freeBuckets(buckets, size);
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *arr = malloc(size * sizeof(int));

    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_RANGE;
    }

    printf("Before sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, size, MAX_RANGE);

    printf("After sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}