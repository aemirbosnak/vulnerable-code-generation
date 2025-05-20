//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Function to print the sorted array
void printArr(int arr[], int size) {
    printf("Sorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform Bucket Sort
void bucketSort(int arr[], int size) {
    // Find the maximum element in the array
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Create an array of buckets
    int *buckets = (int*) malloc(sizeof(int) * (max + 1));
    for (int i = 0; i < max + 1; i++) {
        buckets[i] = 0;
    }

    // Add the elements of the array to the buckets
    for (int i = 0; i < size; i++) {
        buckets[arr[i]]++;
    }
    
    // Iterate through the buckets and add the elements back to the array
    int index = 0;
    for (int i = 0; i < max+1; i++) {
        for (int j = 0; j < buckets[i]; j++) {
            arr[index++] = i;
        }
    }

    // Print the sorted array
    printArr(arr, size);

    // Free the memory allocated for the buckets array
    free(buckets);
}

// Main function to run the program
int main() {
    int arr[] = { 10, 22, 7, 33, 89, 78, 59, 15, 49 };
    int size = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, size);
    return 0;
}