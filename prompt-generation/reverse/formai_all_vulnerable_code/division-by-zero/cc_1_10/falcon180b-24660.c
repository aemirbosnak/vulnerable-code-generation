//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

void bucketSort(int arr[], int n) {
    int i, j;
    int max = arr[0];
    int min = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        } else if (arr[i] < min) {
            min = arr[i];
        }
    }

    int range = (max - min) / n;
    int *buckets[MAX_SIZE];

    for (i = 0; i < n; i++) {
        int index = (arr[i] - min) / range;
        if (buckets[index] == NULL) {
            buckets[index] = malloc(sizeof(int) * n);
        }
        int *bucket = buckets[index];
        bucket[0] = arr[i];
        for (j = 1; j < n; j++) {
            if (arr[j] - min == index * range) {
                bucket[j] = arr[j];
            }
        }
    }

    i = 0;
    for (j = 0; j < n; j++) {
        int *bucket = buckets[j];
        for (int k = 0; k < n; k++) {
            if (bucket[k]!= 0) {
                arr[i++] = bucket[k];
            }
        }
    }
}

int main() {
    int arr[] = { 5, 3, 8, 1, 7, 2, 4, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n);

    printf("After sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}