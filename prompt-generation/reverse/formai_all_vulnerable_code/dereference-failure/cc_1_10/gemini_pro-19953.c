//GEMINI-pro DATASET v1.0 Category: Benchmarking ; Style: creative
// The Mighty Measure: A Benchmarking Symphony

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define our data structures
typedef struct {
  double value;
  int index;
} DataPoint;

// Forward declare benchmarking functions
void bench_find_max(int n, DataPoint *data);
void bench_sort(int n, DataPoint *data);
void bench_filter(int n, DataPoint *data);

// Main execution
int main() {
  // Set up our data
  const int n = 1000000;
  DataPoint *data = malloc(n * sizeof(DataPoint));
  for (int i = 0; i < n; i++) {
    data[i].value = drand48();
    data[i].index = i;
  }

  // Commence the benchmarking!
  printf("** Benchmarking the Mighty Measure **\n");
  printf("Data points generated: %d\n\n", n);

  struct timespec start, end;
  double time_elapsed;

  // Benchmark: Find the maximum value
  clock_gettime(CLOCK_MONOTONIC, &start);
  bench_find_max(n, data);
  clock_gettime(CLOCK_MONOTONIC, &end);
  time_elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;
  printf("Time to find the maximum value: %.3f seconds\n", time_elapsed);

  // Benchmark: Sort the data
  clock_gettime(CLOCK_MONOTONIC, &start);
  bench_sort(n, data);
  clock_gettime(CLOCK_MONOTONIC, &end);
  time_elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;
  printf("Time to sort the data: %.3f seconds\n", time_elapsed);

  // Benchmark: Filter the data
  clock_gettime(CLOCK_MONOTONIC, &start);
  bench_filter(n, data);
  clock_gettime(CLOCK_MONOTONIC, &end);
  time_elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;
  printf("Time to filter the data: %.3f seconds\n", time_elapsed);

  // Release our data
  free(data);

  // Victory dance!
  printf("\nThe benchmarking symphony has concluded!\n");
  return 0;
}

// Function to find the maximum value
void bench_find_max(int n, DataPoint *data) {
  double max_value = data[0].value;
  for (int i = 1; i < n; i++) {
    if (data[i].value > max_value) {
      max_value = data[i].value;
    }
  }
}

// Function to sort the data
void bench_sort(int n, DataPoint *data) {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (data[i].value > data[j].value) {
        DataPoint temp = data[i];
        data[i] = data[j];
        data[j] = temp;
      }
    }
  }
}

// Function to filter the data
void bench_filter(int n, DataPoint *data) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (data[i].value > 0.5) {
      count++;
    }
  }
}