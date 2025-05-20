//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 10

void bucketSort(int arr[], int n) {
    int i, j, k;
    int *bucket;

    bucket = (int *)malloc(sizeof(int) * N);
    for (i = 0; i < N; i++) {
        bucket[i] = 0;
    }

    for (i = 0; i < n; i++) {
        k = arr[i];
        for (j = 0; j < N; j++) {
            if (bucket[j] < k) {
                bucket[j] = k;
                break;
            }
        }
    }

    for (i = 0; i < n; i++) {
        k = arr[i];
        for (j = 0; j < N; j++) {
            if (bucket[j] == k) {
                bucket[j] += 1;
                break;
            }
        }
        arr[i] = bucket[j];
    }

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[N] = {5, 2, 8, 1, 4, 6, 3, 9, 7, 0};

    printf("Original array: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, N);

    printf("Sorted array: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}