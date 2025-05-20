//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of elements in the array
#define MAX_SIZE 100

// Define the maximum value of an element in the array
#define MAX_VALUE 100

// Function to create an empty bucket
int* createBucket() {
    int* bucket = (int*)malloc(sizeof(int) * MAX_VALUE);
    for (int i = 0; i < MAX_VALUE; i++) {
        bucket[i] = 0;
    }
    return bucket;
}

// Function to insert an element into a bucket
void insertIntoBucket(int* bucket, int element) {
    bucket[element]++;
}

// Function to sort the array using bucket sort
void bucketSort(int* array, int size) {
    // Create an array of buckets
    int** buckets = (int**)malloc(sizeof(int*) * MAX_VALUE);
    for (int i = 0; i < MAX_VALUE; i++) {
        buckets[i] = createBucket();
    }

    // Insert each element of the array into a bucket
    for (int i = 0; i < size; i++) {
        insertIntoBucket(buckets[array[i]], array[i]);
    }

    // Concatenate the buckets into a single sorted array
    int index = 0;
    for (int i = 0; i < MAX_VALUE; i++) {
        for (int j = 0; j < buckets[i][i]; j++) {
            array[index++] = i;
        }
    }

    // Free the memory allocated for the buckets
    for (int i = 0; i < MAX_VALUE; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

// Function to print the array
void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Main function
int main() {
    // Create an array of unsorted elements
    int array[] = {4, 2, 8, 5, 1, 9, 3, 7, 6};
    int size = sizeof(array) / sizeof(array[0]);

    // Sort the array using bucket sort
    bucketSort(array, size);

    // Print the sorted array
    printArray(array, size);

    return 0;
}