//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000

typedef struct {
    int *data;
    int size;
} Bucket;

void createBucket(Bucket *bucket, int size) {
    bucket->data = malloc(size * sizeof(int));
    bucket->size = size;
}

void destroyBucket(Bucket *bucket) {
    free(bucket->data);
}

void fillBucket(Bucket *bucket, int *arr, int n, int (*comparator)(int, int)) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        j = comparator(arr[i], 0);
        if (j >= bucket->size) {
            bucket->size = j + 1;
            bucket->data = realloc(bucket->data, bucket->size * sizeof(int));
        }
        k = bucket->data[j];
        while (k && comparator(arr[i], k) > 0) {
            k = bucket->data[--j];
        }
        bucket->data[j] = arr[i];
    }
}

void sortBucket(Bucket *bucket, int (*comparator)(int, int)) {
    int i, j, k;
    for (i = 0; i < bucket->size; i++) {
        k = bucket->data[i];
        while (k && comparator(k, i) > 0) {
            bucket->data[i] = bucket->data[--j];
            k = bucket->data[j];
        }
        bucket->data[j] = k;
    }
}

void printBucket(Bucket *bucket) {
    int i;
    for (i = 0; i < bucket->size; i++) {
        printf("%d ", bucket->data[i]);
    }
    printf("\n");
}

int compareInts(int a, int b) {
    return a - b;
}

int main() {
    srand(time(NULL));
    int n = rand() % MAX_SIZE + 1;
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % MAX_SIZE;
    }

    Bucket bucket;
    createBucket(&bucket, MAX_SIZE);
    fillBucket(&bucket, arr, n, compareInts);
    sortBucket(&bucket, compareInts);
    printBucket(&bucket);

    destroyBucket(&bucket);
    return 0;
}