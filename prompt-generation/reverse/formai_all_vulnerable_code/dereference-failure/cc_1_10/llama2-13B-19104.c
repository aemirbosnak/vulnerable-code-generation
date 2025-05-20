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

// Function to sort an array of integers using insertion sort
void sortArray(int arr[], int n) {
    int i, j, temp;

    // Loop through the array n-1 times
    for (i = 0; i < n - 1; i++) {
        // Find the first unsorted element
        j = i + 1;
        while (j < n && arr[j] <= arr[i]) {
            j++;
        }

        // Swap the unsorted element with the first element
        swap(&arr[i], &arr[j]);

        // Move the first element to its correct position
        i++;
    }
}

// Main function
int main() {
    int arr[5] = {4, 2, 7, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Start the clock
    clock_t start = clock();

    // Sort the array
    sortArray(arr, n);

    // End the clock
    clock_t end = clock();

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Print the time taken to sort the array
    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}