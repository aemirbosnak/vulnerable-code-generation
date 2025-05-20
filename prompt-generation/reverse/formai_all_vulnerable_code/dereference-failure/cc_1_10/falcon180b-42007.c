//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to find the largest element in the array
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
    int max = findMax(arr, n);
    int bucketSize = max / n;
    int* bucket[MAX_SIZE];

    // Create empty buckets
    for (int i = 0; i < n; i++) {
        bucket[i] = (int*) malloc(bucketSize * sizeof(int));
    }

    // Place elements in buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / bucketSize;
        int* temp = (int*) malloc(bucketSize * sizeof(int));
        int j = 0;
        while (j < bucketSize) {
            temp[j] = bucket[bucketIndex][j];
            j++;
        }
        bucket[bucketIndex][j] = arr[i];
        free(temp);
    }

    // Concatenate buckets back into original array
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketSize; j++) {
            arr[k++] = bucket[i][j];
        }
    }

    // Free memory used by buckets
    for (int i = 0; i < n; i++) {
        free(bucket[i]);
    }
}

int main() {
    int arr[] = { 3, 2, 1, 7, 8, 5, 4, 9, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Perform bucket sort
    bucketSort(arr, n);

    // Print sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}