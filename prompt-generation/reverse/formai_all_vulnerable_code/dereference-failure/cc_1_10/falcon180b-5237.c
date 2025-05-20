//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int *arr;
    int size;
} Bucket;

void createBucket(Bucket **bucket, int size) {
    *bucket = (Bucket*) malloc(sizeof(Bucket));
    (*bucket)->arr = (int*) malloc(sizeof(int) * size);
    (*bucket)->size = size;
}

void destroyBucket(Bucket *bucket) {
    free(bucket->arr);
    free(bucket);
}

void insertElement(Bucket *bucket, int element) {
    int i = 0;
    int index = element / bucket->size;
    while (i < bucket->size && element % bucket->size!= 0) {
        if (bucket->arr[i] == -1) {
            bucket->arr[i] = element;
            return;
        }
        i++;
    }
    if (i == bucket->size) {
        printf("Bucket is full\n");
        exit(0);
    }
    bucket->arr[i] = element;
}

void printBucket(Bucket *bucket) {
    int i = 0;
    printf("Bucket:\n");
    for (i = 0; i < bucket->size; i++) {
        if (bucket->arr[i]!= -1) {
            printf("%d ", bucket->arr[i]);
        } else {
            printf("-1 ");
        }
    }
    printf("\n");
}

void bucketSort(int *arr, int size) {
    int i = 0, j = 0;
    Bucket *bucket = NULL;
    createBucket(&bucket, size);
    for (i = 0; i < size; i++) {
        insertElement(bucket, arr[i]);
    }
    for (i = 0; i < size; i++) {
        arr[i] = -1;
    }
    for (i = 0; i < size; i++) {
        for (j = 0; j < bucket->size; j++) {
            if (bucket->arr[j]!= -1) {
                if (bucket->arr[j] == i) {
                    arr[i] = bucket->arr[j];
                    bucket->arr[j] = -1;
                }
            }
        }
    }
    destroyBucket(bucket);
}

int main() {
    int arr[] = { 5, 2, 9, 1, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bucketSort(arr, n);
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}