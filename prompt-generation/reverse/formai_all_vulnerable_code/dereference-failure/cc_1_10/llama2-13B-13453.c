//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort an array of integers
void sort(int arr[], int low, int high) {
    // Base case: If the length of the array is 1 or less, return
    if (low >= high) return;

    // Partition the array into two halves
    int mid = (low + high) / 2;
    swap(arr[low], arr[mid]);

    // Recursively sort the two halves
    sort(arr, low, mid - 1);
    sort(arr, mid + 1, high);

    // Combine the two sorted halves
    swap(arr[low], arr[high]);
}

int main() {
    int arr[5] = { 8, 3, 6, 2, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Print the unsorted array
    printf("Before sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort the array
    sort(arr, 0, n - 1);

    // Print the sorted array
    printf("After sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}