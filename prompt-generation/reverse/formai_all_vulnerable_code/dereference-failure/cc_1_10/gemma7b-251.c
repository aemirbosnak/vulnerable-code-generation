//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

void dance_with_the_red_pill(int **matrix, int rows, int cols) {
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      int value = matrix[r][c];
      if (value == 1) {
        matrix[r][c] = 2;
      } else if (value == 2) {
        matrix[r][c] = 3;
      } else if (value == 3) {
        matrix[r][c] = 4;
      } else if (value == 4) {
        matrix[r][c] = 5;
      } else if (value == 5) {
        matrix[r][c] = 6;
      } else if (value == 6) {
        matrix[r][c] = 7;
      } else if (value == 7) {
        matrix[r][c] = 8;
      } else if (value == 8) {
        matrix[r][c] = 9;
      } else if (value == 9) {
        matrix[r][c] = 10;
      }
    }
  }
}

int main() {
  int rows = 5;
  int cols = 5;
  int **matrix = (int **)malloc(rows * sizeof(int *) + cols * sizeof(int));
  for (int r = 0; r < rows; r++) {
    matrix[r] = (int *)malloc(cols * sizeof(int));
  }

  // Initialize the matrix with random numbers
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      matrix[r][c] = rand() % 11;
    }
  }

  dance_with_the_red_pill(matrix, rows, cols);

  // Print the matrix
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      printf("%d ", matrix[r][c]);
    }
    printf("\n");
  }

  free(matrix);

  return 0;
}