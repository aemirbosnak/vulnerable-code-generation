//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int arr[], int n) {
    int max_elem = 0, min_bucket = 0, bucket_size = 0;
    int *buckets = (int *)malloc(sizeof(int) * (n + 1));
    int *buckets_end = buckets + n + 1;

    for (int i = 0; i < n; i++) {
        buckets[i] = arr[i];
    }

    while (buckets_end - buckets > 1) {
        max_elem = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] > max_elem) {
                max_elem = arr[i];
            }
        }

        bucket_size = (buckets_end - buckets) / max_elem;
        min_bucket = 0;
        for (int i = 0; i < bucket_size; i++) {
            buckets[min_bucket] = arr[min_bucket];
            min_bucket++;
        }

        buckets_end = buckets + bucket_size;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = buckets[i];
    }

    free(buckets);
}

int main() {
    int arr[] = {3, 8, 4, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucket_sort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}