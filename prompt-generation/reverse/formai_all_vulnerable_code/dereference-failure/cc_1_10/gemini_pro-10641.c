//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to insert an element into the bucket
void insertIntoBucket(int *bucket, int size, int element) {
    // Find the correct bucket for the element
    int i;
    for (i = 0; i < size; i++) {
        if (bucket[i] == -1 || bucket[i] > element) {
            break;
        }
    }

    // Insert the element into the bucket
    for (int j = size - 1; j > i; j--) {
        bucket[j] = bucket[j - 1];
    }
    bucket[i] = element;
}

// Function to sort the elements in the bucket
void sortBucket(int *bucket, int size) {
    // Perform insertion sort on the bucket
    for (int i = 1; i < size; i++) {
        int key = bucket[i];
        int j = i - 1;

        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

// Function to perform bucket sort on the given array
void bucketSort(int *arr, int size) {
    // Create an array of buckets
    int **buckets = (int **)malloc(sizeof(int *) * size);

    // Initialize all the buckets to -1
    for (int i = 0; i < size; i++) {
        buckets[i] = (int *)malloc(sizeof(int) * MAX_SIZE);
        for (int j = 0; j < MAX_SIZE; j++) {
            buckets[i][j] = -1;
        }
    }

    // Distribute the elements into the buckets
    for (int i = 0; i < size; i++) {
        insertIntoBucket(buckets[arr[i]], MAX_SIZE, arr[i]);
    }

    // Sort the elements in each bucket
    for (int i = 0; i < size; i++) {
        sortBucket(buckets[i], MAX_SIZE);
    }

    // Concatenate the sorted buckets into the output array
    int index = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < MAX_SIZE && buckets[i][j] != -1; j++) {
            arr[index++] = buckets[i][j];
        }
        free(buckets[i]);
    }
    free(buckets);
}

// Function to print the elements of the array
void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Create an array of unsorted integers
    int arr[] = {4, 2, 1, 3, 5, 3, 1, 2, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Sort the array using bucket sort
    bucketSort(arr, size);

    // Print the sorted array
    printArray(arr, size);

    return 0;
}