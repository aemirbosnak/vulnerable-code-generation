//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to find the maximum element in the array
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
    int max = findMax(arr, size);
    int *buckets = (int *)malloc(MAX_SIZE * sizeof(int));
    int i = 0;

    // Create empty buckets
    for (int j = 0; j < MAX_SIZE; j++) {
        buckets[j] = 0;
    }

    // Place each element in the appropriate bucket
    for (int k = 0; k < size; k++) {
        int index = arr[k] * MAX_SIZE / max;
        buckets[index]++;
    }

    // Place the elements back into the original array
    for (int l = 0; l < size; l++) {
        int index = arr[l] * MAX_SIZE / max;
        buckets[index]--;
        arr[i] = l;
        i++;
    }

    free(buckets);
}

// Function to print the sorted array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to test the bucket sort implementation
int main() {
    int arr[] = { 3, 8, 2, 5, 1, 4, 7, 6 };
    int size = sizeof(arr) / sizeof(arr[0]);

    // Perform bucket sort
    bucketSort(arr, size);

    // Print the sorted array
    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}