//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define MAX_VALUE 1000

typedef struct {
    int *arr;
    int size;
} Bucket;

void createBucket(Bucket *b, int size) {
    b->arr = (int *)malloc(size * sizeof(int));
    b->size = size;
    for (int i = 0; i < size; i++) {
        b->arr[i] = -1;
    }
}

void destroyBucket(Bucket *b) {
    free(b->arr);
    b->size = 0;
}

void insertElement(Bucket *b, int value) {
    int index = value / b->size;
    int position = 0;
    while (b->arr[index]!= -1 && position < b->size) {
        position++;
        index++;
    }
    if (position < b->size) {
        b->arr[index] = value;
    }
}

void printBucket(Bucket *b) {
    for (int i = 0; i < b->size; i++) {
        int value = b->arr[i];
        if (value!= -1) {
            printf("%d ", value);
        }
    }
    printf("\n");
}

void bucketSort(int *arr, int size) {
    Bucket *bucket = (Bucket *)malloc(sizeof(Bucket));
    createBucket(bucket, size);

    for (int i = 0; i < size; i++) {
        insertElement(bucket, arr[i]);
    }

    int index = 0;
    for (int i = 0; i < size; i++) {
        int value = bucket->arr[i];
        while (value!= -1) {
            arr[index++] = value;
            value = bucket->arr[i];
        }
    }

    destroyBucket(bucket);
    free(bucket);
}

int main() {
    int arr[] = {34, 56, 12, 98, 76, 23, 45, 67, 89, 12};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, size);

    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}