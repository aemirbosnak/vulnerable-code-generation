//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void bucketSortRecursive(int **arr, int n, int i) {
    if (i >= n - 1) {
        return;
    }

    int bucketSize = 10;
    int *buckets = (int *)malloc(bucketSize * sizeof(int));
    for (int j = 0; j < bucketSize; j++) {
        buckets[j] = 0;
    }

    for (int j = 0; j < n; j++) {
        buckets[*arr[j]]++;
    }

    for (int j = 0; j < bucketSize; j++) {
        if (buckets[j] > 0) {
            for (int k = 0; k < buckets[j]; k++) {
                arr[i] = j;
                i++;
            }
        }
    }

    free(buckets);
    bucketSortRecursive(arr, n, i);
}

int main() {
    int n = 10;
    int *arr = (int *)malloc(n * sizeof(int));
    arr[0] = 4;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 5;
    arr[4] = 2;
    arr[5] = 3;
    arr[6] = 1;
    arr[7] = 4;
    arr[8] = 2;
    arr[9] = 3;

    bucketSortRecursive(arr, n, 0);

    printf("Sorted array:");
    for (int i = 0; i < n; i++) {
        printf(" %d", arr[i]);
    }

    free(arr);
    return 0;
}