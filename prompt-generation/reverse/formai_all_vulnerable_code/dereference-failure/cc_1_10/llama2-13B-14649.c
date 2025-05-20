//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: lively
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
void quicksort(int arr[], int low, int high) {
    int i, j, pivot;

    // If the length of the array is 1 or less, return
    if (low >= high) return;

    // Choose the pivot element
    pivot = arr[low];

    // Partition the array into two parts: less than pivot and greater than pivot
    for (i = low + 1; i <= high; i++) {
        if (arr[i] < pivot) {
            swap(arr[i], arr[low]);
            low++;
        }
    }

    // Recursively sort the two partitions
    quicksort(arr, low, high);
    quicksort(arr, low, low - 1);
}

int main() {
    int arr[5] = {4, 2, 7, 1, 3};
    int i, j;

    // Print the initial array
    printf("Initial array: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort the array using quicksort
    quicksort(arr, 0, 4);

    // Print the sorted array
    printf("Sorted array: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Add some randomness to the sorting process
    for (i = 0; i < 5; i++) {
        // Randomly swap two elements
        j = rand() % 5;
        swap(arr[i], arr[j]);
    }

    // Sort the array again
    quicksort(arr, 0, 4);

    // Print the final sorted array
    printf("Final sorted array: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}