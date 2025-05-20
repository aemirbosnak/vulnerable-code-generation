//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the number of elements in the array.
#define NUM_ELEMENTS 1000000

// Define the number of times to run the test.
#define NUM_TESTS 100

// Define the function to be tested.
int test_function(int *array, int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += array[i];
  }
  return sum;
}

// Define the main function.
int main() {
  // Create an array of integers.
  int *array = (int *)malloc(NUM_ELEMENTS * sizeof(int));

  // Initialize the array with random numbers.
  srand(time(NULL));
  for (int i = 0; i < NUM_ELEMENTS; i++) {
    array[i] = rand();
  }

  // Run the test multiple times and measure the time taken.
  clock_t start, end;
  double total_time = 0.0;
  for (int i = 0; i < NUM_TESTS; i++) {
    start = clock();
    test_function(array, NUM_ELEMENTS);
    end = clock();
    total_time += (double)(end - start) / CLOCKS_PER_SEC;
  }

  // Calculate the average time taken.
  double average_time = total_time / NUM_TESTS;

  // Print the average time taken.
  printf("Average time taken: %f seconds\n", average_time);

  // Free the memory allocated for the array.
  free(array);

  return 0;
}