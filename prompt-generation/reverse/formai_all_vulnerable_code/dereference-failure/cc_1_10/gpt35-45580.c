//FormAI DATASET v1.0 Category: Error handling ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <errno.h>

// Error handling function
void handle_error(int errnum) {
    fprintf(stderr, "Error: %s\n", strerror(errnum));
    exit(EXIT_FAILURE);
}

int main() {
    int num_heads = 0;  // Number of heads in the experiment
    int num_tails = 0;  // Number of tails in the experiment
    int num_flips = 1000;  // Number of flips in the experiment
    double mean;  // Mean value of coin tosses
    double sum = 0.0;  // Sum of coin tosses squared
    double variance;  // Variance of coin tosses
    double standard_deviation;  // Standard deviation of coin tosses
    int i;

    srand(time(NULL)); // Seed random number generator

    // Simulate the coin toss experiment
    for (i = 0; i < num_flips; i++) {
        if (rand() % 2 == 0) {
            num_heads++;
        } else {
            num_tails++;
        }

        if (errno != 0) {
            handle_error(errno);
        }
    }

    // Calculate mean
    mean = (double) num_heads / num_flips;

    // Calculate variance
    for (i = 0; i < num_flips; i++) {
        sum += pow((i / (double) num_flips) - mean, 2);

        if (errno != 0) {
            handle_error(errno);
        }
    }
    variance = sum / num_flips;

    // Calculate standard deviation
    standard_deviation = sqrt(variance);

    // If standard deviation is less than 0.05, experiment is statistically significant
    if (standard_deviation < 0.05) {
        printf("Experiment is statistically significant!\n");
    } else {
        printf("Experiment is not statistically significant.\n");
    }

    return 0;
}