//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Define a function to sort an array of integers
void sort(int arr[], int low, int high) {
    // Base case: if the length of the array is 1 or less, return
    if (low >= high) return;

    // Partition the array into two parts: low and high
    int pivot = partition(arr, low, high);

    // Recursively sort the low and high parts
    sort(arr, low, pivot - 1);
    sort(arr, pivot + 1, high);
}

// Define a function to partition the array around a pivot element
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choose the last element as the pivot
    int i = low - 1;  // Index of the smallest element greater than the pivot

    // Swap elements less than the pivot to the left of the pivot
    for (int j = low; j <= high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // Swap the pivot element with the last element of the left partition
    swap(arr[i + 1], arr[high]);

    return i + 1;  // Return the index of the last element of the left partition
}

int main() {
    int arr[5] = { 3, 6, 1, 8, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sort the array in ascending order
    sort(arr, 0, n - 1);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}