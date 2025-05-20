//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to be benchmarked
double my_function(double x) {
  return x * x + 2 * x + 1;
}

// Function to generate random numbers
double random_number(double min, double max) {
  return min + (max - min) * ((double)rand() / (double)RAND_MAX);
}

int main() {
  // Set up the benchmarking parameters
  int num_iterations = 1000000;
  double min_value = -10.0;
  double max_value = 10.0;

  // Create an array of random numbers
  double *numbers = malloc(num_iterations * sizeof(double));
  for (int i = 0; i < num_iterations; i++) {
    numbers[i] = random_number(min_value, max_value);
  }

  // Start the timer
  clock_t start = clock();

  // Call the function to be benchmarked num_iterations times
  for (int i = 0; i < num_iterations; i++) {
    my_function(numbers[i]);
  }

  // Stop the timer
  clock_t end = clock();

  // Calculate the elapsed time
  double elapsed_time = ((double)(end - start)) / CLOCKS_PER_SEC;

  // Calculate the average time per iteration
  double avg_time_per_iteration = elapsed_time / num_iterations;

  // Print the results
  printf("Number of iterations: %d\n", num_iterations);
  printf("Elapsed time: %f seconds\n", elapsed_time);
  printf("Average time per iteration: %f seconds\n", avg_time_per_iteration);

  // Free the allocated memory
  free(numbers);

  return 0;
}