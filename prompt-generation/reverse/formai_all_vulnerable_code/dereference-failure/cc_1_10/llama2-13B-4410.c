//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort an array of integers using quicksort
void sort_array(int arr[], int low, int high) {
    int i, j, pivot, temp;

    // If the length of the array is 1 or less, return
    if (low >= high) return;

    // Partition the array into two subarrays: [low, pivot] and [pivot, high]
    pivot = partition(arr, low, high);

    // Recursively sort the two subarrays
    sort_array(arr, low, pivot - 1);
    sort_array(arr, pivot + 1, high);
}

// Function to partition the array around a pivot element
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i, j;

    // Move elements less than the pivot to the left
    for (i = low + 1; i <= high; i++) {
        if (arr[i] < pivot) {
            swap(arr[i], arr[low]);
            low++;
        }
    }

    // Move elements greater than the pivot to the right
    for (j = high - 1; j > low; j--) {
        if (arr[j] > pivot) {
            swap(arr[j], arr[high]);
        }
    }

    return low;
}

int main() {
    int arr[5] = { 3, 6, 1, 8, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sort the array using quicksort
    sort_array(arr, 0, n - 1);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}