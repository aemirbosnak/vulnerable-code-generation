//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int arr[], int n) {
    int max_val = arr[0];
    int min_val = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val)
            max_val = arr[i];
        if (arr[i] < min_val)
            min_val = arr[i];
    }

    int bucket_count = (max_val - min_val) / 5 + 1;

    // Create and initialize buckets
    int** buckets = malloc(bucket_count * sizeof(int*));
    for (int i = 0; i < bucket_count; i++) {
        buckets[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
            buckets[i][j] = 0;
    }

    // Place elements in buckets
    for (int i = 0; i < n; i++) {
        int bucket_index = (arr[i] - min_val) / 5;
        buckets[bucket_index][i] = arr[i];
    }

    // Sort buckets using insertion sort
    for (int i = 0; i < bucket_count; i++) {
        for (int j = 1; j < n; j++) {
            int k = j;
            while (k > 0 && buckets[i][k-1] > buckets[i][k]) {
                int temp = buckets[i][k];
                buckets[i][k] = buckets[i][k-1];
                buckets[i][k-1] = temp;
                k--;
            }
        }
    }

    // Place sorted elements in original array
    int index = 0;
    for (int i = 0; i < bucket_count; i++) {
        for (int j = 0; j < n; j++) {
            if (buckets[i][j] != 0) {
                arr[index] = buckets[i][j];
                index++;
            }
        }
    }

    // Free memory
    for (int i = 0; i < bucket_count; i++)
        free(buckets[i]);
    free(buckets);
}

int main() {
    int arr[] = {32, 14, 25, 70, 30, 37, 3, 38, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    bucket_sort(arr, n);

    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}