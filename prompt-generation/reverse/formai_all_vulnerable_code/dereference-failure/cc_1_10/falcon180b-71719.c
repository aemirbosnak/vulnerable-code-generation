//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to find the index of an element in a bucket
int findIndex(int* bucket, int size, int element) {
    for (int i = 0; i < size; i++) {
        if (bucket[i] == element) {
            return i;
        }
    }
    return -1;
}

// Function to print a bucket
void printBucket(int* bucket, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", bucket[i]);
    }
    printf("\n");
}

// Function to perform bucket sort
void bucketSort(int* arr, int size) {
    int max = arr[0];
    int min = arr[0];

    // Find the maximum and minimum elements in the array
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // Calculate the range of the elements
    int range = max - min + 1;

    // Create an array of buckets
    int* bucket = (int*) malloc(range * sizeof(int));

    // Initialize all the buckets to empty
    for (int i = 0; i < range; i++) {
        bucket[i] = -1;
    }

    // Place the elements in the appropriate buckets
    for (int i = 0; i < size; i++) {
        int index = (arr[i] - min) / (max - min) * range;
        if (bucket[index] == -1) {
            bucket[index] = i;
        }
        else {
            int j = findIndex(bucket, range, arr[i]);
            swap(&bucket[j], &bucket[index]);
        }
    }

    // Copy the elements back to the original array
    for (int i = 0; i < size; i++) {
        int index = findIndex(bucket, range, arr[i]);
        arr[i] = bucket[index];
    }

    // Free the memory used by the bucket array
    free(bucket);
}

// Main function
int main() {
    int arr[] = { 23, 45, 12, 67, 89, 34, 56, 78 };
    int size = sizeof(arr) / sizeof(arr[0]);

    // Print the original array
    printf("Original Array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort the array using bucket sort
    bucketSort(arr, size);

    // Print the sorted array
    printf("Sorted Array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}