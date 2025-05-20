//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000000

void bucket_sort(int arr[], int n) {
    int buckets[MAX_SIZE];
    int *bucket_ptr = &buckets[0];
    int bucket_capacity = MAX_SIZE / 3;
    int bucket_count = 0;
    int i, j;

    for (i = 0; i < n; i++) {
        while (bucket_count == bucket_capacity) {
            bucket_count = 0;
            for (j = 0; j < bucket_capacity; j++) {
                if (buckets[j] == 0) {
                    break;
                }
                bucket_count++;
            }
            if (bucket_count == 0) {
                break;
            }
            for (j = 0; j < bucket_capacity; j++) {
                buckets[j] = 0;
            }
        }
        bucket_ptr[bucket_count] = arr[i];
        bucket_count++;
    }

    for (i = 0; i < n; i++) {
        arr[i] = bucket_ptr[i];
    }

    free(bucket_ptr);
}

int main() {
    int arr[] = {10, 4, 20, 2, 1, 7, 5, 3, 8, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    bucket_sort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}