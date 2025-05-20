//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// function declarations
void sort(int[], int);
void printArray(int[], int);

// implementation of Bucket Sort
void sort(int arr[], int n) {
    // initialize the buckets
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    int bucket_size = max_val / 3 + 1;
    int **buckets = (int **)malloc(bucket_size * sizeof(int *));
    for (int i = 0; i < bucket_size; i++) {
        buckets[i] = (int *)malloc(n * sizeof(int));
    }
    int *bucket_sizes = (int *)calloc(bucket_size, sizeof(int));

    // put each element into the appropriate bucket
    for (int i = 0; i < n; i++) {
        int bucket_index = arr[i] / 3;
        buckets[bucket_index][bucket_sizes[bucket_index]] = arr[i];
        bucket_sizes[bucket_index]++;
    }

    // sort each bucket using insertion sort
    for (int i = 0; i < bucket_size; i++) {
        for (int j = 1; j < bucket_sizes[i]; j++) {
            int key = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }
    }

    // combine the sorted buckets into the final array
    int index = 0;
    for (int i = 0; i < bucket_size; i++) {
        for (int j = 0; j < bucket_sizes[i]; j++) {
            arr[index] = buckets[i][j];
            index++;
        }
    }

    // free memory used by the buckets
    for (int i = 0; i < bucket_size; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucket_sizes);
}

// utility function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// main function for testing the implementation
int main() {
    int arr[] = {25, 30, 16, 5, 8, 12, 18, 22, 28, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array:\n");
    printArray(arr, n);

    sort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}