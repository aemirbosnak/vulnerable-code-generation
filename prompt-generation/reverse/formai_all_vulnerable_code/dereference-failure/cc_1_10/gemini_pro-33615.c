//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: protected
#include <stdlib.h>
#include <stdio.h>

// Create a bucket of size n
int *createBucket(int n) {
    int *bucket = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        bucket[i] = 0;
    }
    return bucket;
}

// Insert an element into a bucket
void insertIntoBucket(int *bucket, int n, int element) {
    bucket[element]++;
}

// Sort the elements in a bucket
void sortBucket(int *bucket, int n) {
    int sorted[n];
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (bucket[i] > 0) {
            sorted[j++] = i;
            bucket[i]--;
        }
    }
    for (int i = 0; i < n; i++) {
        bucket[i] = sorted[i];
    }
}

// Bucket sort function
void bucketSort(int *array, int n) {
    // Create an array of buckets
    int **buckets = malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        buckets[i] = createBucket(n);
    }

    // Insert the elements into the buckets
    for (int i = 0; i < n; i++) {
        insertIntoBucket(buckets[array[i]], n, array[i]);
    }

    // Sort the elements in each bucket
    for (int i = 0; i < n; i++) {
        sortBucket(buckets[i], n);
    }

    // Concatenate the sorted buckets into the output array
    int j = 0;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            if (buckets[i][k] != 0) {
                array[j++] = buckets[i][k];
            }
        }
    }

    // Free the memory allocated for the buckets
    for (int i = 0; i < n; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

// Print an array
void printArray(int *array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Main function
int main() {
    // Create an array of unsorted numbers
    int array[] = {4, 2, 8, 5, 1, 9, 3, 7, 6};
    int n = sizeof(array) / sizeof(array[0]);

    // Sort the array using bucket sort
    bucketSort(array, n);

    // Print the sorted array
    printArray(array, n);

    return 0;
}