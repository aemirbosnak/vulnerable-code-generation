//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int arr[], int n, int bucket_size) {
    int *buckets = malloc(n * sizeof(int));
    int *counts = malloc(n * sizeof(int));
    int *sorted_arr = malloc(n * sizeof(int));
    int *sorted_indices = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        buckets[i] = (int)(arr[i] / bucket_size);
    }

    for (int i = 0; i < n; i++) {
        counts[buckets[i]]++;
    }

    for (int i = 0; i < n; i++) {
        sorted_indices[i] = 0;
        sorted_arr[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        while (counts[buckets[i]] > 0) {
            sorted_arr[sorted_indices[i]] = arr[i];
            counts[buckets[i]]--;
            sorted_indices[i]++;
        }
    }

    for (int i = 0; i < n; i++) {
        arr[i] = sorted_arr[i];
    }

    free(buckets);
    free(counts);
    free(sorted_arr);
    free(sorted_indices);
}

int main() {
    int arr[] = {10, 3, 5, 2, 8, 6, 4, 1, 9, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int bucket_size = 3;

    bucket_sort(arr, n, bucket_size);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}