//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int *arr;
    int size;
} Bucket;

void createBucket(Bucket *bucket, int size) {
    bucket->arr = (int *)malloc(size * sizeof(int));
    bucket->size = size;
}

void destroyBucket(Bucket *bucket) {
    free(bucket->arr);
}

void insertElement(Bucket *bucket, int num) {
    int i = 0;
    while (i < bucket->size && bucket->arr[i]!= -1) {
        i++;
    }
    bucket->arr[i] = num;
}

void printBucket(Bucket *bucket) {
    int i = 0;
    while (i < bucket->size) {
        if (bucket->arr[i]!= -1) {
            printf("%d ", bucket->arr[i]);
        }
        i++;
    }
    printf("\n");
}

void bucketSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    int range = max / n;
    Bucket *buckets = (Bucket *)malloc(n * sizeof(Bucket));
    for (int i = 0; i < n; i++) {
        createBucket(&buckets[i], range);
    }
    for (int i = 0; i < n; i++) {
        int index = arr[i] / range;
        insertElement(&buckets[index], arr[i]);
    }
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (buckets[i].arr[j]!= -1) {
            arr[j] = buckets[i].arr[j];
            j++;
        }
    }
    for (int i = 0; i < n; i++) {
        destroyBucket(&buckets[i]);
    }
    free(buckets);
}

int main() {
    int arr[] = { 37, 12, 22, 5, 9, 55, 33, 2, 44, 66, 77, 88, 99 };
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}