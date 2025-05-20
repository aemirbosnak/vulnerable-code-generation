//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct __benchmark {
  int *numbers;
  size_t size;
} Benchmark;

void init_benchmark(Benchmark *bench, int size)
{
  bench->numbers = malloc(size * sizeof(int));
  for (size_t i = 0; i < size; i++) {
    bench->numbers[i] = rand() % 1000;
  }
  bench->size = size;
}

void free_benchmark(Benchmark *bench)
{
  free(bench->numbers);
  bench->numbers = NULL;
  bench->size = 0;
}

int main()
{
  // Set up the benchmark
  Benchmark bench;
  init_benchmark(&bench, 1000000);

  // Start the clock
  clock_t start = clock();

  // Do the benchmark
  for (size_t i = 0; i < bench.size; i++) {
    if (bench.numbers[i] % 2 == 0) {
      // Do something with even numbers
    } else {
      // Do something with odd numbers
    }
  }

  // Stop the clock
  clock_t end = clock();

  // Print the results
  printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

  // Free the benchmark
  free_benchmark(&bench);

  return 0;
}