//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Function to perform Bucket Sort
void bucketSort(int *arr, int size) {
    int *temp; // Temporary array to store elements

    // Calculate the number of buckets required
    int buckets = (size / 10) + 1;
    int max = 0, min = 100;

    // Create an array to store the elements
    int arrSize = 100;
    int *arr1 = (int*)malloc(arrSize * sizeof(int));

    // Copy the elements of the input array into the temporary array
    for (int i = 0; i < size; i++) {
        arr1[i] = arr[i];
    }

    // Start sorting the elements
    while (arrSize < size) {
        // Allocate memory for a new array
        arrSize *= 2;
        temp = (int*)realloc(arr1, arrSize * sizeof(int));

        // Initialize the variables to keep track of the number of elements in the current bucket
        int size = 0, n = 0;

        // Iterate over each element in the current array
        for (int i = 0; i < size; i++) {
            n += arr1[i];
        }

        // Iterate over the current bucket
        for (int j = 0; j < n; j++) {
            size += 1;
            temp[j] = arr1[j];
        }

        // If the number of elements in the current bucket is greater than 1
        if (n > 1) {
            // Calculate the new size of the bucket and the size of the current bucket
            int newSize = n / 2;
            int size1 = n * 2;

            // Iterate over the current bucket
            for (int k = 0; k < n; k++) {
                // Add the current element to the new array
                temp[k + newSize] = arr1[k];

                // If the sum is not equal to 0, subtract the current element from the sum and decrement n by 1
                if (n!= 0) {
                    n -= arr1[k];
                    temp[k] = 0;
                }
            }

            // Free the memory of the current array
            free(arr1);

            // Copy the elements of the new array into the temporary array
            for (int l = 0; l < newSize; l++) {
                arr1[l] = temp[l];
            }
        }
    }

    // Print the sorted array
    printf("Sorted Array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr1[i]);
    }
}

// Function to print the array
void printArray(int *arr, int size) {
    printf("Array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

// Function to get the maximum element in the array
int getMax(int *arr, int size) {
    int max = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to get the minimum element in the array
int getMin(int *arr, int size) {
    int min = 100;
    for (int i = 0; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int main() {
    // Create an array with 10 elements
    int arr[] = {2, 5, 1, 9, 3, 6, 7, 4, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Print the original array
    printf("Original Array:\n");
    printArray(arr, size);

    // Call the bucketSort function
    bucketSort(arr, size);

    // Print the sorted array
    printf("\nSorted Array:\n");
    printArray(arr, size);

    // Print the maximum and minimum elements in the array
    int max = getMax(arr, size);
    int min = getMin(arr, size);
    printf("Maximum Element: %d\n", max);
    printf("Minimum Element: %d\n", min);

    return 0;
}