//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int generate_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to calculate the average of an array of numbers
double calculate_average(int *array, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum / size;
}

// Function to calculate the standard deviation of an array of numbers
double calculate_standard_deviation(int *array, int size) {
    double average = calculate_average(array, size);
    double sum_of_squared_differences = 0;
    for (int i = 0; i < size; i++) {
        sum_of_squared_differences += pow(array[i] - average, 2);
    }
    return sqrt(sum_of_squared_differences / size);
}

// Function to calculate the minimum value of an array of numbers
int calculate_minimum(int *array, int size) {
    int min = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

// Function to calculate the maximum value of an array of numbers
int calculate_maximum(int *array, int size) {
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

// Function to generate a random array of numbers
int *generate_random_array(int size) {
    int *array = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        array[i] = generate_random_number(0, 100);
    }
    return array;
}

// Function to print an array of numbers
void print_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    // Generate a random array of numbers
    int size = 100000;
    int *array = generate_random_array(size);

    // Calculate the average, standard deviation, minimum, and maximum of the array
    double average = calculate_average(array, size);
    double standard_deviation = calculate_standard_deviation(array, size);
    int minimum = calculate_minimum(array, size);
    int maximum = calculate_maximum(array, size);

    // Print the results
    printf("Average: %f\n", average);
    printf("Standard deviation: %f\n", standard_deviation);
    printf("Minimum: %d\n", minimum);
    printf("Maximum: %d\n", maximum);

    // Free the memory allocated for the array
    free(array);

    return 0;
}