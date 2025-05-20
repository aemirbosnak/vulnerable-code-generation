//FormAI DATASET v1.0 Category: Matrix operations ; Style: introspective
#include <stdio.h>

// Function for introspection - print matrix
void print_matrix(int rows, int cols, int matrix[rows][cols]) {
  printf("The matrix is:\n");
  for(int i=0; i<rows; i++) {
    for(int j=0; j<cols; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
  // Matrix creation
  int rows, cols;
  printf("Enter the number of rows and columns of the matrix:\n");
  scanf("%d %d", &rows, &cols);
  int matrix[rows][cols];
  printf("Enter the values for the matrix:\n");
  for(int i=0; i<rows; i++) {
    for(int j=0; j<cols; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }

  // Print matrix
  print_matrix(rows, cols, matrix);

  // Matrix transpose
  int transpose_matrix[cols][rows];
  for(int i=0; i<cols; i++) {
    for(int j=0; j<rows; j++) {
      transpose_matrix[i][j] = matrix[j][i];
    }
  }

  // Print transpose matrix
  printf("\nThe transpose matrix is:\n");
  for(int i=0; i<cols; i++) {
    for(int j=0; j<rows; j++) {
      printf("%d ", transpose_matrix[i][j]);
    }
    printf("\n");
  }

  // Matrix multiplication
  int new_rows, new_cols;
  printf("\nEnter the number of rows and columns of the new matrix for multiplication:\n");
  scanf("%d %d", &new_rows, &new_cols);
  int new_matrix[new_rows][new_cols];
  if(cols != new_rows) {
    printf("\nThe matrix multiplication is not possible!\n");
  } else {
    printf("Enter the values for the new matrix:\n");
    for(int i=0; i<new_rows; i++) {
      for(int j=0; j<new_cols; j++) {
        new_matrix[i][j] = 0;
        for(int k=0; k<cols; k++) {
          new_matrix[i][j] += matrix[i][k] * transpose_matrix[k][j];
        }
      }
    }

    // Print new matrix
    printf("\nThe new matrix is:\n");
    for(int i=0; i<new_rows; i++) {
      for(int j=0; j<new_cols; j++) {
        printf("%d ", new_matrix[i][j]);
      }
      printf("\n");
    }
  }

  return 0;
}