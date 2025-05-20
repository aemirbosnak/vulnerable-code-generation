//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Define a function to sort an array of integers
void sortArray(int arr[], int low, int high) {
    // Base case: if the length of the array is 1 or less, return
    if (low >= high) return;

    // Partition the array into two halves
    int pivot = partition(arr, low, high);

    // Recursively sort the two halves
    sortArray(arr, low, pivot - 1);
    sortArray(arr, pivot + 1, high);
}

// Define a function to partition the array around a given element
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    for (int j = low + 1; j <= high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[i - 1]);
    return i - 1;
}

// Main function
int main() {
    int arr[5] = { 8, 3, 6, 1, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sort the array using the quicksort algorithm
    sortArray(arr, 0, n - 1);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}