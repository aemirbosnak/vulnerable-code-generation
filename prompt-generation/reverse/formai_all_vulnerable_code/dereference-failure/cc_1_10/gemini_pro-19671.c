//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to find the maximum element in an array
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    // Create n empty buckets
    int buckets[n];
    for (int i = 0; i < n; i++) {
        buckets[i] = 0;
    }

    // Distribute elements into buckets
    int max = findMax(arr, n);
    int bucketSize = ceil((double)max / n);
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / bucketSize;
        buckets[bucketIndex]++;
    }

    // Sort elements in each bucket
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / bucketSize;
        int j = 0;
        while (buckets[bucketIndex] > 0) {
            if (arr[i] == bucketIndex * bucketSize + j) {
                buckets[bucketIndex]--;
                arr[i] = -1; // Mark element as sorted
                j++;
            } else {
                i++;
            }
        }
    }

    // Rearrange sorted elements in the original array
    int sortedIndex = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != -1) {
            arr[sortedIndex++] = arr[i];
        }
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Get the size of the array and its elements
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform bucket sort on the array
    bucketSort(arr, n);

    // Print the sorted array
    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}