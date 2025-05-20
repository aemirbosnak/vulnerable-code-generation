//FormAI DATASET v1.0 Category: Matrix operations ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main() {

  printf("Welcome to the Matrix Operations Program!\n");

  // Matrix creation
  int rows, cols, i, j;
  printf("Enter the number of rows and columns of the matrix:\n");
  scanf("%d %d", &rows, &cols);
  
  int **matrix1, **matrix2, **sum, **product;
  matrix1 = (int **)malloc(rows * sizeof(int *));
  matrix2 = (int **)malloc(rows * sizeof(int *));
  sum = (int **)malloc(rows * sizeof(int *));
  product = (int **)malloc(rows * sizeof(int *));
  
  for(i=0;i<rows;i++){
      matrix1[i] = (int *)malloc(cols * sizeof(int));
      matrix2[i] = (int *)malloc(cols * sizeof(int));
      sum[i] = (int *)malloc(cols * sizeof(int));
      product[i] = (int *)malloc(cols * sizeof(int));
  }
  
  printf("Enter the elements of Matrix 1:\n");
  for(i=0;i<rows;i++){
      for(j=0;j<cols;j++){
          scanf("%d", &matrix1[i][j]);
      }
  }
  
  printf("Enter the elements of Matrix 2:\n");
  for(i=0;i<rows;i++){
      for(j=0;j<cols;j++){
          scanf("%d", &matrix2[i][j]);
      }
  }

  // Matrix addition
  printf("\nAdding Matrix 1 and Matrix 2...\n");
  for(i=0;i<rows;i++){
      for(j=0;j<cols;j++){
          sum[i][j] = matrix1[i][j] + matrix2[i][j];
      }
  }
  
  printf("\nMatrix 1 + Matrix 2 is:\n");
  for(i=0;i<rows;i++){
      for(j=0;j<cols;j++){
          printf("%d ", sum[i][j]);
      }
      printf("\n");
  }

  // Matrix multiplication
  printf("\nMultiplying Matrix 1 and Matrix 2...\n");
  int k, temp;
  for(i=0;i<rows;i++){
      for(j=0;j<cols;j++){
          temp = 0;
          for(k=0;k<cols;k++){
              temp += matrix1[i][k] * matrix2[k][j];
          }
          product[i][j] = temp;
      }
  }

  printf("\nMatrix 1 * Matrix 2 is:\n");
  for(i=0;i<rows;i++){
      for(j=0;j<cols;j++){
          printf("%d ", product[i][j]);
      }
      printf("\n");
  }

  // Matrix transpose
  printf("\nFinding the transpose of Matrix 1...\n");
  int **transpose;
  transpose = (int **)malloc(cols * sizeof(int *));
  
  for(i=0;i<cols;i++){
      transpose[i] = (int *)malloc(rows * sizeof(int));
  }
  
  for(i=0;i<rows;i++){
      for(j=0;j<cols;j++){
          transpose[j][i] = matrix1[i][j];
      }
  }
  
  printf("\nThe transpose of Matrix 1 is:\n");
  for(i=0;i<cols;i++){
      for(j=0;j<rows;j++){
          printf("%d ",transpose[i][j]);
      }
      printf("\n");
  }

  // Freeing memory
  for(i=0;i<rows;i++){
      free(matrix1[i]);
      free(matrix2[i]);
      free(sum[i]);
      free(product[i]);
  }
  free(matrix1);
  free(matrix2);
  free(sum);
  free(product);
  for(i=0;i<cols;i++){
      free(transpose[i]);
  }
  free(transpose);

  return 0;
}