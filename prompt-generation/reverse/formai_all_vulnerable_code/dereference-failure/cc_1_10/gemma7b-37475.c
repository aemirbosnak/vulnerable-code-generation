//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUCKETS 10

typedef struct Bucket {
    int key;
    struct Bucket* next;
} Bucket;

void insertBucket(int key, Bucket** buckets) {
    Bucket* newBucket = malloc(sizeof(Bucket));
    newBucket->key = key;
    newBucket->next = NULL;

    if (*buckets == NULL) {
        *buckets = newBucket;
    } else {
        (*buckets)->next = newBucket;
        *buckets = newBucket;
    }
}

void bucketSort(int arr[], int n) {
    Bucket** buckets = malloc(MAX_BUCKETS * sizeof(Bucket));

    for (int i = 0; i < MAX_BUCKETS; i++) {
        buckets[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        insertBucket(arr[i], buckets);
    }

    int i = 0;
    for (Bucket* bucket = buckets[0]; bucket; bucket = bucket->next) {
        arr[i++] = bucket->key;
    }

    free(buckets);
}

int main() {
    int arr[] = {3, 5, 8, 2, 4, 7, 6, 1, 9, 0};
    int n = sizeof(arr) / sizeof(int);

    bucketSort(arr, n);

    printf("Sorted array:");
    for (int i = 0; i < n; i++) {
        printf(" %d ", arr[i]);
    }

    printf("\n");

    return 0;
}