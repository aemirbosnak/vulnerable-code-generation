//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void bucketSort(int[], int);
void insertionSort(int[], int);

// Function definition for bucketSort
void bucketSort(int arr[], int n) {
    // Create an array of size n and initialize each element to NULL
    int* bucket = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        bucket[i] = 0;
    }

    // Calculate the maximum value in the array
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    // Divide each element in the array by the maximum value and store it in the respective bucket
    for (int i = 0; i < n; i++) {
        bucket[(int) (((float) arr[i] / max_val) * (n - 1))] = arr[i];
    }

    // Sort each bucket using insertionSort
    for (int i = 0; i < n; i++) {
        insertionSort(bucket, n);
    }

    // Print the sorted array
    printf("\nBucket Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", bucket[i]);
    }

    // Free memory allocated to bucket
    free(bucket);
}

// Function definition for insertionSort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j - 1;
        }

        arr[j+1] = key;
    }
}

// Driver program
int main() {
    // Get input from user
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements separated by space: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array using bucketSort
    bucketSort(arr, n);

    // Exit the program
    return 0;
}