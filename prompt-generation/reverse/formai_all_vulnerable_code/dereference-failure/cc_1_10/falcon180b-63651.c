//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100

void bucketSort(int arr[], int n) {
    int i, j, k, index, max = arr[0], min = arr[0];

    for (i = 0; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    int bucket_size = (max - min) / n;
    int *bucket[n];

    for (i = 0; i < n; i++) {
        bucket[i] = (int *)malloc(sizeof(int) * (max - min + 1));
        for (j = 0; j <= max - min; j++)
            bucket[i][j] = 0;
    }

    for (i = 0; i < n; i++) {
        index = (arr[i] - min) / bucket_size;
        bucket[index][arr[i] - min]++;
    }

    int sorted_arr[n];
    int count = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j <= max - min; j++) {
            if (bucket[i][j] > 0) {
                sorted_arr[count++] = min + j * bucket_size + i * bucket_size;
                bucket[i][j]--;
            }
        }
    }

    for (i = 0; i < n; i++)
        free(bucket[i]);

    for (i = 0; i < n; i++)
        arr[i] = sorted_arr[i];
}

int main() {
    int arr[] = { 37, 12, 28, 9, 100, 56, 80, 5, 12 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    bucketSort(arr, n);

    printf("\nAfter sorting:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}