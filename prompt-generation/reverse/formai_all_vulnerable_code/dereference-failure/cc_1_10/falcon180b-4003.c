//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_BUCKETS 1000
#define MAX_RANGE 1000

// Function to find the maximum element in the array
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform the bucket sort
void bucketSort(int arr[], int n) {
    // Find the maximum element in the array
    int max = findMax(arr, n);

    // Create an array of empty buckets
    int buckets[MAX_BUCKETS] = {0};

    // Determine the range of each bucket
    int range = max / MAX_BUCKETS;

    // Place each element in the correct bucket
    for (int i = 0; i < n; i++) {
        int bucket = arr[i] / range;
        buckets[bucket]++;
    }

    // Combine the elements from each bucket back into the original array
    int index = 0;
    for (int i = 0; i < MAX_BUCKETS; i++) {
        for (int j = 0; j < buckets[i]; j++) {
            arr[index++] = i * range + range / 2;
        }
    }
}

// Main function
int main() {
    int n;

    // Get the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));

    // Get the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array using bucket sort
    bucketSort(arr, n);

    // Print the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}