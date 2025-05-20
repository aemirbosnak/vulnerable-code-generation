//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 100.0
#define BUCKET_COUNT 10

typedef struct Bucket {
    float *values;
    int size;
    int capacity;
} Bucket;

void initBucket(Bucket *bucket) {
    bucket->size = 0;
    bucket->capacity = 2;
    bucket->values = (float *)malloc(sizeof(float) * bucket->capacity);
}

void addToBucket(Bucket *bucket, float value) {
    if (bucket->size >= bucket->capacity) {
        bucket->capacity *= 2;
        bucket->values = (float *)realloc(bucket->values, sizeof(float) * bucket->capacity);
    }
    bucket->values[bucket->size++] = value;
}

void insertSort(Bucket *bucket) {
    for (int i = 1; i < bucket->size; i++) {
        float key = bucket->values[i];
        int j = i - 1;
        while (j >= 0 && bucket->values[j] > key) {
            bucket->values[j + 1] = bucket->values[j];
            j--;
        }
        bucket->values[j + 1] = key;
    }
}

void bucketSort(float *array, int n) {
    Bucket *buckets = (Bucket *)malloc(sizeof(Bucket) * BUCKET_COUNT);
    for (int i = 0; i < BUCKET_COUNT; i++) {
        initBucket(&buckets[i]);
    }

    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(BUCKET_COUNT * (array[i] / MAX_VALUE));
        if (bucketIndex >= BUCKET_COUNT) {
            bucketIndex = BUCKET_COUNT - 1;
        }
        addToBucket(&buckets[bucketIndex], array[i]);
    }

    for (int i = 0; i < BUCKET_COUNT; i++) {
        insertSort(&buckets[i]);
    }

    int index = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        for (int j = 0; j < buckets[i].size; j++) {
            array[index++] = buckets[i].values[j];
        }
        free(buckets[i].values);
    }
    free(buckets);
}

int main() {
    int n = 20;
    float *array = (float *)malloc(sizeof(float) * n);

    printf("Input array:\n");
    for (int i = 0; i < n; i++) {
        array[i] = (float)(rand() % (int)MAX_VALUE);
        printf("%f ", array[i]);
    }

    printf("\nSorting...\n");
    bucketSort(array, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%f ", array[i]);
    }

    free(array);
    return 0;
}