//Falcon2-11B DATASET v1.0 Category: Sorting ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort an array of integers
void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Function to print an array of integers
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to generate random integers
int* generateRandomIntegers(int min, int max, int n) {
    srand(time(NULL));
    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (max - min + 1) + min;
    }
    return arr;
}

// Main function
int main() {
    int n = 10; // Size of array
    int *arr = generateRandomIntegers(1, 100, n); // Generate random integers
    printf("Original array: ");
    printArray(arr, n);

    // Sort the array
    sort(arr, n);

    // Print sorted array
    printf("Sorted array: ");
    printArray(arr, n);

    free(arr); // Free allocated memory
    return 0;
}