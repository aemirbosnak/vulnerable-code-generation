//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_VALUE 100000

typedef struct bucket_t {
    int *arr;
    int size;
    int capacity;
} bucket_t;

bucket_t *create_bucket(int capacity) {
    bucket_t *bucket = (bucket_t *)malloc(sizeof(bucket_t));
    bucket->arr = (int *)malloc(sizeof(int) * capacity);
    bucket->size = 0;
    bucket->capacity = capacity;
    return bucket;
}

void destroy_bucket(bucket_t *bucket) {
    free(bucket->arr);
    free(bucket);
}

void insert_bucket(bucket_t *bucket, int value) {
    assert(bucket->size < bucket->capacity);
    bucket->arr[bucket->size++] = value;
}

void sort_bucket(bucket_t *bucket) {
    for (int i = 0; i < bucket->size - 1; i++) {
        for (int j = i + 1; j < bucket->size; j++) {
            if (bucket->arr[j] < bucket->arr[i]) {
                int temp = bucket->arr[i];
                bucket->arr[i] = bucket->arr[j];
                bucket->arr[j] = temp;
            }
        }
    }
}

void bucket_sort(int *arr, int size) {
    bucket_t **buckets = (bucket_t **)malloc(sizeof(bucket_t *) * MAX_VALUE);
    for (int i = 0; i < MAX_VALUE; i++) {
        buckets[i] = create_bucket(size);
    }

    for (int i = 0; i < size; i++) {
        int value = arr[i];
        insert_bucket(buckets[value], value);
    }

    for (int i = 0; i < MAX_VALUE; i++) {
        sort_bucket(buckets[i]);
    }

    int index = 0;
    for (int i = 0; i < MAX_VALUE; i++) {
        for (int j = 0; j < buckets[i]->size; j++) {
            arr[index++] = buckets[i]->arr[j];
        }
        destroy_bucket(buckets[i]);
    }
    free(buckets);
}

int main() {
    int arr[] = {5, 3, 1, 7, 4, 1, 2, 8, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    bucket_sort(arr, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}