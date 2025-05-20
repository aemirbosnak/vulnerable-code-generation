//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Function to perform bucket sort
void bucketSort(int arr[], int n)
{
    // Find maximum element in array to determine number of buckets
    int max_num = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_num) {
            max_num = arr[i];
        }
    }

    // Create n empty buckets
    int *buckets = calloc(n, sizeof(int));

    // Add elements to their respective buckets
    for (int i = 0; i < n; i++) {
        int bucket_index = (arr[i] * n) / (max_num + 1);
        buckets[bucket_index]++;
    }

    // Sort elements in each bucket using insertion sort
    for (int i = 0; i < n; i++) {
        int bucket_index = (arr[i] * n) / (max_num + 1);
        int j = bucket_index;

        while (j > 0 && arr[i] < arr[j-1]) {
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }

    // Concatenate sorted elements from each bucket
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i]; j++) {
            arr[index++] = (i * (max_num + 1)) / n;
        }
    }

    free(buckets);
}

// Main function
int main()
{
    int arr[] = {8, 2, 5, 1, 10, 4, 7, 3, 6, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Print original array
    printf("Original Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort array using bucket sort
    bucketSort(arr, n);

    // Print sorted array
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}