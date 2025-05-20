//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: calm
// Compiling, running and measuring performance of C code
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

// Function prototypes
double compute_pi(int num_iterations);
double measure_time(double (*func)(int), int num_iterations);

int main(int argc, char *argv[]) {

// Check if the number of iterations was provided as an argument
    if (argc < 2) {
        printf("Usage: %s <number_of_iterations>\n", argv[0]);
        return 1;
    }

    // Parse the number of iterations
    int num_iterations = atoi(argv[1]);

    // Compute the value of pi using the Leibnitz series
    double pi = compute_pi(num_iterations);

    // Measure the time taken to compute pi
    double time_taken = measure_time(compute_pi, num_iterations);

    // Print the results
    printf("Computed value of pi: %.15f\n", pi);
    printf("Time taken to compute pi: %.6f seconds\n", time_taken);

    return 0;
}

// Function to compute the value of pi using the Leibnitz series
double compute_pi(int num_iterations) {
    double pi = 0.0;
    for (int i = 0; i < num_iterations; i++) {
        pi += 4.0 * (-1.0 / (2.0 * i + 1.0) + 1.0 / (2.0 * i + 3.0));
    }
    return pi;
}

// Function to measure the time taken to execute a function
double measure_time(double (*func)(int), int num_iterations) {
    struct timeval start, end;
    gettimeofday(&start, NULL);
    func(num_iterations);
    gettimeofday(&end, NULL);
    return (double)(end.tv_sec - start.tv_sec) + (double)(end.tv_usec - start.tv_usec) / 1000000.0;
}