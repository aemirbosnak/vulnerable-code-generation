//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define RANGE 10000

void bucketSort(int arr[], int n) {
    int i, j, k = 0;
    int *bucket[RANGE];
    for (i = 0; i < RANGE; i++) {
        bucket[i] = (int *)malloc(MAX_SIZE * sizeof(int));
        for (j = 0; j < MAX_SIZE; j++) {
            bucket[i][j] = -1;
        }
    }

    for (i = 0; i < n; i++) {
        k = arr[i] / (RANGE / MAX_SIZE);
        bucket[k][arr[i] % (RANGE / MAX_SIZE)] = i;
    }

    for (i = 0; i < n; i++) {
        k = bucket[arr[i] / (RANGE / MAX_SIZE)][arr[i] % (RANGE / MAX_SIZE)];
        arr[i] = (k == -1)? arr[i] : bucket[k][--bucket[k][0]];
    }
}

int main() {
    int i, n;
    srand(time(NULL));
    n = rand() % 50 + 1;
    int arr[n];

    for (i = 0; i < n; i++) {
        arr[i] = rand() % RANGE;
    }

    printf("Before sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n);

    printf("After sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}