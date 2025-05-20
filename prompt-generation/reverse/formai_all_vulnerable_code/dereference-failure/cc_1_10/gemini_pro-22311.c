//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum number of elements in the array
#define MAX_SIZE 100

// Function to generate a random array of integers
int *generate_random_array(int size) {
    int *array = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
    return array;
}

// Function to calculate the mean of an array of integers
double calculate_mean(int *array, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum / size;
}

// Function to calculate the standard deviation of an array of integers
double calculate_standard_deviation(int *array, int size) {
    double mean = calculate_mean(array, size);
    double sum_of_squared_differences = 0;
    for (int i = 0; i < size; i++) {
        sum_of_squared_differences += pow(array[i] - mean, 2);
    }
    return sqrt(sum_of_squared_differences / (size - 1));
}

// Function to print an array of integers
void print_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    // Generate a random array of integers
    int *array = generate_random_array(MAX_SIZE);

    // Print the array
    printf("Original array: ");
    print_array(array, MAX_SIZE);

    // Calculate the mean and standard deviation of the array
    double mean = calculate_mean(array, MAX_SIZE);
    double standard_deviation = calculate_standard_deviation(array, MAX_SIZE);

    // Print the mean and standard deviation
    printf("Mean: %.2f\n", mean);
    printf("Standard deviation: %.2f\n", standard_deviation);

    // Free the memory allocated to the array
    free(array);

    return 0;
}