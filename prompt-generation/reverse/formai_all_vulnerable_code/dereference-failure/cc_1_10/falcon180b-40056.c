//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void bucket_sort(int arr[], int n) {
    int i, j, max_val, min_val, range, bucket_size;
    int *buckets[MAX_SIZE];

    // calculate range
    max_val = arr[0];
    min_val = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }
    range = max_val - min_val + 1;

    // calculate bucket size
    bucket_size = range / n;

    // create buckets
    for (i = 0; i < n; i++) {
        buckets[i] = (int *)malloc(bucket_size * sizeof(int));
    }

    // place elements in buckets
    for (i = 0; i < n; i++) {
        j = (arr[i] - min_val) / bucket_size;
        buckets[j][(arr[i] - min_val) % bucket_size] = arr[i];
    }

    // concatenate buckets
    i = 0;
    for (j = 0; j < n; j++) {
        for (int k = 0; k < bucket_size; k++) {
            if (buckets[j][k]!= 0) {
                arr[i] = buckets[j][k];
                i++;
            }
        }
    }

    // free memory
    for (i = 0; i < n; i++) {
        free(buckets[i]);
    }
}

int main() {
    int arr[] = { 5, 2, 7, 1, 8, 4, 6, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucket_sort(arr, n);

    printf("\nAfter sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}