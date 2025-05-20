//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int arr[], int n) {
    int i, j, k, temp, bucket_size;
    int *bucket;

    // calculate the bucket size
    bucket_size = (n / 10) + 1;

    // allocate memory for buckets
    bucket = (int *)malloc(bucket_size * sizeof(int));

    // initialize all buckets to -1
    for (i = 0; i < bucket_size; i++) {
        bucket[i] = -1;
    }

    // put elements into respective buckets
    for (i = 0; i < n; i++) {
        j = arr[i] / bucket_size;
        bucket[j] = bucket[j] == -1? arr[i] : arr[i];
    }

    // sort each bucket
    for (i = 0; i < bucket_size; i++) {
        k = 0;
        for (j = 0; j < bucket_size; j++) {
            if (bucket[j]!= -1 && bucket[j]!= bucket[i]) {
                bucket[k] = bucket[j];
                k++;
            }
        }
        bucket[k] = bucket[i];
        k++;
        bucket[k] = -1;
    }

    // put sorted elements back into the original array
    for (i = 0; i < n; i++) {
        j = arr[i] / bucket_size;
        if (bucket[j]!= -1) {
            arr[i] = bucket[j];
        }
    }

    // free memory
    free(bucket);
}

int main() {
    int arr[] = {5, 3, 2, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucket_sort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}