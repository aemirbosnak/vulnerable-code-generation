//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define MIN_VALUE -100

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to get the index of the bucket for a given element
int getBucketIndex(int arr[], int element, int numBuckets) {
    int index = element / numBuckets;
    if (element % numBuckets!= 0) {
        index++;
    }
    return index;
}

// Function to perform bucket sort
void bucketSort(int arr[], int numElements, int numBuckets) {
    int i, j, k;
    int *buckets[numBuckets];
    for (i = 0; i < numBuckets; i++) {
        buckets[i] = (int *)malloc(sizeof(int) * numElements);
    }

    // Distribute elements into buckets
    for (i = 0; i < numElements; i++) {
        int index = getBucketIndex(arr, arr[i], numBuckets);
        buckets[index][i] = arr[i];
    }

    // Sort each bucket using insertion sort
    for (i = 0; i < numBuckets; i++) {
        for (j = 0; j < numElements - 1; j++) {
            for (k = j + 1; k < numElements; k++) {
                if (buckets[i][j] > buckets[i][k]) {
                    swap(&buckets[i][j], &buckets[i][k]);
                }
            }
        }
    }

    // Merge sorted buckets into original array
    for (i = 0; i < numElements; i++) {
        arr[i] = buckets[getBucketIndex(arr, arr[i], numBuckets)][i];
    }

    // Free memory allocated for buckets
    for (i = 0; i < numBuckets; i++) {
        free(buckets[i]);
    }
}

int main() {
    int arr[] = { -5, 0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100 };
    int numElements = sizeof(arr) / sizeof(arr[0]);
    int numBuckets = 10;

    // Perform bucket sort
    bucketSort(arr, numElements, numBuckets);

    // Print sorted array
    printf("Sorted array: ");
    for (int i = 0; i < numElements; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}