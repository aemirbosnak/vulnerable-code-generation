//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int *arr;
    int size;
} Bucket;

void createBucket(Bucket *b, int size) {
    b->arr = (int *)malloc(size * sizeof(int));
    b->size = size;
}

void insertElement(Bucket *b, int val) {
    int i = 0;
    while (i < b->size && b->arr[i]!= val) {
        i++;
    }
    if (i == b->size) {
        b->arr[i] = val;
        b->size++;
    }
}

void printBucket(Bucket b) {
    int i;
    for (i = 0; i < b.size; i++) {
        printf("%d ", b.arr[i]);
    }
    printf("\n");
}

void bucketSort(int *arr, int size) {
    int i, j, max = arr[0], min = arr[0];
    Bucket *b = (Bucket *)malloc(MAX_SIZE * sizeof(Bucket));

    for (i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    for (i = 0; i < MAX_SIZE; i++) {
        createBucket(&b[i], 0);
    }

    for (i = 0; i < size; i++) {
        insertElement(&b[(arr[i] - min) / (max - min) * MAX_SIZE], arr[i]);
    }

    for (i = 0; i < size; i++) {
        arr[i] = b[(arr[i] - min) / (max - min) * MAX_SIZE].arr[0];
    }

    for (i = 0; i < MAX_SIZE; i++) {
        free(b[i].arr);
    }
    free(b);
}

int main() {
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, size);

    printf("After sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}