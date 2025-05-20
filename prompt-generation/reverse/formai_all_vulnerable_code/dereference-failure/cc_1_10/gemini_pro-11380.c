//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the number of iterations for the benchmark
#define ITERATIONS 1000000

// Define the size of the array for the benchmark
#define ARRAY_SIZE 10000

// Define the function to be benchmarked
void benchmark_function(int *array, int size) {
  for (int i = 0; i < size; i++) {
    array[i] = array[i] * 2;
  }
}

// Define the main function
int main() {
  // Allocate memory for the array
  int *array = malloc(sizeof(int) * ARRAY_SIZE);

  // Initialize the array with random values
  for (int i = 0; i < ARRAY_SIZE; i++) {
    array[i] = rand() % 100;
  }

  // Start the timer
  clock_t start = clock();

  // Run the benchmark function
  for (int i = 0; i < ITERATIONS; i++) {
    benchmark_function(array, ARRAY_SIZE);
  }

  // Stop the timer
  clock_t end = clock();

  // Calculate the elapsed time
  double elapsed_time = ((double)(end - start)) / CLOCKS_PER_SEC;

  // Print the elapsed time
  printf("Elapsed time: %f seconds\n", elapsed_time);

  // Free the memory allocated for the array
  free(array);

  return 0;
}