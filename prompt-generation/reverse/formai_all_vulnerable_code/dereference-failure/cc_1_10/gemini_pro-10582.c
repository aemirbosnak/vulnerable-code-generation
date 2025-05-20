//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Function to create buckets
int** createBuckets(int n) {
    int** buckets = malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        buckets[i] = malloc(sizeof(int) * n);
    }
    return buckets;
}

// Function to insert elements into buckets
void insertIntoBuckets(int** buckets, int* arr, int n, int numBuckets) {
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / numBuckets;
        buckets[bucketIndex][i] = arr[i];
    }
}

// Function to sort elements in buckets
void sortBuckets(int** buckets, int n, int numBuckets) {
    for (int i = 0; i < numBuckets; i++) {
        int bucketSize = n / numBuckets;
        for (int j = 0; j < bucketSize; j++) {
            for (int k = j + 1; k < bucketSize; k++) {
                if (buckets[i][j] > buckets[i][k]) {
                    int temp = buckets[i][j];
                    buckets[i][j] = buckets[i][k];
                    buckets[i][k] = temp;
                }
            }
        }
    }
}

// Function to concatenate buckets into a single array
int* concatenateBuckets(int** buckets, int n, int numBuckets) {
    int* sortedArray = malloc(sizeof(int) * n);
    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        int bucketSize = n / numBuckets;
        for (int j = 0; j < bucketSize; j++) {
            sortedArray[index++] = buckets[i][j];
        }
    }
    return sortedArray;
}

// Function to perform bucket sort
int* bucketSort(int* arr, int n) {
    int numBuckets = n;
    int** buckets = createBuckets(numBuckets);
    insertIntoBuckets(buckets, arr, n, numBuckets);
    sortBuckets(buckets, n, numBuckets);
    return concatenateBuckets(buckets, n, numBuckets);
}

// Function to print an array
void printArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Bucket sort example
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array:\n");
    printArray(arr, n);

    int* sortedArray = bucketSort(arr, n);

    printf("Sorted array:\n");
    printArray(sortedArray, n);

    return 0;
}