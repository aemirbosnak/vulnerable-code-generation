//FormAI DATASET v1.0 Category: Matrix operations ; Style: grateful
#include <stdio.h>

// A grateful program that performs various matrix operations

void displayMatrix(int rows, int columns, int matrix[rows][columns]) {
    // Displays the contents of the matrix
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void scalarMultiplication(int rows, int columns, int matrix[rows][columns], int scalar) {
    // Multiplies the matrix by a scalar value
    printf("\nScalar multiplication:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] *= scalar;
        }
    }
    displayMatrix(rows, columns, matrix);
}

void matrixAddition(int rows, int columns, int matrix1[rows][columns], int matrix2[rows][columns]) {
    // Adds two matrices and displays the result
    printf("\nMatrix addition:\n");
    int result[rows][columns];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    displayMatrix(rows, columns, result);
}

void matrixMultiplication(int rows1, int columns1, int matrix1[rows1][columns1],
                           int rows2, int columns2, int matrix2[rows2][columns2]) {
    // Multiplies two matrices and displays the result
    printf("\nMatrix multiplication:\n");
    if (columns1 != rows2) {
        printf("Error: Number of columns in the first matrix must be equal to the number of rows in the second matrix.\n");
        return;
    }
    int result[rows1][columns2];
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < columns1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    displayMatrix(rows1, columns2, result);
}

int main() {
    int rows, columns, scalar;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &columns);
    int matrix[rows][columns];
    printf("Enter the contents of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("Enter a scalar value to multiply the matrix by: ");
    scanf("%d", &scalar);
    displayMatrix(rows, columns, matrix);
    scalarMultiplication(rows, columns, matrix, scalar);
    int rows2, columns2;
    printf("\nEnter the number of rows and columns of the second matrix: ");
    scanf("%d %d", &rows2, &columns2);
    int matrix2[rows2][columns2];
    printf("Enter the contents of the second matrix:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < columns2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }
    matrixAddition(rows, columns, matrix, matrix2);
    matrixMultiplication(rows, columns, matrix, rows2, columns2, matrix2);
    return 0;
}