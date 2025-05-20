//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort the array using selection sort
void sort(int arr[ARRAY_SIZE]) {
    int i, j, min_idx, temp;

    // Loop until the array is sorted
    for (i = 0; i < ARRAY_SIZE - 1; i++) {
        // Find the smallest element
        min_idx = i;
        for (j = i + 1; j < ARRAY_SIZE; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the smallest element with the current element
        swap(arr[min_idx], arr[i]);
    }
}

int main() {
    int arr[ARRAY_SIZE] = {4, 2, 7, 1, 3, 6, 5, 8, 9, 10};
    clock_t start, end;

    // Start the clock
    start = clock();

    // Sort the array
    sort(arr);

    // End the clock
    end = clock();

    // Print the sorted array
    printf("Sorted array: \n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }

    // Print the time taken
    printf("\nTime taken: %fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}