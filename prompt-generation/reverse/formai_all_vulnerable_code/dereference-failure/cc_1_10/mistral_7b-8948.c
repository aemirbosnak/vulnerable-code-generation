//MISTRAL-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int length;
} CBucket;

CBucket *createBucket() {
    CBucket *bucket = (CBucket *)malloc(sizeof(CBucket));
    bucket->length = 0;
    return bucket;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printBucket(CBucket *bucket) {
    for (int i = 0; i < bucket->length; i++) {
        printf("%d ", bucket->data[i]);
    }
    printf("\n");
}

int getBucketIndex(int value, int bucketSize) {
    int index = floor(value / (float)bucketSize);
    return index;
}

void bucketSort(CBucket *bucket) {
    int bucketSize = 1;
    int gap = 0;

    while (gap < bucket->length / 3) {
        gap = 2 * gap + 1;
    }

    for (int pass = 0; gap > 0; pass++) {
        for (int i = 0; i < bucket->length; i += bucketSize) {
            int index = getBucketIndex(bucket->data[i], bucketSize);

            for (int j = i + bucketSize; j > i && bucket->data[j] < bucket->data[i]; j -= bucketSize) {
                swap(&(bucket->data[j]), &(bucket->data[j - bucketSize]));
            }
        }

        bucketSize = gap;
        gap = gap / 2;
    }
}

int main() {
    CBucket *bucket = createBucket();

    srand(time(NULL));

    for (int i = 0; i < MAX_SIZE; i++) {
        bucket->data[i] = rand() % 100;
        bucket->length++;
    }

    printBucket(bucket);
    bucketSort(bucket);
    printBucket(bucket);

    free(bucket);

    return 0;
}