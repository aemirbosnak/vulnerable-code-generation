//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: standalone
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <math.h>

// Define the number of elements in the array
#define ARRAY_SIZE 1000000

// Define the number of trials to run
#define NUM_TRIALS 10

// Function to generate a random number between 0 and 1
double rand_double() {
    return (double)rand() / (double)RAND_MAX;
}

// Function to calculate the sum of an array of doubles
double sum_array(double *array, int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;
}

// Function to calculate the average of an array of doubles
double avg_array(double *array, int size) {
    double sum = sum_array(array, size);
    return sum / size;
}

// Function to calculate the standard deviation of an array of doubles
double stddev_array(double *array, int size) {
    double avg = avg_array(array, size);
    double sum_sq_diff = 0.0;
    for (int i = 0; i < size; i++) {
        sum_sq_diff += pow(array[i] - avg, 2);
    }
    return sqrt(sum_sq_diff / size);
}

// Function to run a single trial of the experiment
double run_trial() {
    // Generate an array of random numbers
    double *array = (double *)malloc(ARRAY_SIZE * sizeof(double));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand_double();
    }

    // Calculate the sum, average, and standard deviation of the array
    double sum = sum_array(array, ARRAY_SIZE);
    double avg = avg_array(array, ARRAY_SIZE);
    double stddev = stddev_array(array, ARRAY_SIZE);

    // Free the memory allocated for the array
    free(array);

    // Return the standard deviation
    return stddev;
}

// Function to run multiple trials of the experiment and calculate the average standard deviation
double run_experiment(int num_trials) {
    // Run each trial and store the standard deviation in an array
    double *stddevs = (double *)malloc(num_trials * sizeof(double));
    for (int i = 0; i < num_trials; i++) {
        stddevs[i] = run_trial();
    }

    // Calculate the average standard deviation
    double avg_stddev = avg_array(stddevs, num_trials);

    // Free the memory allocated for the array
    free(stddevs);

    // Return the average standard deviation
    return avg_stddev;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Run the experiment and store the average standard deviation
    double avg_stddev = run_experiment(NUM_TRIALS);

    // Print the average standard deviation
    printf("Average standard deviation: %f\n", avg_stddev);

    return 0;
}