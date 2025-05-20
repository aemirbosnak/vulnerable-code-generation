//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bucket_sort(int* arr, int n, int bucket_size) {
    int* buckets = (int*)malloc(sizeof(int) * bucket_size);
    memset(buckets, 0, sizeof(int) * bucket_size);

    int* bucket_counts = (int*)malloc(sizeof(int) * bucket_size);
    memset(bucket_counts, 0, sizeof(int) * bucket_size);

    int* sorted_arr = (int*)malloc(sizeof(int) * n);
    memset(sorted_arr, 0, sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        int bucket_index = arr[i] / bucket_size;
        bucket_counts[bucket_index]++;

        buckets[bucket_index] += arr[i];
    }

    for (int i = 0; i < bucket_size; i++) {
        if (bucket_counts[i] > 0) {
            sorted_arr[i] = buckets[i] / bucket_counts[i];

            for (int j = 0; j < bucket_counts[i]; j++) {
                arr[i * bucket_counts[i] + j] = sorted_arr[i];
            }
        }
    }

    free(buckets);
    free(bucket_counts);
    free(sorted_arr);
}

int main() {
    int n = 10;
    int* arr = (int*)malloc(sizeof(int) * n);
    memset(arr, 0, sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    bucket_sort(arr, n, 10);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}