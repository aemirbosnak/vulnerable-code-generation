//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

// Function to find the maximum element in the array
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Function to perform Bucket Sort
void bucketSort(int arr[], int n) {
    // Create n empty buckets
    int buckets[n];
    for (int i = 0; i < n; i++) {
        buckets[i] = 0;
    }

    // Find the maximum element in the array
    int max = findMax(arr, n);

    // Distribute the elements into the buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (arr[i] * n) / max;
        buckets[bucketIndex]++;
    }

    // Sort the elements in each bucket
    for (int i = 0; i < n; i++) {
        if (buckets[i] > 0) {
            for (int j = 0; j < buckets[i]; j++) {
                printf("%d ", i);
            }
        }
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Get the size of the array
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Get the elements of the array
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the original array
    printf("Original array: ");
    printArray(arr, n);

    // Perform Bucket Sort
    bucketSort(arr, n);

    // Print the sorted array
    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}