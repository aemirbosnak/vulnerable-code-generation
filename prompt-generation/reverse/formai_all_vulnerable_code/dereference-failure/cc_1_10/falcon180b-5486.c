//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

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
    int max = findMax(arr, size);
    int numBuckets = max / 10 + 1;
    int *buckets[numBuckets];

    // Initialize all buckets to empty
    for (int i = 0; i < numBuckets; i++) {
        buckets[i] = NULL;
    }

    // Place each element into its corresponding bucket
    for (int i = 0; i < size; i++) {
        int bucketIndex = arr[i] / 10;
        if (buckets[bucketIndex] == NULL) {
            buckets[bucketIndex] = malloc(MAX_SIZE * sizeof(int));
        }
        int *bucket = buckets[bucketIndex];
        int j = 0;
        while (j < MAX_SIZE && bucket[j]!= -1) {
            j++;
        }
        bucket[j] = arr[i];
    }

    // Concatenate all the sorted buckets into a single sorted array
    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        int *bucket = buckets[i];
        if (bucket!= NULL) {
            for (int j = 0; j < MAX_SIZE; j++) {
                if (bucket[j]!= -1) {
                    arr[index++] = bucket[j];
                }
            }
        }
    }
}

int main() {
    int arr[] = { 5, 2, 8, 1, 7, 6, 3, 4 };
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    bucketSort(arr, size);

    printf("\nAfter sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}