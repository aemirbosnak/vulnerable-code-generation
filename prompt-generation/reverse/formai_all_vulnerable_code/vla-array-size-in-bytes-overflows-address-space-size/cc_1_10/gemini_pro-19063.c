//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int main() {
  int rows, cols;
  int matrix[MAX_ROWS][MAX_COLS];

  // Read matrix dimensions
  printf("Enter the number of rows: ");
  scanf("%d", &rows);
  printf("Enter the number of columns: ");
  scanf("%d", &cols);

  // Read matrix elements
  printf("Enter the matrix elements:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }

  // Print original matrix
  printf("Original Matrix:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  // Calculate matrix transpose
  int transpose[cols][rows];
  for (int i = 0; i < cols; i++) {
    for (int j = 0; j < rows; j++) {
      transpose[i][j] = matrix[j][i];
    }
  }

  // Print matrix transpose
  printf("Matrix Transpose:\n");
  for (int i = 0; i < cols; i++) {
    for (int j = 0; j < rows; j++) {
      printf("%d ", transpose[i][j]);
    }
    printf("\n");
  }

  return 0;
}