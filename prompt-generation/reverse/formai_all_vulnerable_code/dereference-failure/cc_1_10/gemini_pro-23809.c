//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Create a bucket of size n
int *create_bucket(int n) {
    int *bucket = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        bucket[i] = 0;
    }
    return bucket;
}

// Insert an element into a bucket
void insert_into_bucket(int *bucket, int n, int element) {
    bucket[element]++;
}

// Sort an array using bucket sort
void bucket_sort(int *arr, int n) {
    // Create a bucket for each element in the array
    int max_element = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_element) {
            max_element = arr[i];
        }
    }
    int *bucket = create_bucket(max_element + 1);

    // Insert each element into its corresponding bucket
    for (int i = 0; i < n; i++) {
        insert_into_bucket(bucket, max_element + 1, arr[i]);
    }

    // Sort the elements in each bucket
    for (int i = 0; i <= max_element; i++) {
        while (bucket[i] > 0) {
            printf("%d ", i);
            bucket[i]--;
        }
    }

    // Free the memory allocated for the bucket
    free(bucket);
}

// Test the bucket sort function
int main() {
    int arr[] = {3, 1, 4, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucket_sort(arr, n);

    return 0;
}