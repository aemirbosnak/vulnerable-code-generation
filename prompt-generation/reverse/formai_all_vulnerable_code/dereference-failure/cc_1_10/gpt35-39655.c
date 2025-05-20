//FormAI DATASET v1.0 Category: Matrix operations ; Style: mathematical
#include <stdio.h>

void print_matrix(int row_size, int col_size, int matrix[row_size][col_size]) {
  for (int i = 0; i < row_size; i++) {
    for (int j = 0; j < col_size; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

void multiply_matrices(int row_size1, int col_size1, int matrix1[row_size1][col_size1],
                       int row_size2, int col_size2, int matrix2[row_size2][col_size2],
                       int product[row_size1][col_size2]) {
  if (col_size1 != row_size2) {
    printf("Error: The number of columns in the first matrix must be equal to the number of rows in the second matrix.\n");
    return;
  }
  
  for (int i = 0; i < row_size1; i++) {
    for (int j = 0; j < col_size2; j++) {
      int sum = 0;
      for (int k = 0; k < col_size1; k++) {
        sum += matrix1[i][k] * matrix2[k][j];
      }
      product[i][j] = sum;
    }
  }
}

int main() {
  int matrix1[3][2] = {{1, 2},
                       {3, 4},
                       {5, 6}};
  
  int matrix2[2][4] = {{7, 8, 9, 10},
                       {11, 12, 13, 14}};
                       
  printf("The first matrix is:\n");
  print_matrix(3, 2, matrix1);
  
  printf("\nThe second matrix is:\n");
  print_matrix(2, 4, matrix2);

  int product[3][4];
  multiply_matrices(3, 2, matrix1, 2, 4, matrix2, product);
  
  printf("\nThe product of the two matrices is:\n");
  print_matrix(3, 4, product);
  
  return 0;
}