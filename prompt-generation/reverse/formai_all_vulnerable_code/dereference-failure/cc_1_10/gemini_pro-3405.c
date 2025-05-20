//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the array to be sorted
#define ARRAY_SIZE 100000

// Define the number of times to run the benchmark
#define BENCHMARK_ITERATIONS 100

// Generate a random array of integers
int *generate_random_array(int size) {
  int *array = malloc(size * sizeof(int));

  for (int i = 0; i < size; i++) {
    array[i] = rand() % size;
  }

  return array;
}

// Sort the array using the bubble sort algorithm
void bubble_sort(int *array, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - 1; j++) {
      if (array[j] > array[j + 1]) {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}

// Measure the time taken to sort the array using the bubble sort algorithm
double benchmark_bubble_sort(int *array, int size) {
  clock_t start = clock();
  bubble_sort(array, size);
  clock_t end = clock();

  return (double)(end - start) / CLOCKS_PER_SEC;
}

int main() {
  // Generate a random array of integers
  int *array = generate_random_array(ARRAY_SIZE);

  // Run the benchmark multiple times and calculate the average time taken
  double total_time = 0.0;
  for (int i = 0; i < BENCHMARK_ITERATIONS; i++) {
    total_time += benchmark_bubble_sort(array, ARRAY_SIZE);
  }
  double average_time = total_time / BENCHMARK_ITERATIONS;

  // Print the average time taken to sort the array
  printf("Average time taken to sort the array using the bubble sort algorithm: %f seconds\n", average_time);

  // Free the memory allocated for the array
  free(array);

  return 0;
}