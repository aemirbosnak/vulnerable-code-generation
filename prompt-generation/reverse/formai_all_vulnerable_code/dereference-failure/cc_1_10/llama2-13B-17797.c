//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort the array using quicksort
void sort(int arr[], int low, int high) {
    int i, j, pivot;

    // If the length of the array is 1 or less, return
    if (low >= high) return;

    // Partition the array into two halves
    pivot = partition(arr, low, high);

    // Recursively sort the two halves
    sort(arr, low, pivot - 1);
    sort(arr, pivot + 1, high);
}

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    // Move elements less than the pivot to the left
    while (i <= j) {
        if (arr[i] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    // Move the pivot to the right position
    swap(arr[low], arr[j]);

    return j + 1;
}

int main() {
    int arr[5] = { 3, 2, 1, 6, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Display the original array
    printf("Before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort the array using quicksort
    sort(arr, 0, n - 1);

    // Display the sorted array
    printf("After sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}