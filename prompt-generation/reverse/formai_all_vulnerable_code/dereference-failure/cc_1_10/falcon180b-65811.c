//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MAX_RANGE 1000000

void generateArray(int* arr, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_RANGE;
    }
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucketSort(int* arr, int size) {
    int* buckets = (int*) malloc(MAX_RANGE * sizeof(int));
    int bucketCount = 0;

    // Count frequency of each element
    for (int i = 0; i < size; i++) {
        if (arr[i] < MAX_RANGE) {
            buckets[arr[i]]++;
        }
    }

    // Add elements to buckets
    int* sortedArr = (int*) malloc(size * sizeof(int));
    sortedArr[0] = buckets[0];
    int j = 1;
    for (int i = 0; i < MAX_RANGE; i++) {
        if (buckets[i] > 0) {
            while (buckets[i] > 0) {
                sortedArr[j++] = i;
                buckets[i]--;
            }
        }
    }

    // Copy sorted elements back to original array
    for (int i = 0; i < size; i++) {
        arr[i] = sortedArr[i];
    }

    free(buckets);
    free(sortedArr);
}

int main() {
    int size = MAX_SIZE;
    int* arr = (int*) malloc(size * sizeof(int));

    generateArray(arr, size);
    printf("Before sorting:\n");
    printArray(arr, size);

    bucketSort(arr, size);
    printf("After sorting:\n");
    printArray(arr, size);

    free(arr);
    return 0;
}