//FormAI DATASET v1.0 Category: Matrix operations ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 3

typedef struct {
   int row;
   int col;
   int **matrix_a;
   int **matrix_b;
   int **result_matrix;
} ThreadArgs;

void print_matrix(int **matrix) {
  int i, j;
  for (i = 0; i < SIZE; i++) {
    for (j = 0; j < SIZE; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

void * multiplyRowCol(void *arg) {
  ThreadArgs *args = (ThreadArgs *)arg;
  int i, sum = 0;
  for (i = 0; i < SIZE; i++) {
    sum += args->matrix_a[args->row][i] * args->matrix_b[i][args->col];
  }
  args->result_matrix[args->row][args->col] = sum;
  pthread_exit(NULL);
}

int main() {
  int i, j;
  int **matrix_a = malloc(SIZE * sizeof(int *));
  for (i = 0; i < SIZE; i++) {
    matrix_a[i] = malloc(SIZE * sizeof(int));
  }
  int **matrix_b = malloc(SIZE * sizeof(int *));
  for (i = 0; i < SIZE; i++) {
    matrix_b[i] = malloc(SIZE * sizeof(int));
  }
  int **result_matrix = malloc(SIZE * sizeof(int *));
  for (i = 0; i < SIZE; i++) {
    result_matrix[i] = malloc(SIZE * sizeof(int));
  }

  // Initialize matrices
  int counter = 1;
  for (i = 0; i < SIZE; i++) {
    for (j = 0; j < SIZE; j++) {
      matrix_a[i][j] = counter;
      matrix_b[i][j] = counter;
      counter++;
    }
  }

  // Prepare thread arguments for each cell of result matrix
  pthread_t threads[SIZE*SIZE];
  ThreadArgs thread_args[SIZE][SIZE];
  for (i = 0; i < SIZE; i++) {
    for (j = 0; j < SIZE; j++) {
      thread_args[i][j].row = i;
      thread_args[i][j].col = j;
      thread_args[i][j].matrix_a = matrix_a;
      thread_args[i][j].matrix_b = matrix_b;
      thread_args[i][j].result_matrix = result_matrix;
      pthread_create(&threads[(i*SIZE) + j], NULL, multiplyRowCol, &thread_args[i][j]);
    }
  }

  // Wait for all threads to complete
  for (i = 0; i < SIZE*SIZE; i++) {
    pthread_join(threads[i], NULL);
  }

  // Print matrices
  printf("Matrix A\n");
  print_matrix(matrix_a);
  printf("\nMatrix B\n");
  print_matrix(matrix_b);
  printf("\nResult Matrix\n");
  print_matrix(result_matrix);

  // Free memory
  for (i = 0; i < SIZE; i++) {
    free(matrix_a[i]);
    free(matrix_b[i]);
    free(result_matrix[i]);
  }
  free(matrix_a);
  free(matrix_b);
  free(result_matrix);

  return 0;
}