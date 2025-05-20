//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort an array of integers
void sort(int arr[], int low, int high) {
    int pivot, i, j, temp;

    // Choose the middle element as the pivot
    pivot = arr[low];

    // Partition the array into two parts: less than pivot and greater than pivot
    for (i = low + 1; i <= high; i++) {
        if (arr[i] < pivot) {
            // Find the right position for the element
            j = i - 1;
            while (j >= low && arr[j] >= pivot) {
                j--;
            }
            swap(arr[j], arr[i]);
        }
    }

    // Recursively sort the left and right parts
    if (low < j) {
        sort(arr, low, j);
    }
    if (i < high) {
        sort(arr, i, high);
    }
}

int main() {
    int arr[5] = {4, 2, 7, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sort the array
    sort(arr, 0, n - 1);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}