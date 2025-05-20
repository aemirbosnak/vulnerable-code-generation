//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int array[], int n) {
    int max_val = array[0];
    int min_val = array[0];
    int i, j, k;

    // Find the minimum and maximum element in the array
    for (i = 1; i < n; i++) {
        if (array[i] > max_val) {
            max_val = array[i];
        }
        if (array[i] < min_val) {
            min_val = array[i];
        }
    }

    // Find the range of a single bucket
    int bucket_range = (max_val - min_val) / n + 1;

    // Create n buckets using dynamic memory allocation
    int** buckets = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++) {
        buckets[i] = (int*)malloc(bucket_range * sizeof(int));
    }

    // Initialize all the buckets
    for (i = 0; i < n; i++) {
        for (j = 0; j < bucket_range; j++) {
            buckets[i][j] = 0;
        }
    }

    // Insert the elements into the appropriate bucket
    for (i = 0; i < n; i++) {
        int bucket_index = (array[i] - min_val) / bucket_range;
        if (bucket_index >= n) {
            bucket_index = n - 1;
        }
        buckets[bucket_index][array[i] % bucket_range] = array[i];
    }

    // Sort the elements in each bucket using any sorting algorithm (here I use Insertion Sort)
    for (i = 0; i < n; i++) {
        for (j = 0; j < bucket_range; j++) {
            int* bucket = buckets[i];
            for (k = 0; k < j; k++) {
                if (bucket[k] > bucket[j]) {
                    int temp = bucket[k];
                    bucket[k] = bucket[j];
                    bucket[j] = temp;
                }
            }
        }
    }

    // Copy the sorted elements back into the original array
    int index = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < bucket_range; j++) {
            if (buckets[i][j] != 0) {
                array[index++] = buckets[i][j];
            }
        }
    }

    // Free the memory allocated for the buckets
    for (i = 0; i < n; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

int main() {
    int array[] = { 5, 2, 8, 4, 6, 5, 3 };
    int n = sizeof(array) / sizeof(array[0]);

    printf("Unsorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    bucketSort(array, n);

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}