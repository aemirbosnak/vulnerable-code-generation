//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MAX_VALUE 100

void generateArray(int *arr, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_VALUE;
    }
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucketSort(int *arr, int size) {
    int bucketCount = MAX_VALUE / 10 + 1;
    int *buckets[bucketCount];

    for (int i = 0; i < bucketCount; i++) {
        buckets[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    for (int i = 0; i < size; i++) {
        int bucketIndex = arr[i] / 10;
        int *bucket = buckets[bucketIndex];
        int bucketSize = 0;

        for (int j = 0; j < bucketSize; j++) {
            if (bucket[j] == arr[i]) {
                return;
            }
        }

        bucket[bucketSize++] = arr[i];
    }

    for (int i = 0; i < bucketCount; i++) {
        int bucketSize = 0;
        int *bucket = buckets[i];

        while (bucketSize < size) {
            for (int j = 0; j < bucketSize; j++) {
                arr[j] = bucket[j];
            }

            bucketSize += 10;
        }
    }
}

int main() {
    int size = 50;
    int *arr = (int *)malloc(size * sizeof(int));

    generateArray(arr, size);
    printArray(arr, size);

    bucketSort(arr, size);
    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}