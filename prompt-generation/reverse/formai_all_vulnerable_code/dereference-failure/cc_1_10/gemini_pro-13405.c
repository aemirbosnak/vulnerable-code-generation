//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Define the number of iterations for the benchmark
#define ITERATIONS 1000000

// Define the size of the array for the benchmark
#define ARRAY_SIZE 100000

// Define the function to be benchmarked
int sum_array(int *array, int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += array[i];
  }
  return sum;
}

// Define the main function
int main() {
  // Allocate memory for the arrays
  int *array1 = malloc(ARRAY_SIZE * sizeof(int));
  int *array2 = malloc(ARRAY_SIZE * sizeof(int));

  // Initialize the arrays with random values
  for (int i = 0; i < ARRAY_SIZE; i++) {
    array1[i] = rand();
    array2[i] = rand();
  }

  // Start the timer
  clock_t start = clock();

  // Run the benchmark
  for (int i = 0; i < ITERATIONS; i++) {
    sum_array(array1, ARRAY_SIZE);
    sum_array(array2, ARRAY_SIZE);
  }

  // Stop the timer
  clock_t end = clock();

  // Calculate the elapsed time
  double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

  // Print the elapsed time
  printf("Elapsed time: %f seconds\n", elapsed_time);

  // Free the memory allocated for the arrays
  free(array1);
  free(array2);

  return 0;
}