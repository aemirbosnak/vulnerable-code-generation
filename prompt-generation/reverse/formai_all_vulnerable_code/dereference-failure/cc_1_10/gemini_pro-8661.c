//GEMINI-pro DATASET v1.0 Category: Educational ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the array size
#define SIZE 10

// Define the maximum value for the array elements
#define MAX_VALUE 100

// Generate a random array of integers
int* generate_random_array() {
    // Allocate memory for the array
    int* array = malloc(SIZE * sizeof(int));

    // Initialize the random number generator
    srand(time(NULL));

    // Generate random numbers and store them in the array
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % MAX_VALUE;
    }

    // Return the array
    return array;
}

// Print the array
void print_array(int* array) {
    // Iterate over the array and print each element
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }

    // Print a newline character
    printf("\n");
}

// Sort the array using the bubble sort algorithm
void bubble_sort(int* array) {
    // Iterate over the array
    for (int i = 0; i < SIZE - 1; i++) {
        // Iterate over the remaining elements in the array
        for (int j = 0; j < SIZE - i - 1; j++) {
            // If the current element is greater than the next element, swap them
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Main function
int main() {
    // Generate a random array of integers
    int* array = generate_random_array();

    // Print the original array
    printf("Original array: ");
    print_array(array);

    // Sort the array using the bubble sort algorithm
    bubble_sort(array);

    // Print the sorted array
    printf("Sorted array: ");
    print_array(array);

    // Free the memory allocated for the array
    free(array);

    return 0;
}