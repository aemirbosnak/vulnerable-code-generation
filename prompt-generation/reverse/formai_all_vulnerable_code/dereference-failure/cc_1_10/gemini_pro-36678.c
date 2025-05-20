//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Data structure for benchmarking results
typedef struct {
  double elapsed_time;
  int iterations;
} BenchmarkResult;

// Function to benchmark a code block
BenchmarkResult benchmark(void (*func)(void *), void *arg, int iterations) {
  clock_t start, end;
  BenchmarkResult result;

  // Warm up the CPU
  for (int i = 0; i < 1000000; i++) {
    func(arg);
  }

  // Start the timer
  start = clock();

  // Execute the code block multiple times
  for (int i = 0; i < iterations; i++) {
    func(arg);
  }

  // Stop the timer
  end = clock();

  // Calculate the elapsed time
  result.elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
  result.iterations = iterations;

  return result;
}

// Code block to benchmark
void test_function(void *arg) {
  int *array = (int *)arg;
  for (int i = 0; i < 1000000; i++) {
    array[i] += 1;
  }
}

int main() {
  // Generate a large array of integers
  int *array = malloc(sizeof(int) * 1000000);
  for (int i = 0; i < 1000000; i++) {
    array[i] = i;
  }

  // Benchmark the test function
  BenchmarkResult result = benchmark(test_function, array, 1000);

  // Print the benchmarking results
  printf("Benchmark results:\n");
  printf("- Elapsed time: %lfs\n", result.elapsed_time);
  printf("- Iterations: %d\n", result.iterations);

  // Free the allocated memory
  free(array);

  return 0;
}