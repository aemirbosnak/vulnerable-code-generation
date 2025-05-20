//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Create a bucket of size n
int* createBucket(int n) {
    int* bucket = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        bucket[i] = 0;
    }
    return bucket;
}

// Insert an element into a bucket
void insertIntoBucket(int* bucket, int element) {
    bucket[element]++;
}

// Sort the elements in a bucket
void sortBucket(int* bucket, int n) {
    int sortedIndex = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucket[i]; j++) {
            bucket[sortedIndex++] = i;
        }
    }
}

// Perform bucket sort on an array
void bucketSort(int* arr, int n) {
    // Create an array of buckets
    int** buckets = malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        buckets[i] = createBucket(n);
    }

    // Insert each element into a bucket
    for (int i = 0; i < n; i++) {
        insertIntoBucket(buckets[arr[i]], arr[i]);
    }

    // Sort the elements in each bucket
    for (int i = 0; i < n; i++) {
        sortBucket(buckets[i], n);
    }

    // Concatenate the sorted buckets into the original array
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[index++] = buckets[i][j];
        }
        free(buckets[i]);
    }
    free(buckets);
}

// Print an array
void printArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Create an array of unsorted integers
    int arr[] = {5, 3, 1, 7, 4, 1, 2, 8, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sort the array using bucket sort
    bucketSort(arr, n);

    // Print the sorted array
    printArray(arr, n);

    return 0;
}