//FormAI DATASET v1.0 Category: Benchmarking ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int matrix_size = 10000; // size of matrix to be tested
  int num_iterations = 10; // number of iterations to run for benchmarking
  
  clock_t start_time, end_time;
  double total_time = 0;
  
  // allocate memory for source matrix and destination matrix
  int **src = malloc(matrix_size * sizeof(int*));
  int **dest = malloc(matrix_size * sizeof(int*));

  for (int i = 0; i < matrix_size; i++) {
    src[i] = malloc(matrix_size * sizeof(int));
    dest[i] = malloc(matrix_size * sizeof(int));
  }

  // randomize the source matrix
  for (int i = 0; i < matrix_size; i++) {
    for (int j = 0; j < matrix_size; j++) {
      src[i][j] = rand() % 10;
    }
  }

  // run the benchmarking loop
  for (int k = 0; k < num_iterations; k++) {
    start_time = clock();
    
    // perform matrix rotation with left shift
    for (int i = 0; i < matrix_size; i++) {
      for (int j = 0; j < matrix_size; j++) {
        dest[i][j] = src[i][(j+1)%matrix_size];
      }
    }
    
    end_time = clock();
    total_time += ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
  }

  // calculate average time for all iterations
  double avg_time = total_time / num_iterations;

  // print the benchmark results
  printf("Benchmarking results for matrix size %d:\n", matrix_size);
  printf("Total time: %f seconds\n", total_time);
  printf("Average time per iteration: %f seconds\n", avg_time);

  // free memory
  for (int i = 0; i < matrix_size; i++) {
    free(src[i]);
    free(dest[i]);
  }
  free(src);
  free(dest);

  return 0;
}