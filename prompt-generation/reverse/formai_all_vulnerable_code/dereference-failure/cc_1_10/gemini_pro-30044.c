//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of characters in a string
#define MAX_STRING_LENGTH 1024

// Define the maximum number of strings in the array
#define MAX_ARRAY_SIZE 1000000

// Define the number of times to run the benchmark
#define NUM_TRIALS 100000

// Define the function to be benchmarked
int my_strlen(char *str) {
  int len = 0;
  while (*str != '\0') {
    len++;
    str++;
  }
  return len;
}

// Define the main function
int main() {
  // Allocate memory for the array of strings
  char **array = malloc(MAX_ARRAY_SIZE * sizeof(char *));

  // Initialize the array of strings
  for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
    array[i] = malloc(MAX_STRING_LENGTH * sizeof(char));
    memset(array[i], 'a', MAX_STRING_LENGTH - 1);
    array[i][MAX_STRING_LENGTH - 1] = '\0';
  }

  // Start the timer
  clock_t start = clock();

  // Run the benchmark
  for (int i = 0; i < NUM_TRIALS; i++) {
    for (int j = 0; j < MAX_ARRAY_SIZE; j++) {
      my_strlen(array[j]);
    }
  }

  // Stop the timer
  clock_t end = clock();

  // Calculate the elapsed time
  double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

  // Print the elapsed time
  printf("Elapsed time: %f seconds\n", elapsed_time);

  // Free the memory allocated for the array of strings
  for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
    free(array[i]);
  }
  free(array);

  return 0;
}