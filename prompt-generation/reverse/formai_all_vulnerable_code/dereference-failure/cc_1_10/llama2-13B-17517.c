//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort an array of integers
void sort(int arr[], int low, int high) {
    // Base case: if the length of the array is 1 or less, return
    if (low >= high) return;

    // Partition the array into two parts: left and right
    int pivot = partition(arr, low, high);

    // Recursively sort the left and right parts
    sort(arr, low, pivot - 1);
    sort(arr, pivot + 1, high);
}

// Function to partition the array around a pivot element
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high - 1;

    // Move elements less than the pivot to the left
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] >= pivot) j--;

        // If i and j are not equal, there is a gap
        if (i != j) {
            swap(arr[i], arr[j]);
        }
    }

    // Move the pivot element to its final position
    swap(arr[low], arr[j]);

    return j + 1;
}

int main() {
    int arr[5] = { 4, 2, 7, 1, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sort the array in ascending order
    sort(arr, 0, n - 1);

    // Print the sorted array
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}