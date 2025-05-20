//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Function to sort an array using bucket sort algorithm
void bucketSort(int arr[], int n) {
    int max = arr[0];
    int min = arr[0];

    // Find the maximum and minimum values in the array
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // Calculate the range and bucket size
    int range = max - min + 1;
    int bucketSize = range / n;

    // Create an array of empty buckets
    int buckets[n];
    for (int i = 0; i < n; i++) {
        buckets[i] = 0;
    }

    // Place each element into its corresponding bucket
    for (int i = 0; i < n; i++) {
        int bucketIdx = (arr[i] - min) / bucketSize;
        buckets[bucketIdx]++;
    }

    // Add the elements back into the sorted array
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i]; j++) {
            arr[index++] = min + i * bucketSize;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array using bucket sort algorithm
    bucketSort(arr, n);

    // Print the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}