//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of elements in the array
#define ARRAY_SIZE 1000000

// Create a random array of integers
int *create_random_array(int size) {
  int *array = malloc(size * sizeof(int));
  for (int i = 0; i < size; i++) {
    array[i] = rand() % size;
  }
  return array;
}

// Find the maximum element in the array using a sequential search
int find_max_sequential(int *array, int size) {
  int max = array[0];
  for (int i = 1; i < size; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }
  return max;
}

// Find the maximum element in the array using a parallel search with OpenMP
int find_max_parallel(int *array, int size) {
  int max = 0;
#pragma omp parallel for reduction(max : array[i])
  for (int i = 0; i < size; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }
  return max;
}

// Print the results
void print_results(int max_sequential, int max_parallel) {
  printf("Maximum element using sequential search: %d\n", max_sequential);
  printf("Maximum element using parallel search: %d\n", max_parallel);
}

int main() {
  // Set the random seed
  srand(time(NULL));

  // Create a random array
  int *array = create_random_array(ARRAY_SIZE);

  // Find the maximum element using a sequential search
  int max_sequential = find_max_sequential(array, ARRAY_SIZE);

  // Find the maximum element using a parallel search with OpenMP
  int max_parallel = find_max_parallel(array, ARRAY_SIZE);

  // Print the results
  print_results(max_sequential, max_parallel);

  // Free the allocated memory
  free(array);

  return 0;
}