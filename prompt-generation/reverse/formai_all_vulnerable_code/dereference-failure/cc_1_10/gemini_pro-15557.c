//GEMINI-pro DATASET v1.0 Category: Educational ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of elements in the array
#define MAX_SIZE 100

// Function to generate a random array
int* generate_random_array(int size) {
    // Allocate memory for the array
    int* array = malloc(size * sizeof(int));

    // Initialize the random number generator
    srand(time(NULL));

    // Generate random numbers and store them in the array
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }

    // Return the array
    return array;
}

// Function to find the minimum element in an array
int find_minimum(int* array, int size) {
    // Initialize the minimum value to the first element in the array
    int min = array[0];

    // Iterate over the remaining elements in the array
    for (int i = 1; i < size; i++) {
        // If the current element is less than the minimum value, update the minimum value
        if (array[i] < min) {
            min = array[i];
        }
    }

    // Return the minimum value
    return min;
}

// Function to find the maximum element in an array
int find_maximum(int* array, int size) {
    // Initialize the maximum value to the first element in the array
    int max = array[0];

    // Iterate over the remaining elements in the array
    for (int i = 1; i < size; i++) {
        // If the current element is greater than the maximum value, update the maximum value
        if (array[i] > max) {
            max = array[i];
        }
    }

    // Return the maximum value
    return max;
}

// Function to find the average of the elements in an array
double find_average(int* array, int size) {
    // Initialize the sum of the elements to 0
    double sum = 0;

    // Iterate over the elements in the array and add them to the sum
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }

    // Return the average of the elements
    return sum / size;
}

// Function to print an array
void print_array(int* array, int size) {
    // Iterate over the elements in the array and print them
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    // Print a newline character
    printf("\n");
}

// Main function
int main() {
    // Generate a random array
    int* array = generate_random_array(MAX_SIZE);

    // Print the array
    printf("Original array:\n");
    print_array(array, MAX_SIZE);

    // Find the minimum element in the array
    int min = find_minimum(array, MAX_SIZE);

    // Find the maximum element in the array
    int max = find_maximum(array, MAX_SIZE);

    // Find the average of the elements in the array
    double avg = find_average(array, MAX_SIZE);

    // Print the minimum, maximum, and average of the array
    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);
    printf("Average: %.2f\n", avg);

    // Free the memory allocated for the array
    free(array);

    return 0;
}