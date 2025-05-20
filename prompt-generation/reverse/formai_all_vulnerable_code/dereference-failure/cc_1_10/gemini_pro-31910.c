//GEMINI-pro DATASET v1.0 Category: Educational ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Define the number of elements to be generated
#define NUM_ELEMENTS 10

// Generate a random number between min and max
int random_number(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Generate a random array of integers
int* generate_random_array(int size) {
    // Allocate memory for the array
    int* array = (int*)malloc(size * sizeof(int));

    // Generate random numbers for the array
    for (int i = 0; i < size; i++) {
        array[i] = random_number(0, 100);
    }

    // Return the array
    return array;
}

// Print the elements of an array
void print_array(int* array, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d, ", array[i]);
    }
    printf("]\n");
}

// Find the minimum element in an array
int find_minimum(int* array, int size) {
    int min = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

// Find the maximum element in an array
int find_maximum(int* array, int size) {
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

// Find the average of the elements in an array
float find_average(int* array, int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum / size;
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Generate a random array of integers
    int* array = generate_random_array(NUM_ELEMENTS);

    // Print the original array
    printf("Original array: ");
    print_array(array, NUM_ELEMENTS);

    // Find the minimum element in the array
    int min = find_minimum(array, NUM_ELEMENTS);

    // Find the maximum element in the array
    int max = find_maximum(array, NUM_ELEMENTS);

    // Find the average of the elements in the array
    float average = find_average(array, NUM_ELEMENTS);

    // Print the minimum, maximum, and average of the array
    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);
    printf("Average: %.2f\n", average);

    // Free the memory allocated for the array
    free(array);

    return 0;
}