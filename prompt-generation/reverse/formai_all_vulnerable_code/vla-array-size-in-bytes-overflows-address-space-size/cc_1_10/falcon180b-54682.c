//Falcon-180B DATASET v1.0 Category: Sorting ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to swap two elements in an array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform selection sort on an array
void selection_sort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[i], &arr[min_idx]);
    }
}

// Function to print an array
void print_array(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, i;
    srand(time(NULL)); // Initialize random seed with current time
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    // Generate random numbers for the array
    for (i = 0; i < n; i++) {
        arr[i] = rand_num(1, 100);
    }
    // Print the unsorted array
    printf("Unsorted array:\n");
    print_array(arr, n);
    // Perform selection sort on the array
    selection_sort(arr, n);
    // Print the sorted array
    printf("Sorted array:\n");
    print_array(arr, n);
    return 0;
}