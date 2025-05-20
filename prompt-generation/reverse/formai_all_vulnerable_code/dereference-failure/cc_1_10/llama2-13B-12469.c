//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAGIC_NUMBER 42

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort an array of integers
void sort(int arr[], int n) {
    int i, j, min;

    // Base case: If the length of the array is 1 or less, return
    if (n <= 1) return;

    // Partition the array into two halves
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) min = j;
        }
        swap(arr[min], arr[i]);
    }

    // Recursively sort the two halves
    sort(arr, n / 2);
    sort(arr + n / 2, n / 2);
}

int main() {
    int arr[10] = {4, 2, 7, 1, 3, 6, 5, 8, 2, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Print the initial array
    printf("Initial array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    // Sort the array
    sort(arr, n);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}