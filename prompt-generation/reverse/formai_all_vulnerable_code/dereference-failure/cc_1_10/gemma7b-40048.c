//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers
int compare(int a, int b) {
    return a - b;
}

void bucketSort(int *arr, int n) {
    int i, j, k, bucketSize, min, max;
    bucketSize = 10;
    min = arr[0];
    max = arr[0];
    for (i = 1; i < n; i++) {
        if (min > arr[i]) {
            min = arr[i];
        }
        if (max < arr[i]) {
            max = arr[i];
        }
    }

    // Calculate the number of buckets
    int numBuckets = (max - min) / bucketSize + 1;

    // Create buckets
    int *buckets = (int *)malloc(numBuckets * sizeof(int));
    for (i = 0; i < numBuckets; i++) {
        buckets[i] = 0;
    }

    // Distribute the elements into the buckets
    for (i = 0; i < n; i++) {
        buckets[arr[i] / bucketSize]++;
    }

    // Merge the buckets
    i = 0;
    for (j = 0; j < numBuckets; j++) {
        for (k = 0; k < buckets[j]; k++) {
            arr[i++] = min + j * bucketSize;
        }
    }

    free(buckets);
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(int);

    bucketSort(arr, n);

    printf("Sorted array:");
    for (int i = 0; i < n; i++) {
        printf(" %d", arr[i]);
    }

    printf("\n");

    return 0;
}