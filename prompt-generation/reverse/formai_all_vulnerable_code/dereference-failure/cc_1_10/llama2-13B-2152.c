//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    int i, j, min_idx;
    for (i = 0; i < ARRAY_SIZE - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < ARRAY_SIZE; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[min_idx], arr[i]);
    }
}

int main() {
    int arr[ARRAY_SIZE] = {64, 32, 16, 8, 4, 2, 1};
    int i;
    clock_t start, end;

    // Initialize the array
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort the array using selection sort
    sort(arr);

    // Print the sorted array
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Calculate the time taken for sorting
    clock_t now = clock();
    end = now;
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken for sorting: %f seconds\n", time_taken);

    return 0;
}