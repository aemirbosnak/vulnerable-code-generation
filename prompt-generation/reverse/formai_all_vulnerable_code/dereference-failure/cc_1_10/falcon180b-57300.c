//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int size;
    int *arr;
} Bucket;

void createBucket(Bucket *bucket, int size) {
    bucket->size = size;
    bucket->arr = (int *)malloc(size * sizeof(int));
}

void insertElement(Bucket *bucket, int element) {
    int i = 0;
    while (i < bucket->size && bucket->arr[i]!= -1) {
        i++;
    }
    bucket->arr[i] = element;
}

void sortBucket(Bucket *bucket) {
    int i, j;
    int temp;
    for (i = 0; i < bucket->size - 1; i++) {
        for (j = 0; j < bucket->size - i - 1; j++) {
            if (bucket->arr[j] > bucket->arr[j + 1]) {
                temp = bucket->arr[j];
                bucket->arr[j] = bucket->arr[j + 1];
                bucket->arr[j + 1] = temp;
            }
        }
    }
}

void bucketSort(int *arr, int n) {
    int i, j, max = arr[0], min = arr[0];
    int range = max - min + 1;
    Bucket *bucket = (Bucket *)malloc(range * sizeof(Bucket));
    for (i = 0; i < range; i++) {
        createBucket(&bucket[i], 0);
    }
    for (i = 0; i < n; i++) {
        insertElement(&bucket[(arr[i] - min) / (max - min) * range], arr[i]);
    }
    for (i = 0; i < range; i++) {
        sortBucket(&bucket[i]);
    }
    i = 0;
    for (j = 0; j < n; j++) {
        arr[j] = bucket[(arr[j] - min) / (max - min) * range].arr[i++];
    }
    free(bucket);
}

int main() {
    int arr[] = { 5, 7, 3, 9, 1, 8, 6, 2, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}