//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUCKET_SIZE 10

void printArray(int* arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucketSort(int* arr, int size) {
    int maxVal = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    int numBuckets = (maxVal / BUCKET_SIZE) + 1;
    int* buckets[numBuckets];
    int bucketSizes[numBuckets];
    for(int i = 0; i < numBuckets; i++) {
        buckets[i] = malloc(sizeof(int) * size);
        bucketSizes[i] = 0;
    }

    for(int i = 0; i < size; i++) {
        int bucketIndex = arr[i] / BUCKET_SIZE;
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
    }

    int currentIndex = 0;
    for(int i = 0; i < numBuckets; i++) {
        int* bucket = buckets[i];
        int bucketSize = bucketSizes[i];
        for(int j = 0; j < bucketSize; j++) {
            arr[currentIndex++] = bucket[j];
        }
        free(bucket);
    }
}

int main() {
    int arr[] = {29, 23, 43, 32, 21, 55, 57, 12, 18, 49};
    int size = sizeof(arr) / sizeof(int);

    printf("Before sorting: ");
    printArray(arr, size);

    bucketSort(arr, size);
    
    printf("After sorting: ");
    printArray(arr, size);

    return 0;
}