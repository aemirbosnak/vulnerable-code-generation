//MISTRAL-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE(x) sizeof(x)/sizeof(x[0])
#define MIN(x, y) ((x) < (y) ? (x) : (y))

void bucketSort(int *arr, int n, int bucketCount) {
    int i, j, bucketIndex, temp;
    int *bucket;

    bucket = (int *)calloc(bucketCount, sizeof(int));

    for (i = 0; i < bucketCount; i++)
        bucket[i] = 0;

    for (i = 0; i < n; i++) {
        bucketIndex = arr[i] / bucketCount;
        bucket[bucketIndex]++;
    }

    for (i = 1; i < bucketCount; i++)
        bucket[i] += bucket[i - 1];

    for (i = n - 1; i >= 0; i--) {
        bucketIndex = arr[i] / bucketCount;
        j = bucket[arr[i] % bucketCount] - 1;
        temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
        bucket[arr[i] % bucketCount]--;
    }

    free(bucket);
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = ARRAY_SIZE(arr), bucketCount;

    printf("Original Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    bucketCount = 3;
    bucketSort(arr, n, bucketCount);

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}