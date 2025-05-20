//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

// Defines the size of the array to be sorted
#define ARRAY_SIZE 1000000

// Defines the type of the elements in the array
typedef int32_t element_type;

// Function to generate a random array of integers
void generate_random_array(element_type *array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        array[i] = rand() % 1000000;
    }
}

// Function to sort the array using the quicksort algorithm
void quicksort(element_type *array, size_t size) {
    if (size <= 1) return;

    element_type pivot = array[size / 2];
    element_type *left = array;
    element_type *right = array + size - 1;

    while (left <= right) {
        while (*left < pivot) left++;
        while (*right > pivot) right--;

        if (left <= right) {
            element_type temp = *left;
            *left = *right;
            *right = temp;

            left++;
            right--;
        }
    }

    quicksort(array, right - array + 1);
    quicksort(left, array + size - left);
}

// Function to print the array
void print_array(element_type *array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Main function
int main() {
    // Allocate memory for the array
    element_type *array = malloc(sizeof(element_type) * ARRAY_SIZE);

    // Generate a random array
    generate_random_array(array, ARRAY_SIZE);

    // Print the unsorted array
    printf("Unsorted array:\n");
    print_array(array, ARRAY_SIZE);

    // Sort the array
    quicksort(array, ARRAY_SIZE);

    // Print the sorted array
    printf("Sorted array:\n");
    print_array(array, ARRAY_SIZE);

    // Free the memory allocated for the array
    free(array);

    return 0;
}