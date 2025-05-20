//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATRIX_ROWS 5
#define MATRIX_COLS 3

// Matrix operations
void print_matrix(float (*mat)[MATRIX_COLS]);
void add_matrices(float (*mat1)[MATRIX_COLS], float (*mat2)[MATRIX_COLS], float (*result)[MATRIX_COLS]);
void multiply_matrices(float (*mat1)[MATRIX_COLS], float (*mat2)[MATRIX_COLS], float (*result)[MATRIX_COLS]);

int main() {
  // Create matrices
  float (*mat1)[MATRIX_COLS] = malloc(MATRIX_ROWS * MATRIX_COLS * sizeof(float));
  float (*mat2)[MATRIX_COLS] = malloc(MATRIX_ROWS * MATRIX_COLS * sizeof(float));
  float (*result)[MATRIX_COLS] = malloc(MATRIX_ROWS * MATRIX_COLS * sizeof(float));

  // Populate matrices
  for (int i = 0; i < MATRIX_ROWS; i++) {
    for (int j = 0; j < MATRIX_COLS; j++) {
      mat1[i][j] = (i + j) % 2 ? 1.0f : 0.0f;
      mat2[i][j] = (i + j) % 3 ? 2.0f : 0.0f;
    }
  }

  // Perform operations
  add_matrices(mat1, mat2, result);
  multiply_matrices(mat1, mat2, result);

  // Print results
  print_matrix(result);

  // Free memory
  free(mat1);
  free(mat2);
  free(result);

  return 0;
}

// Matrix operations functions
void print_matrix(float (*mat)[MATRIX_COLS]) {
  for (int i = 0; i < MATRIX_ROWS; i++) {
    for (int j = 0; j < MATRIX_COLS; j++) {
      printf("%.2f ", mat[i][j]);
    }
    printf("\n");
  }
}

void add_matrices(float (*mat1)[MATRIX_COLS], float (*mat2)[MATRIX_COLS], float (*result)[MATRIX_COLS]) {
  for (int i = 0; i < MATRIX_ROWS; i++) {
    for (int j = 0; j < MATRIX_COLS; j++) {
      result[i][j] = mat1[i][j] + mat2[i][j];
    }
  }
}

void multiply_matrices(float (*mat1)[MATRIX_COLS], float (*mat2)[MATRIX_COLS], float (*result)[MATRIX_COLS]) {
  for (int i = 0; i < MATRIX_ROWS; i++) {
    for (int j = 0; j < MATRIX_COLS; j++) {
      for (int k = 0; k < MATRIX_COLS; k++) {
        result[i][j] += mat1[i][k] * mat2[k][j];
      }
    }
  }
}