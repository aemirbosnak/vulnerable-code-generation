//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int arr[], int n, int *buckets) {
    int i, j, k, *arr_copy;

    // Allocate memory for bucket array
    int *bucket = (int *)malloc(n * sizeof(int));

    // Initialize bucket array
    for (i = 0; i < n; i++) {
        bucket[i] = 0;
    }

    // Create a copy of the input array
    arr_copy = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        arr_copy[i] = arr[i];
    }

    // Insert each element into its appropriate bucket
    for (i = 0; i < n; i++) {
        j = arr_copy[i];
        while (j!= 0) {
            buckets[j]++;
            j = arr_copy[j];
        }
    }

    // Merge elements from each bucket into sorted array
    for (i = 0; i < n; i++) {
        arr_copy[i] = arr[i];
        for (j = 1; j < buckets[i]; j++) {
            arr_copy[i + j] = arr[i];
        }
    }

    // Free memory
    free(bucket);
    free(arr_copy);
}

int main() {
    int arr[] = {5, 2, 8, 1, 9, 3, 6, 4, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int *buckets;

    buckets = (int *)malloc(n * sizeof(int));

    // Call bucket sort function
    bucket_sort(arr, n, buckets);

    // Print sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free memory
    free(buckets);

    return 0;
}