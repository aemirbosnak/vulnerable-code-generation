//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define some macro shortcuts for readability
#define START_TIMER(name) clock_t t_start_##name = clock();
#define STOP_TIMER(name) clock_t t_stop_##name = clock();
#define PRINT_ELAPSED(name) printf("Elapsed time for %s: %f seconds\n", #name, (double)(t_stop_##name - t_start_##name) / CLOCKS_PER_SEC);

// A simple function to calculate the factorial of a number
double factorial(unsigned int n) {
    if (n == 0) {
        return 1.0;
    } else {
        return n * factorial(n - 1);
    }
}

// A more efficient function to calculate the factorial of a number using memoization
double memoized_factorial(unsigned int n, double *memo) {
    if (memo[n] != -1.0) {
        return memo[n];
    } else {
        if (n == 0) {
            memo[n] = 1.0;
        } else {
            memo[n] = n * memoized_factorial(n - 1, memo);
        }
        return memo[n];
    }
}

int main() {
    // Set up a random number generator to generate input data
    srand((unsigned int)time(NULL));

    // Define the number of iterations for each benchmark
    const unsigned int iterations = 1000000;

    // Allocate memory for memoization
    double *memo = malloc(sizeof(double) * (iterations + 1));
    for (unsigned int i = 0; i <= iterations; i++) {
        memo[i] = -1.0;
    }

    // Run the benchmark for the simple factorial function
    START_TIMER(simple_factorial);
    for (unsigned int i = 0; i < iterations; i++) {
        factorial(rand() % 100);
    }
    STOP_TIMER(simple_factorial);
    PRINT_ELAPSED(simple_factorial);

    // Run the benchmark for the memoized factorial function
    START_TIMER(memoized_factorial);
    for (unsigned int i = 0; i < iterations; i++) {
        memoized_factorial(rand() % 100, memo);
    }
    STOP_TIMER(memoized_factorial);
    PRINT_ELAPSED(memoized_factorial);

    // Free the allocated memory
    free(memo);

    return 0;
}