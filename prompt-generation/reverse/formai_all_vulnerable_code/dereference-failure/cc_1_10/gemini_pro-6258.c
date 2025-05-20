//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum size of the array
#define MAX_SIZE 1000000

// Define the number of iterations
#define ITERATIONS 10000

// Define the function to test
void test_function(int *array, int size) {
  // Iterate over the array
  for (int i = 0; i < size; i++) {
    // Perform some operations on the array element
    array[i] *= 2;
  }
}

int main() {
  // Allocate memory for the array
  int *array = malloc(MAX_SIZE * sizeof(int));

  // Initialize the array
  for (int i = 0; i < MAX_SIZE; i++) {
    array[i] = rand() % 100;
  }

  // Start the timer
  clock_t start = clock();

  // Perform the test function multiple times
  for (int i = 0; i < ITERATIONS; i++) {
    test_function(array, MAX_SIZE);
  }

  // Stop the timer
  clock_t end = clock();

  // Calculate the time taken
  double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

  // Print the time taken
  printf("Time taken: %f seconds\n", time_taken);

  // Free the memory allocated for the array
  free(array);

  return 0;
}