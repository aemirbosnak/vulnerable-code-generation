//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the array
#define ARRAY_SIZE 1000000

// Define the number of iterations
#define NUM_ITERATIONS 1000

// Create an array of random numbers
int* create_array() {
  int* array = malloc(ARRAY_SIZE * sizeof(int));
  for (int i = 0; i < ARRAY_SIZE; i++) {
    array[i] = rand();
  }
  return array;
}

// Sort the array using bubble sort
void bubble_sort(int* array, int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}

// Measure the time taken to sort the array
double measure_time(int* array, int size) {
  clock_t start = clock();
  bubble_sort(array, size);
  clock_t end = clock();
  return (double)(end - start) / CLOCKS_PER_SEC;
}

// Print the results
void print_results(double time) {
  printf("Time taken to sort the array: %.6f seconds\n", time);
}

int main() {
  // Create an array of random numbers
  int* array = create_array();

  // Measure the time taken to sort the array
  double time = measure_time(array, ARRAY_SIZE);

  // Print the results
  print_results(time);

  // Free the memory allocated for the array
  free(array);

  return 0;
}