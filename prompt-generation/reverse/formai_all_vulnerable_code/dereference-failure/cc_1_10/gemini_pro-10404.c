//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the number of iterations for the benchmark
#define ITERATIONS 1000000

// Define the size of the data array
#define DATA_SIZE 10000

// Define the number of threads to use
#define NUM_THREADS 4

// Define the function to be benchmarked
double benchmark_function(double *data, int size) {
  double sum = 0.0;
  for (int i = 0; i < size; i++) {
    sum += data[i];
  }
  return sum;
}

// Define the function to run the benchmark
void run_benchmark(int num_threads) {
  // Allocate memory for the data array
  double *data = (double *)malloc(DATA_SIZE * sizeof(double));

  // Initialize the data array with random values
  for (int i = 0; i < DATA_SIZE; i++) {
    data[i] = (double)rand() / RAND_MAX;
  }

  // Start the timer
  clock_t start = clock();

  // Run the benchmark
  double sum = 0.0;
  for (int i = 0; i < ITERATIONS; i++) {
    sum += benchmark_function(data, DATA_SIZE);
  }

  // Stop the timer
  clock_t end = clock();

  // Calculate the elapsed time
  double elapsed_time = ((double)(end - start)) / CLOCKS_PER_SEC;

  // Print the results
  printf("Elapsed time: %f seconds\n", elapsed_time);
  printf("Sum: %f\n", sum);

  // Free the memory allocated for the data array
  free(data);
}

// Define the main function
int main(int argc, char *argv[]) {
  // Parse the command line arguments
  int num_threads = NUM_THREADS;
  if (argc > 1) {
    num_threads = atoi(argv[1]);
  }

  // Run the benchmark
  run_benchmark(num_threads);

  return 0;
}