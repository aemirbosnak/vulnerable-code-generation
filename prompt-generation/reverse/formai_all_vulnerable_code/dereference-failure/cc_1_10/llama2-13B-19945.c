//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort an array of integers
void sort(int arr[], int low, int high) {
    // Base case: If the length of the array is 1 or less, return
    if (low >= high) return;

    // Partition the array into two halves
    int pivot = partition(arr, low, high);

    // Recursively sort the two halves
    sort(arr, low, pivot - 1);
    sort(arr, pivot + 1, high);
}

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    // Move elements less than pivot to the left
    while (i <= j) {
        if (arr[i] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    // Move pivot to the right position
    swap(arr[low], arr[j]);

    return j + 1;
}

int main() {
    int arr[5] = { 3, 1, 2, 6, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sort the array with a random pivot
    srand(time(NULL));
    int pivot = arr[rand() % n];
    sort(arr, 0, n - 1);

    // Print the sorted array
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}