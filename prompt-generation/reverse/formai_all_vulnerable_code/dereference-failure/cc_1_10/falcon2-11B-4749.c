//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Function to create an empty array of given size
void createArray(int* arr, int size) {
    arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }
}

// Function to perform bucket sort
void bucketSort(int* arr, int size) {
    // Create an array of empty buckets of size 10
    int* buckets = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        buckets[i] = 0;
    }

    // Iterate through the input array and place elements in their respective buckets
    int* curr = arr;
    for (int i = 0; i < size; i++) {
        int bucket = curr[i] / 10;
        curr[i] %= 10;
        if (buckets[bucket] == 0) {
            buckets[bucket] = 1;
        } else {
            buckets[bucket]++;
        }
    }

    // Merge the buckets back into the input array
    int* sortedArr = arr;
    curr = buckets;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < buckets[i]; j++) {
            sortedArr[j] = curr[i];
        }
    }

    // Free the memory allocated for the buckets
    free(buckets);
}

// Function to print an array
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Create an array of size 100
    int* arr = (int*)malloc(100 * sizeof(int));
    createArray(arr, 100);

    // Randomly populate the array with integers
    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        arr[i] = rand() % 100;
    }

    // Perform bucket sort on the array
    bucketSort(arr, 100);

    // Print the sorted array
    printArray(arr, 100);

    // Free the memory allocated for the array
    free(arr);

    return 0;
}