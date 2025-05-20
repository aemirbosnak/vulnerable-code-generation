//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int arr[], int n, int numBuckets) {
    int i, j;
    int minVal = arr[0], maxVal = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        } else if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    int bucketSize = ((maxVal - minVal) / numBuckets) + 1;
    int* buckets[numBuckets];
    for (i = 0; i < numBuckets; i++) {
        buckets[i] = (int*)malloc(sizeof(int) * n);
    }
    int bucketCounts[numBuckets];
    for (i = 0; i < numBuckets; i++) {
        bucketCounts[i] = 0;
    }

    for (i = 0; i < n; i++) {
        int bucketIndex = (arr[i] - minVal) / bucketSize;
        buckets[bucketIndex][bucketCounts[bucketIndex]] = arr[i];
        bucketCounts[bucketIndex]++;
    }

    int k = 0;
    for (i = 0; i < numBuckets; i++) {
        int* bucket = buckets[i];
        int bucketCount = bucketCounts[i];
        for (j = 0; j < bucketCount; j++) {
            arr[k] = bucket[j];
            k++;
        }
        free(bucket);
    }
}

int main() {
    int arr[] = {23, 14, 56, 32, 97, 8, 40, 73};
    int n = sizeof(arr) / sizeof(arr[0]);
    int numBuckets = 3;
    printf("Before sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n, numBuckets);

    printf("After sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}