//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum number of elements in the array
#define MAX_SIZE 100

// Function to generate a random array of integers
int *generate_random_array(int size) {
    int *array = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
    return array;
}

// Function to find the minimum element in an array
int find_minimum(int *array, int size) {
    int min = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

// Function to find the maximum element in an array
int find_maximum(int *array, int size) {
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

// Function to find the sum of all elements in an array
int find_sum(int *array, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;
}

// Function to find the average of all elements in an array
double find_average(int *array, int size) {
    double sum = find_sum(array, size);
    double average = sum / size;
    return average;
}

// Function to find the variance of all elements in an array
double find_variance(int *array, int size) {
    double average = find_average(array, size);
    double sum_of_squares = 0;
    for (int i = 0; i < size; i++) {
        sum_of_squares += pow(array[i] - average, 2);
    }
    double variance = sum_of_squares / (size - 1);
    return variance;
}

// Function to find the standard deviation of all elements in an array
double find_standard_deviation(int *array, int size) {
    double variance = find_variance(array, size);
    double standard_deviation = sqrt(variance);
    return standard_deviation;
}

// Main function
int main() {
    // Generate a random array of integers
    int *array = generate_random_array(MAX_SIZE);

    // Find the minimum element in the array
    int min = find_minimum(array, MAX_SIZE);

    // Find the maximum element in the array
    int max = find_maximum(array, MAX_SIZE);

    // Find the sum of all elements in the array
    int sum = find_sum(array, MAX_SIZE);

    // Find the average of all elements in the array
    double average = find_average(array, MAX_SIZE);

    // Find the variance of all elements in the array
    double variance = find_variance(array, MAX_SIZE);

    // Find the standard deviation of all elements in the array
    double standard_deviation = find_standard_deviation(array, MAX_SIZE);

    // Print the results
    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);
    printf("Sum: %d\n", sum);
    printf("Average: %f\n", average);
    printf("Variance: %f\n", variance);
    printf("Standard deviation: %f\n", standard_deviation);

    // Free the allocated memory
    free(array);

    return 0;
}