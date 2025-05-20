//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int[], int);
void insertionSort(int[], int);

void bucketSort(int arr[], int n) {
    int i, j;
    int *buckets;
    const int max = n;

    buckets = calloc(max, sizeof(int));

    for (i = 0; i < n; i++) {
        ++buckets[arr[i]];
    }

    for (i = 0, j = 0; j < max; j++) {
        for (int k = buckets[j]; k > 0; k--) {
            arr[i++] = j;
        }
    }

    free(buckets);
}

void insertionSort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main(int argc, char const *argv[]) {
    int arr[] = {7, 2, 1, 6, 8, 5, 3, 4};
    int n = sizeof(arr) / sizeof(int);

    bucketSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}