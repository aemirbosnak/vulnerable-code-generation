//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUCKETS 100
#define MAX_ELEMENTS 1000

// Function to print the elements in the bucket
void print_bucket(int* bucket, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", bucket[i]);
    }
    printf("\n");
}

// Function to perform bucket sort
void bucket_sort(int* arr, int n) {
    int* buckets = (int*)malloc(MAX_BUCKETS * sizeof(int));
    int* sorted_arr = (int*)malloc(n * sizeof(int));
    int* tmp_arr = (int*)malloc(n * sizeof(int));

    // Initialize the buckets
    for (int i = 0; i < MAX_BUCKETS; i++) {
        buckets[i] = 0;
    }

    // Count the number of elements in each bucket
    for (int i = 0; i < n; i++) {
        int bucket_index = arr[i] / MAX_ELEMENTS;
        buckets[bucket_index]++;
    }

    // Copy the elements to the temporary array
    for (int i = 0; i < n; i++) {
        int bucket_index = arr[i] / MAX_ELEMENTS;
        tmp_arr[i] = arr[i];
    }

    // Sort the temporary array
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (tmp_arr[j] < tmp_arr[i]) {
                int temp = tmp_arr[j];
                tmp_arr[j] = tmp_arr[i];
                tmp_arr[i] = temp;
            }
        }
    }

    // Copy the sorted elements to the final array
    for (int i = 0; i < n; i++) {
        int bucket_index = tmp_arr[i] / MAX_ELEMENTS;
        sorted_arr[i] = tmp_arr[i];
    }

    // Print the final array
    printf("Sorted array: ");
    print_bucket(sorted_arr, n);

    // Free the memory
    free(tmp_arr);
    free(sorted_arr);
    free(buckets);
}

int main() {
    int arr[] = {9, 3, 5, 2, 8, 1, 7, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucket_sort(arr, n);

    return 0;
}