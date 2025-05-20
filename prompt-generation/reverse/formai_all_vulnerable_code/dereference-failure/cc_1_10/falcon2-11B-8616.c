//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Bucket Sort function
void bucketSort(int arr[], int n) {
    // Calculate the number of buckets
    int numBuckets = (n + 1);
    
    // Initialize an array of empty buckets
    int *buckets = (int *) malloc(sizeof(int) * numBuckets);
    
    // Iterate over the array elements
    for (int i = 0; i < n; i++) {
        // Calculate the bucket index for the current element
        int bucketIndex = arr[i] / numBuckets;
        
        // If the bucket is empty, create a new bucket
        if (buckets[bucketIndex] == 0) {
            buckets[bucketIndex] = 1;
        }
        
        // Increment the count of elements in the bucket
        buckets[bucketIndex]++;
    }
    
    // Iterate over the buckets and sort them
    for (int i = 0; i < numBuckets; i++) {
        // If the bucket is not empty, sort its elements
        if (buckets[i] > 0) {
            // Sort the elements using a selection sort algorithm
            int temp = buckets[i];
            buckets[i] = arr[i];
            arr[i] = temp;
        }
    }
    
    // Free the memory allocated for buckets
    free(buckets);
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Initialize an array of integers
    int arr[] = {12, 5, 8, 1, 9, 3, 7, 4, 6, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Call the bucketSort function to sort the array
    bucketSort(arr, n);
    
    // Print the sorted array
    printf("Sorted array: ");
    printArray(arr, n);
    
    return 0;
}