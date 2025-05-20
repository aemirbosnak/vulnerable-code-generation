//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// Defining a function to sort the array using bucket sort
void bucketSort(int arr[], int n) {
    // Creating buckets
    int i, j, k, min_elem, num_of_buckets;
    int *bucket;

    // Finding the minimum element in the array
    min_elem = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] < min_elem) {
            min_elem = arr[i];
        }
    }

    // Finding the number of buckets
    num_of_buckets = min_elem + 1;

    // Creating buckets
    bucket = (int*)malloc(num_of_buckets * sizeof(int));
    for (i = 0; i < num_of_buckets; i++) {
        bucket[i] = 0;
    }

    // Sorting elements into the buckets
    for (i = 0; i < n; i++) {
        j = arr[i] - min_elem;
        bucket[j]++;
    }

    // Reversing the array
    for (i = 0; i < n; i++) {
        j = arr[i] - min_elem;
        arr[i] = bucket[j];
    }

    // Freeing the memory
    free(bucket);
}

int main() {
    int arr[] = {64, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;

    // Printing the original array
    printf("Original Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sorting the array using bucket sort
    bucketSort(arr, n);

    // Printing the sorted array
    printf("Sorted Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}