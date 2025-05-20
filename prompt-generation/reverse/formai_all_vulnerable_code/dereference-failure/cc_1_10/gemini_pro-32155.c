//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers
int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

// Function to print an array
void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to sort an array using qsort
void sort_array(int *arr, int size) {
    qsort(arr, size, sizeof(int), compare);
}

// Function to generate a random array
int *generate_random_array(int size) {
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
    return arr;
}

// Main function
int main() {
    // Generate a random array of size 10
    int *arr = generate_random_array(10);

    // Print the original array
    printf("Original array:\n");
    print_array(arr, 10);

    // Sort the array using qsort
    sort_array(arr, 10);

    // Print the sorted array
    printf("Sorted array:\n");
    print_array(arr, 10);

    // Free the allocated memory
    free(arr);

    return 0;
}