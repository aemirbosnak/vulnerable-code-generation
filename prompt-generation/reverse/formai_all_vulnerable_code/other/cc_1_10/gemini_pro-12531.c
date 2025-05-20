//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: shape shifting
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <unistd.h>

// Define the data structure for the benchmark.
typedef struct benchmark {
    char *name;              // The name of the benchmark.
    void (*function)(void);    // The function to be benchmarked.
    int iterations;          // The number of iterations to run the benchmark for.
} benchmark;

// Define the array of benchmarks.
benchmark benchmarks[] = {
    { "memcpy", memcpy, 1000000 },
    { "memset", memset, 1000000 },
    { "strcpy", strcpy, 1000000 },
    { "strcmp", strcmp, 1000000 },
    { "strtok", strtok, 1000000 },
    { "atoi", atoi, 1000000 },
    { "atof", atof, 1000000 },
    { "rand", rand, 1000000 },
    { "sleep", sleep, 1000000 },
    { "usleep", usleep, 1000000 }
};

// Define the number of benchmarks.
#define NUM_BENCHMARKS (sizeof(benchmarks) / sizeof(benchmark))

// Run the benchmark.
void run_benchmark(benchmark *benchmark) {
    // Get the start time.
    clock_t start = clock();

    // Run the benchmark.
    for (int i = 0; i < benchmark->iterations; i++) {
        benchmark->function();
    }

    // Get the end time.
    clock_t end = clock();

    // Calculate the elapsed time.
    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;

    // Print the results.
    printf("%s: %.6f seconds\n", benchmark->name, elapsed);
}

// Main function.
int main(int argc, char *argv[]) {
    // Run the benchmarks.
    for (int i = 0; i < NUM_BENCHMARKS; i++) {
        run_benchmark(&benchmarks[i]);
    }

    return 0;
}