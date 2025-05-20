//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h>

// Define the size of the array
#define ARRAY_SIZE 1000000

// Define the number of iterations
#define ITERATIONS 100

// Define the data type of the array
typedef uint64_t data_type;

// Define the function to be timed
void test_function(data_type *array, size_t size) {
  for (size_t i = 0; i < size; i++) {
    array[i] += 1;
  }
}

int main() {
  // Allocate memory for the array
  data_type *array = (data_type *)malloc(ARRAY_SIZE * sizeof(data_type));

  // Initialize the array with random values
  srand(time(NULL));
  for (size_t i = 0; i < ARRAY_SIZE; i++) {
    array[i] = rand();
  }

  // Start the timer
  clock_t start = clock();

  // Run the function ITERATIONS times
  for (size_t i = 0; i < ITERATIONS; i++) {
    test_function(array, ARRAY_SIZE);
  }

  // Stop the timer
  clock_t end = clock();

  // Calculate the elapsed time
  double elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;

  // Print the elapsed time
  printf("Elapsed time: %f seconds\n", elapsed);

  // Free the memory allocated for the array
  free(array);

  return 0;
}