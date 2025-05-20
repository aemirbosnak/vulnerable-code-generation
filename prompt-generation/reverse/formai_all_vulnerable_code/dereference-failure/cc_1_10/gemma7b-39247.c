//Gemma-7B DATASET v1.0 Category: Benchmarking ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

int main() {
  int i, j, n, size = MAX_SIZE;
  time_t start, end;
  double time_taken;

  // Allocate memory dynamically
  int **arr = (int**)malloc(size * sizeof(int*));
  for (i = 0; i < size; i++) {
    arr[i] = (int*)malloc(size * sizeof(int));
  }

  // Initialize the array
  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++) {
      arr[i][j] = 0;
    }
  }

  // Start the timer
  start = clock();

  // Perform a computationally expensive operation
  n = factorial(size);

  // Stop the timer
  end = clock();

  // Calculate the time taken
  time_taken = (double)(end - start) / CLOCKS_PER_SEC;

  // Print the time taken
  printf("Time taken: %.2f seconds\n", time_taken);

  // Free the memory
  for (i = 0; i < size; i++) {
    free(arr[i]);
  }
  free(arr);

  return 0;
}

int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}