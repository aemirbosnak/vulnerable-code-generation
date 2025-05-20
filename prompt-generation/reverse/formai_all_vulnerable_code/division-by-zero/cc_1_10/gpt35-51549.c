//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 30
#define MAX_COLS 30

void initialize(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
  int i, j;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      matrix[i][j] = rand() % 2;
    }
  }
}

void print_board(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
  int i, j;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      if (matrix[i][j] == 0) {
        printf(" ");
      } else {
        printf("*");
      }
    }
    printf("\n");
  }
  printf("\n");
}

int is_percolated(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
  int i, j;
  for (j = 0; j < cols; j++) {
    int percolated = 0;
    for (i = 0; i < rows; i++) {
      if (matrix[i][j] == 1 && percolated) {
        return 1;
      } else if (matrix[i][j] == 1) {
        percolated = 1;
      }
    }
  }
  return 0;
}

int main() {
  srand(time(0));
  int rows, cols;
  printf("Enter the number of rows and columns of the matrix: ");
  scanf("%d %d", &rows, &cols);
  int matrix[MAX_ROWS][MAX_COLS];
  initialize(matrix, rows, cols);
  printf("Initial matrix:\n");
  print_board(matrix, rows, cols);
  while (!is_percolated(matrix, rows, cols)) {
    int row = rand() % rows;
    int col = rand() % cols;
    if (matrix[row][col] == 0) {
      matrix[row][col] = 1;
    }
  }
  printf("Percolated matrix:\n");
  print_board(matrix, rows, cols);
  return 0;
}