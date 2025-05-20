//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_BUCKETS 10
#define BUCKET_SIZE 10

typedef struct Bucket {
    int *arr;
    int size;
    struct Bucket *next;
} Bucket;

void insert(Bucket **buckets, int data) {
    int bucket_index = data / BUCKET_SIZE;
    Bucket *bucket = buckets[bucket_index];
    if (!bucket) {
        bucket = malloc(sizeof(Bucket));
        buckets[bucket_index] = bucket;
        bucket->arr = malloc(BUCKET_SIZE * sizeof(int));
        bucket->size = 0;
    }
    bucket->arr[bucket->size++] = data;
}

void bucket_sort(int **arr, int n) {
    Bucket **buckets = malloc(MAX_BUCKETS * sizeof(Bucket));
    for (int i = 0; i < MAX_BUCKETS; i++) {
        buckets[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        insert(buckets, arr[i]);
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
    int arr[] = {4, 3, 8, 6, 2, 5, 1, 9, 7, 0};
    int n = sizeof(arr) / sizeof(int);

    bucket_sort(arr, n);

    printf("Sorted array:");
    for (int i = 0; i < n; i++) {
        printf(" %d", arr[i]);
    }

    return 0;
}