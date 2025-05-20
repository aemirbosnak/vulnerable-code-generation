//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int arr[], int n) {
    int max = arr[0], min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    int bucket_size = 10;
    int num_buckets = (max - min) / bucket_size + 1;
    int **buckets = (int **) malloc(sizeof(int *) * num_buckets);

    for (int i = 0; i < num_buckets; i++) {
        buckets[i] = (int *) malloc(sizeof(int) * n);
    }

    int *bucket_sizes = (int *) malloc(sizeof(int) * num_buckets);
    for (int i = 0; i < num_buckets; i++) {
        bucket_sizes[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int bucket_index = (arr[i] - min) / bucket_size;
        buckets[bucket_index][bucket_sizes[bucket_index]] = arr[i];
        bucket_sizes[bucket_index]++;
    }

    int k = 0;
    for (int i = 0; i < num_buckets; i++) {
        if (bucket_sizes[i] > 0) {
            for (int j = 0; j < bucket_sizes[i]; j++) {
                arr[k] = buckets[i][j];
                k++;
            }
        }
    }

    free(bucket_sizes);
    for (int i = 0; i < num_buckets; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

int main() {
    int arr[] = {4, 2, 7, 1, 6, 9, 3, 8, 5, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}