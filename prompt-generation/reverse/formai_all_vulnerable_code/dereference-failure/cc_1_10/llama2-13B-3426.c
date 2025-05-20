//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>

#define MAX_ARRAY_SIZE 100
#define MAGIC_NUMBER 42

// Function to swap two elements in an array
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Function to sort an array using insertion sort
void insertion_sort(int arr[], int n) {
    int i, j;
    for (i = 1; i < n; i++) {
        int key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            swap(arr, j, j + 1);
            j--;
        }
        swap(arr, j + 1, i);
    }
}

// Function to generate a random array of integers
int *generate_random_array(int n) {
    int i, *arr;
    srand(time(NULL));
    arr = calloc(n, sizeof(int));
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    return arr;
}

int main() {
    int n, i, j, magic = MAGIC_NUMBER;
    int *arr;

    // Generate a random array of integers
    arr = generate_random_array(MAX_ARRAY_SIZE);

    // Print the array before sorting
    printf("Original array: ");
    for (i = 0; i < MAX_ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort the array using insertion sort
    insertion_sort(arr, MAX_ARRAY_SIZE);

    // Print the sorted array
    printf("Sorted array: ");
    for (i = 0; i < MAX_ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Check if the array is sorted
    for (i = 0; i < MAX_ARRAY_SIZE - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            printf("Error: Array is not sorted\n");
            return 1;
        }
    }

    // Check if the array contains the magic number
    for (i = 0; i < MAX_ARRAY_SIZE; i++) {
        if (arr[i] == magic) {
            printf("Error: Magic number not found\n");
            return 2;
        }
    }

    // Print the successful message
    printf("Success: Array is sorted and contains the magic number %d\n", magic);

    return 0;
}