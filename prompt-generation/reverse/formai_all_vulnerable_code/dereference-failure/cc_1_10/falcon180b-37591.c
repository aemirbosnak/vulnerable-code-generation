//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum element in an array
int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform bucket sort
void bucketSort(int arr[], int size) {
    int bucketCount = findMax(arr, size) + 1;
    int *buckets = (int *) malloc(bucketCount * sizeof(int));
    int *temp = (int *) malloc(size * sizeof(int));

    // Initialize all buckets to empty
    for (int i = 0; i < bucketCount; i++) {
        buckets[i] = -1;
    }

    // Place each element in its corresponding bucket
    for (int i = 0; i < size; i++) {
        int index = arr[i] / 10;
        if (buckets[index] == -1) {
            buckets[index] = i;
        } else {
            temp[buckets[index]] = arr[i];
            buckets[index] = i;
        }
    }

    // Copy elements from buckets back to original array
    for (int i = 0; i < size; i++) {
        arr[i] = temp[i];
    }

    // Free memory
    free(temp);
    free(buckets);
}

int main() {
    int arr[] = { 56, 89, 12, 45, 67, 34, 23, 78, 90, 11 };
    int size = sizeof(arr) / sizeof(arr[0]);

    // Perform bucket sort
    bucketSort(arr, size);

    // Print sorted array
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}