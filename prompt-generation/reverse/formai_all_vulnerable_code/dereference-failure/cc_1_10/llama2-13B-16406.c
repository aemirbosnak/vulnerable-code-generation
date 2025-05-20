//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort the list using the quicksort algorithm
void sort(int arr[], int low, int high) {
    // Base case: If the list has only one element, return
    if (low >= high) return;

    // Partition the list into two halves
    int pivot = partition(arr, low, high);

    // Recursively sort the two halves
    sort(arr, low, pivot - 1);
    sort(arr, pivot + 1, high);
}

// Function to partition the list around a pivot element
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high - 1;

    // Swap elements less than pivot to the left of pivot
    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] >= pivot) {
            j--;
        }

        // Swap the elements
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
    int arr[] = {3, 2, 6, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sort the list
    sort(arr, 0, n - 1);

    // Print the sorted list
    printf("Sorted list: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}