//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to sort an array of integers using quicksort
void quicksort(int arr[], int low, int high) {
    int pivot, i, j, temp;

    // Choose a pivot element
    pivot = arr[low];

    // Partition the array into two subarrays: elements less than pivot and elements greater than pivot
    for (i = low + 1; i <= high; i++) {
        if (arr[i] < pivot) {
            // Elements less than pivot go here
            j = i;
            while (j < high && arr[j] < pivot) {
                j++;
            }
            // Swap elements less than pivot with elements greater than pivot
            for (int k = low; k <= j - 1; k++) {
                temp = arr[k];
                arr[k] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Recursively sort the two subarrays
    if (low < j) {
        quicksort(arr, low, j);
    }
    if (j < high) {
        quicksort(arr, j, high);
    }
}

int main() {
    int arr[5] = {4, 2, 7, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Start the timer
    clock_t start = clock();

    // Sort the array
    quicksort(arr, 0, n - 1);

    // Stop the timer and print the result
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Sorting took %f seconds\n", time_taken);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}