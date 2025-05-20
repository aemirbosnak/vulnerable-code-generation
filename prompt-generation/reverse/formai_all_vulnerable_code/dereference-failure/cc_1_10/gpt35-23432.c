//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent the bucket
struct bucket {
    int count;
    int* value;
};

// Define a function to print the array
void printArray(int arr[], int n) {
    printf("Array after sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Define the bucket sort function
void bucketSort(int arr[], int n) {
    // Define the number of buckets and the maximum value in array
    int numBuckets = 5;
    int maxValue = 100;

    // Create an array of numBuckets buckets
    struct bucket* buckets = (struct bucket*) malloc(numBuckets * sizeof(struct bucket));

    // Initialize each bucket's count to 0
    for (int i = 0; i < numBuckets; i++) {
        buckets[i].count = 0;
        buckets[i].value = (int*) malloc(n * sizeof(int));
    }

    // Calculate the size of each bucket
    int bucketSize = maxValue / numBuckets;

    // Place each element in the appropriate bucket
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / bucketSize;
        if (bucketIndex >= numBuckets) {
            bucketIndex = numBuckets - 1;
        }
        buckets[bucketIndex].value[buckets[bucketIndex].count++] = arr[i];
    }

    // Sort each bucket using insertion sort
    for (int i = 0; i < numBuckets; i++) {
        for (int j = 1; j < buckets[i].count; j++) {
            int temp = buckets[i].value[j];
            int k;
            for (k = j - 1; k >= 0 && buckets[i].value[k] > temp; k--) {
                buckets[i].value[k + 1] = buckets[i].value[k];
            }
            buckets[i].value[k + 1] = temp;
        }
    }

    // Concatenate the buckets back into the original array
    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        for (int j = 0; j < buckets[i].count; j++) {
            arr[index++] = buckets[i].value[j];
        }
    }

    // Free the memory allocated for the buckets
    for (int i = 0; i < numBuckets; i++) {
        free(buckets[i].value);
    }
    free(buckets);
}

// Define the main function to test the algorithm
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Perform bucket sort on the array
    bucketSort(arr, n);

    // Print the sorted array
    printArray(arr, n);

    return 0;
}