//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUCKETS 10

typedef struct Bucket {
    int *arr;
    int size;
    struct Bucket *next;
} Bucket;

Bucket *createBucket(int size) {
    Bucket *bucket = malloc(sizeof(Bucket));
    bucket->arr = malloc(size * sizeof(int));
    bucket->size = size;
    bucket->next = NULL;
    return bucket;
}

void insert(Bucket *bucket, int data) {
    int index = data % bucket->size;
    bucket->arr[index] = data;
}

void bucketSort(int **arr, int n) {
    Bucket **buckets = malloc(MAX_BUCKETS * sizeof(Bucket *));
    for (int i = 0; i < MAX_BUCKETS; i++) {
        buckets[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        insert(buckets[*arr[i]], *arr[i]);
    }

    int i = 0;
    for (Bucket *bucket = buckets[0]; bucket; bucket = bucket->next) {
        for (int j = 0; j < bucket->size; j++) {
            arr[i++] = bucket->arr[j];
        }
    }

    free(buckets);
}

int main() {
    int arr[] = {3, 5, 8, 2, 4, 7, 1, 9, 6, 0};
    int n = sizeof(arr) / sizeof(int);

    bucketSort(arr, n);

    printf("Sorted array:");
    for (int i = 0; i < n; i++) {
        printf(" %d", arr[i]);
    }

    printf("\n");

    return 0;
}