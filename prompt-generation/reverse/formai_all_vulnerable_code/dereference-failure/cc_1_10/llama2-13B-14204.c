//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort the array using insertion sort
void sort(int arr[], int n) {
    int i, j, min;
    for (i = 1; i < n; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

// Function to print the sorted array
void print(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[5] = {4, 2, 7, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Initialize the array with random numbers
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10 + 1;
    }

    // Sort the array using insertion sort
    sort(arr, n);

    // Print the sorted array
    print(arr, n);

    return 0;
}