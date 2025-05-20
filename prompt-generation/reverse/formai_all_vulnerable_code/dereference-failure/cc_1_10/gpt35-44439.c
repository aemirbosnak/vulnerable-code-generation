//FormAI DATASET v1.0 Category: Matrix operations ; Style: lively
#include <stdio.h>
#include <stdlib.h>

void printMatrix(int **matrix, int rows, int cols) {
    // Function to print out matrix values
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int ** createMatrix(int rows, int cols) {
    // Function to create matrix of the given size
    int ** matrix = (int **) malloc(rows * sizeof(int *));
    for(int i = 0; i < rows; i++) {
        matrix[i] = (int *) malloc(cols * sizeof(int));
    }
    return matrix;
}

void freeMatrix(int **matrix, int rows) {
  // Function to free the memory allocated to matrix
    for(int i = 0; i < rows; i++) {
      free(matrix[i]);
    }
    free(matrix);
}

int ** transposeMatrix(int **matrix, int rows, int cols) {
  // Function to transpose the matrix
    int **transpose = createMatrix(cols, rows);
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            transpose[i][j] = matrix[j][i];
        }
    }
    return transpose;
}

int ** multiplyMatrix(int **matrix1, int rows1, int cols1, int **matrix2, int rows2, int cols2) {
    // Function to multiply 2 matrices
    if(cols1 != rows2) {
        printf("Matrix multiplication not possible\n");
        return NULL;
    }
    int ** result = createMatrix(rows1, cols2);
    for(int i = 0; i < rows1; i++) {
        for(int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for(int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}

int main() {
    printf("Welcome to the Matrix Operations program!\n\n");
    printf("We are going to create a 3x3 matrix and perform some operations on it.\n\n");

    int rows = 3;
    int cols = 3;
    int **matrix = createMatrix(rows, cols);

    printf("Enter values for the matrix:\n");

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("The matrix you entered is:\n");
    printMatrix(matrix, rows, cols);

    printf("\n");

    printf("The transpose of the matrix is:\n");
    int **transpose = transposeMatrix(matrix, rows, cols);
    printMatrix(transpose, cols, rows);
    freeMatrix(transpose, cols);

    printf("\n");

    printf("Let's multiply the matrix with its transpose:\n");
    int **product = multiplyMatrix(matrix, rows, cols, matrix, rows, cols);
    printMatrix(product, rows, rows);
    freeMatrix(product, rows);
    
    freeMatrix(matrix, rows);

    printf("\nThank you for using the Matrix Operations program! Have a nice day :)\n");
    return 0;
}