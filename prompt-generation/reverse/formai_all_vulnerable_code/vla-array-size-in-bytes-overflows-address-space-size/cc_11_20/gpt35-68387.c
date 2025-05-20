//FormAI DATASET v1.0 Category: Matrix operations ; Style: immersive
/* Welcome, user! I am your enthusiastic C matrix operations program.
 * I can perform various matrix operations like addition, subtraction, multiplication, and transpose.
 * So, let's dive into a mesmerizing journey of matrices.
 */

#include <stdio.h>

int main() {
  // First, let's get the dimensions of our matrices from the user
  int n, m;
  printf("Hey there! How many rows and columns do your matrices have?\n");
  printf("Enter number of rows: ");
  scanf("%d", &n);
  printf("Enter number of columns: ");
  scanf("%d", &m);

  // Now, let's create our matrices and initialize them with the user's input values
  int matrix_A[n][m], matrix_B[n][m], result[n][m];
  printf("Please enter the elements of Matrix A:\n");
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      scanf("%d", &matrix_A[i][j]);
    }
  }
  printf("Please enter the elements of Matrix B:\n");
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      scanf("%d", &matrix_B[i][j]);
    }
  }

  // Let's start with matrix addition
  printf("\n===== Matrix Addition =====\n");
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      result[i][j] = matrix_A[i][j] + matrix_B[i][j];
      printf("%d ", result[i][j]);
    }
    printf("\n");
  }

  // Moving on to matrix subtraction
  printf("\n===== Matrix Subtraction =====\n");
  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      result[i][j] = matrix_A[i][j] - matrix_B[i][j];
      printf("%d ", result[i][j]);
    }
    printf("\n");
  }

  // Now, let's perform matrix multiplication but only if the dimensions are appropriate 
  if (n==m) {
    printf("\n===== Matrix Multiplication =====\n");
    for (int i=0; i<n; i++) {
      for (int j=0; j<m; j++) {
        result[i][j] = 0;
        for (int k=0; k<n; k++) {
          result[i][j] += matrix_A[i][k] * matrix_B[k][j];
        }
        printf("%d ", result[i][j]);
      }
      printf("\n");
    }
  } else {
    printf("\nMatrix multiplication not possible with these dimensions.");
  }

  // Finally, matrix transposition
  printf("\n===== Matrix Transpose =====\n");
  for (int i=0; i<m; i++) {
    for (int j=0; j<n; j++) {
      printf("%d ", matrix_A[j][i]);
    }
    printf("\n");
  }

  // That's all folks!
  return 0;
}