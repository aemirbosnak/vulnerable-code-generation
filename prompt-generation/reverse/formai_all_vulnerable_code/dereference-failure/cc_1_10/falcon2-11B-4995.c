//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Define a struct to store the values to be sorted
typedef struct {
    int value;
    int bucket;
} Bucket;

// Define a function to sort the array using bucket sort
void bucketSort(int arr[], int n) {
    // Create an array of buckets with a size equal to the maximum value in the array
    Bucket *buckets = (Bucket *)malloc(sizeof(Bucket) * arr[n - 1]);

    // Initialize the array of buckets to zero
    for (int i = 0; i < n; i++) {
        buckets[i].value = arr[i];
        buckets[i].bucket = i;
    }

    // Sort the buckets array using a bubble sort algorithm
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (buckets[j].value > buckets[j + 1].value) {
                // Swap the values of the two elements in the buckets array
                int temp = buckets[j].value;
                buckets[j].value = buckets[j + 1].value;
                buckets[j + 1].value = temp;
            }
        }
    }

    // Rebuild the sorted array from the sorted buckets array
    for (int i = 0; i < n; i++) {
        arr[i] = buckets[i].value;
    }

    // Free the memory allocated for the buckets array
    free(buckets);
}

int main() {
    // Create an array of integers to be sorted
    int arr[] = {4, 7, 1, 9, 2, 5, 3, 8, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sort the array using bucket sort
    bucketSort(arr, n);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Free the memory allocated for the array
    free(arr);

    return 0;
}