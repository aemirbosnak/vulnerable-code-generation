//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: lively
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
    int mid = (low + high) / 2;

    // Base case: If the array has only one element, return
    if (low == high) return;

    // Partition the array into two subarrays
    int i, j;
    for (i = low; i < high; i++) {
        if (arr[i] <= arr[mid]) {
            j = i + 1;
            while (j <= high && arr[j] > arr[mid]) j++;
            swap(arr[i], arr[j]);
        }
    }

    // Recursively sort the two subarrays
    sort(arr, low, j - 1);
    sort(arr, j + 1, high);
}

int main() {
    int arr[MAX_LENGTH] = {42, 21, 34, 19, 76, 53, 23, 17, 91};
    int low = 0;
    int high = sizeof(arr) / sizeof(arr[0]) - 1;

    // Sort the array
    sort(arr, low, high);

    // Print the sorted array
    printf("Sorted array: \n");
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}