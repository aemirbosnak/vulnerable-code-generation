//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of elements in the array
#define MAX_SIZE 100

// Define the comparison function for sorting
int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

// Function to generate a random array of integers
int *generate_random_array(int size) {
    int *array = malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }

    return array;
}

// Function to print an array of integers
void print_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");
}

// Main function
int main() {
    // Generate a random array of integers
    int *array = generate_random_array(MAX_SIZE);

    // Print the unsorted array
    printf("Unsorted array:\n");
    print_array(array, MAX_SIZE);

    // Sort the array using the qsort function
    qsort(array, MAX_SIZE, sizeof(int), compare);

    // Print the sorted array
    printf("Sorted array:\n");
    print_array(array, MAX_SIZE);

    // Free the memory allocated for the array
    free(array);

    return 0;
}