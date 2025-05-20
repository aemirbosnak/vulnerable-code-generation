//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Define a function to sort an array using 
// insertion sort (can be replaced with any 
// other sorting algorithm)
void insertion_sort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Define a function to perform bucket sort
void bucket_sort(int arr[], int n, int num_buckets) {
    int i, j, max_val, bucket_idx;
    int *buckets[num_buckets];

    // Initialize the buckets
    for (i = 0; i < num_buckets; i++) {
        buckets[i] = (int*)malloc(sizeof(int) * n);
    }

    // Find the maximum value in the array
    max_val = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    // Distribute the elements of the array into the buckets
    for (i = 0; i < n; i++) {
        bucket_idx = (num_buckets * arr[i]) / (max_val + 1);
        buckets[bucket_idx][i] = arr[i];
    }

    // Sort each bucket using insertion sort
    for (i = 0; i < num_buckets; i++) {
        insertion_sort(buckets[i], n);
    }

    // Concatenate the sorted buckets back into the original array
    j = 0;
    for (i = 0; i < num_buckets; i++) {
        for (int k = 0; k < n; k++) {
            if (buckets[i][k] != 0) {
                arr[j++] = buckets[i][k];
            }
        }

        free(buckets[i]);
    }
}

// Example usage
int main() {
    int arr[] = { 3, 1, 4, 2, 7, 6, 8, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int num_buckets = 3;

    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucket_sort(arr, n, num_buckets);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}