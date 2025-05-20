//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 1000
#define MAX_COLS 10

typedef struct {
  int rows;
  int cols;
  int **data;
} Matrix;

Matrix *create_matrix(int rows, int cols) {
  Matrix *matrix = malloc(sizeof(Matrix));
  matrix->rows = rows;
  matrix->cols = cols;
  matrix->data = malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; i++) {
    matrix->data[i] = malloc(cols * sizeof(int));
  }
  return matrix;
}

void free_matrix(Matrix *matrix) {
  for (int i = 0; i < matrix->rows; i++) {
    free(matrix->data[i]);
  }
  free(matrix->data);
  free(matrix);
}

void print_matrix(Matrix *matrix) {
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->cols; j++) {
      printf("%d ", matrix->data[i][j]);
    }
    printf("\n");
  }
}

int main() {
  // Create a matrix with 10 rows and 10 columns
  Matrix *matrix = create_matrix(10, 10);

  // Initialize the matrix with random values
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->cols; j++) {
      matrix->data[i][j] = rand() % 100;
    }
  }

  // Print the matrix
  print_matrix(matrix);

  // Create an index for the matrix
  int **index = malloc(matrix->rows * sizeof(int *));
  for (int i = 0; i < matrix->rows; i++) {
    index[i] = malloc(matrix->cols * sizeof(int));
  }

  // Initialize the index with the row numbers
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->cols; j++) {
      index[i][j] = i;
    }
  }

  // Sort the index by the values in the matrix
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->cols; j++) {
      for (int k = j + 1; k < matrix->cols; k++) {
        if (matrix->data[index[i][j]][j] > matrix->data[index[i][k]][k]) {
          int temp = index[i][j];
          index[i][j] = index[i][k];
          index[i][k] = temp;
        }
      }
    }
  }

  // Print the sorted matrix
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->cols; j++) {
      printf("%d ", matrix->data[index[i][j]][j]);
    }
    printf("\n");
  }

  // Free the matrix and the index
  free_matrix(matrix);
  for (int i = 0; i < matrix->rows; i++) {
    free(index[i]);
  }
  free(index);

  return 0;
}