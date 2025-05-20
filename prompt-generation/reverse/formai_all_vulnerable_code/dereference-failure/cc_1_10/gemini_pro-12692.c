//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of elements in the array
#define ARRAY_SIZE 1000000

// Define the number of iterations for the benchmarking loop
#define ITERATIONS 100

// Define the function to be benchmarked
double sum_array(double *array, int size) {
  double sum = 0.0;
  for (int i = 0; i < size; i++) {
    sum += array[i];
  }
  return sum;
}

// Main function
int main() {
  // Allocate memory for the array
  double *array = malloc(ARRAY_SIZE * sizeof(double));

  // Initialize the array with random values
  srand(time(NULL));
  for (int i = 0; i < ARRAY_SIZE; i++) {
    array[i] = (double)rand() / RAND_MAX;
  }

  // Start the timer
  clock_t start = clock();

  // Run the benchmarking loop
  for (int i = 0; i < ITERATIONS; i++) {
    sum_array(array, ARRAY_SIZE);
  }

  // Stop the timer
  clock_t end = clock();

  // Calculate the elapsed time
  double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

  // Calculate the average time per iteration
  double avg_time = elapsed_time / ITERATIONS;

  // Print the results
  printf("Sum of array: %.2f\n", sum_array(array, ARRAY_SIZE));
  printf("Elapsed time: %.6f seconds\n", elapsed_time);
  printf("Average time per iteration: %.6f seconds\n", avg_time);

  // Free the memory allocated for the array
  free(array);

  return 0;
}