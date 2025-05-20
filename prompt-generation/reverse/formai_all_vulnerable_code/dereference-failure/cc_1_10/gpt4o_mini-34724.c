//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparison_count = 0; // Global variable to track the number of comparisons

// Function to swap two elements in the array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// The partition function for Quick Sort, which selects a pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = (low - 1); // Index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        comparison_count++; // Increment comparison count
        if (arr[j] < pivot) {
            i++; // Increment index of smaller element
            swap(&arr[i], &arr[j]); // Swap
        }
    }
    swap(&arr[i + 1], &arr[high]); // Swap pivot to its correct position
    return (i + 1);
}

// Quick Sort algorithm implementation
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partitioning index
        quickSort(arr, low, pi - 1); // Recursively sort elements before partition
        quickSort(arr, pi + 1, high); // Recursively sort elements after partition
    }
}

// Function to generate random integers
void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000; // Generate random numbers from 0 to 999
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to execute the sorting and statistics
int main() {
    srand(time(NULL)); // Seed for random number generation
    
    int size = 100; // Size of the array
    int* arr = (int*)malloc(size * sizeof(int)); // Dynamically allocate array

    generateRandomArray(arr, size); // Generate random integers
    printf("Original array:\n");
    printArray(arr, size); // Print original array

    clock_t start = clock(); // Start timer
    quickSort(arr, 0, size - 1); // Perform quick sort
    clock_t end = clock(); // End timer

    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC; // Calculate time taken

    printf("Sorted array:\n");
    printArray(arr, size); // Print sorted array
    printf("Number of comparisons made: %d\n", comparison_count); // Print number of comparisons
    printf("Time taken to sort: %f seconds\n", cpu_time_used); // Print time taken

    free(arr); // Free allocated memory
    return 0;
}