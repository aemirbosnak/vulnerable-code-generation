//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of elements in the array
#define MAX_SIZE 100

// Function to create buckets
int* createBuckets(int* arr, int n) {
    // Create an array of buckets
    int* buckets[MAX_SIZE];

    // Initialize each bucket to NULL
    for (int i = 0; i < MAX_SIZE; i++) {
        buckets[i] = NULL;
    }

    // Iterate over the elements in the array
    for (int i = 0; i < n; i++) {
        // Get the current element
        int element = arr[i];

        // Create a new bucket if the bucket for the current element does not exist
        if (buckets[element] == NULL) {
            buckets[element] = (int*)malloc(sizeof(int));
            *buckets[element] = 0;
        }

        // Increment the count of the current element in the bucket
        (*buckets[element])++;
    }

    return buckets;
}

// Function to sort the elements in the array using bucket sort
void bucketSort(int* arr, int n) {
    // Create an array of buckets
    int** buckets = createBuckets(arr, n);

    // Iterate over the buckets
    for (int i = 0; i < MAX_SIZE; i++) {
        // If the bucket is not empty
        if (buckets[i] != NULL) {
            // Get the count of the current element in the bucket
            int count = *buckets[i];

            // Iterate over the count of the current element
            for (int j = 0; j < count; j++) {
                // Add the current element to the array
                *arr++ = i;
            }

            // Free the memory allocated for the bucket
            free(buckets[i]);
        }
    }
}

// Function to print the array
void printArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Get the size of the array
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Create an array of integers
    int arr[n];

    // Get the elements of the array
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array using bucket sort
    bucketSort(arr, n);

    // Print the sorted array
    printf("The sorted array is: ");
    printArray(arr, n);

    return 0;
}