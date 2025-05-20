//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers
int generate_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to calculate the mean of an array
double calculate_mean(int *arr, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

// Function to calculate the standard deviation of an array
double calculate_standard_deviation(int *arr, int n) {
    double mean = calculate_mean(arr, n);
    double sum_of_squared_differences = 0;
    for (int i = 0; i < n; i++) {
        sum_of_squared_differences += (arr[i] - mean) * (arr[i] - mean);
    }
    return sqrt(sum_of_squared_differences / n);
}

// Function to perform a statistical analysis on an array
void perform_statistical_analysis(int *arr, int n) {
    // Calculate the mean
    double mean = calculate_mean(arr, n);

    // Calculate the standard deviation
    double standard_deviation = calculate_standard_deviation(arr, n);

    // Print the results
    printf("Mean: %.2f\n", mean);
    printf("Standard deviation: %.2f\n", standard_deviation);
}

// Function to generate an array of random numbers
int *generate_random_array(int n) {
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = generate_random_number(1, 100);
    }
    return arr;
}

// Main function
int main() {
    // Set the random seed
    srand(time(NULL));

    // Generate an array of 100 random numbers
    int *arr = generate_random_array(100);

    // Perform a statistical analysis on the array
    perform_statistical_analysis(arr, 100);

    // Free the allocated memory
    free(arr);

    return 0;
}