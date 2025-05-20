//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to swap two elements
void swap(int *a, int *b) {
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

// Function to partition the array around a given element
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high - 1;

    // Swap elements less than the pivot to the left
    while (i <= j) {
        while (arr[i] <= pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
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
    int arr[MAX_LENGTH] = { 4, 2, 7, 1, 3 };
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