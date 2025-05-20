//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the array to be benchmarked
#define ARRAY_SIZE 1000000

// Define the number of times to run the benchmark
#define NUM_RUNS 100

// Define the function to be benchmarked
double sum_array(double *array, int size) {
  double sum = 0.0;
  for (int i = 0; i < size; i++) {
    sum += array[i];
  }
  return sum;
}

int main() {
  // Allocate memory for the array
  double *array = malloc(ARRAY_SIZE * sizeof(double));

  // Initialize the array with random values
  srand(time(NULL));
  for (int i = 0; i < ARRAY_SIZE; i++) {
    array[i] = (double)rand() / RAND_MAX;
  }

  // Run the benchmark NUM_RUNS times
  clock_t start, end;
  double total_time = 0.0;
  for (int i = 0; i < NUM_RUNS; i++) {
    start = clock();
    sum_array(array, ARRAY_SIZE);
    end = clock();
    total_time += (double)(end - start) / CLOCKS_PER_SEC;
  }

  // Calculate the average time per run
  double avg_time = total_time / NUM_RUNS;

  // Print the results
  printf("Average time to sum an array of %d doubles: %f seconds\n", ARRAY_SIZE, avg_time);

  // Free the memory allocated for the array
  free(array);

  return 0;
}