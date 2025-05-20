//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void bucketSort(int arr[], int n) {
    int i, j, max = arr[0], min = arr[0];
    int *bucket[n];

    // Find min and max values in the array
    for (i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // Calculate bucket size
    int range = max - min + 1;
    int bucket_size = range / n;

    // Create empty buckets
    for (i = 0; i < n; i++) {
        bucket[i] = (int *)malloc(sizeof(int) * bucket_size);
        for (j = 0; j < bucket_size; j++) {
            bucket[i][j] = 0;
        }
    }

    // Place elements in their respective buckets
    for (i = 0; i < n; i++) {
        int bucket_index = (arr[i] - min) / bucket_size;
        bucket[bucket_index][arr[i] - min % bucket_size]++;
    }

    // Concatenate the buckets
    int index = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < bucket_size; j++) {
            while (bucket[i][j] > 0) {
                arr[index++] = min + j * bucket_size + bucket[i][j] - 1;
                bucket[i][j]--;
            }
        }
    }
}

int main() {
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucketSort(arr, n);

    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}