//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: optimized
#include<stdio.h>
#include<stdlib.h>

/*
 * Function to implement Bucket Sort
 * This function takes an array of integers and number of elements in the array as arguments
 * and sorts the elements in ascending order.
 */
void bucketSort(int arr[], int n) {
    // Find the maximum element in the array
    int max = arr[n - 1];
    int bucket_size = max + 1;
    int *buckets = (int *)malloc(bucket_size * sizeof(int));

    // Initialize all buckets to be empty
    for (int i = 0; i < bucket_size; i++) {
        buckets[i] = 0;
    }

    // Insert elements into respective buckets
    for (int i = 0; i < n; i++) {
        int element = arr[i];
        buckets[element]++;
    }

    // Merge the buckets and sort the array
    for (int i = 1; i < bucket_size; i++) {
        buckets[i] += buckets[i - 1];
    }

    int *temp = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < bucket_size; i++) {
        for (int j = 1; j < buckets[i]; j++) {
            temp[j - 1] = i;
        }
        for (int j = 0; j < buckets[i]; j++) {
            arr[j] = temp[j];
        }
    }

    // Free the allocated memory
    free(buckets);
    free(temp);
}

int main() {
    int arr[] = {5, 2, 9, 1, 3, 8, 6, 7, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucketSort(arr, n);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}