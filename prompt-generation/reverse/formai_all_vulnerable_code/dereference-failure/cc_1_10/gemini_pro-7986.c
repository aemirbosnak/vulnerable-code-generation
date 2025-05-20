//GEMINI-pro DATASET v1.0 Category: Educational ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Define the number of elements to generate
#define NUM_ELEMENTS 10

// Define the range of values to generate
#define MIN_VALUE 0
#define MAX_VALUE 100

// Generate a random number within a given range
int random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Generate an array of random numbers
int *generate_array(int size) {
    int *array = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        array[i] = random_number(MIN_VALUE, MAX_VALUE);
    }
    return array;
}

// Print an array
void print_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Find the minimum element in an array
int find_min(int *array, int size) {
    int min = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

// Find the maximum element in an array
int find_max(int *array, int size) {
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

// Find the average of the elements in an array
double find_average(int *array, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum / size;
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate an array of random numbers
    int *array = generate_array(NUM_ELEMENTS);

    // Print the array
    printf("Array: ");
    print_array(array, NUM_ELEMENTS);

    // Find the minimum element in the array
    int min = find_min(array, NUM_ELEMENTS);

    // Find the maximum element in the array
    int max = find_max(array, NUM_ELEMENTS);

    // Find the average of the elements in the array
    double average = find_average(array, NUM_ELEMENTS);

    // Print the results
    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);
    printf("Average: %.2f\n", average);

    // Free the memory allocated for the array
    free(array);

    return 0;
}