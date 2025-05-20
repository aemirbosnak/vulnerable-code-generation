//FormAI DATASET v1.0 Category: Matrix operations ; Style: Ada Lovelace
// This program demonstrates matrix operations in C programming language
// Inspired by Ada Lovelace, the world's first computer programmer

#include <stdio.h>
#include <stdlib.h>

// Matrix struct to hold values and dimensions
typedef struct {
    int** values;
    int rows;
    int cols;
} Matrix;

// Function to create a new matrix with specified dimensions
Matrix createMatrix(int rows, int cols) {
    Matrix matrix;
    matrix.rows = rows;
    matrix.cols = cols;

    // Allocate memory for matrix values
    matrix.values = (int**)malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; i++) {
        matrix.values[i] = (int*)malloc(cols * sizeof(int));
    }

    // Fill matrix with zeros
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            matrix.values[i][j] = 0;
        }
    }

    return matrix;
}

// Function to print a matrix
void printMatrix(Matrix matrix) {
    for(int i = 0; i < matrix.rows; i++) {
        for(int j = 0; j < matrix.cols; j++) {
            printf("%d ", matrix.values[i][j]);
        }
        printf("\n");
    }
}

// Function to perform matrix addition
Matrix addMatrix(Matrix matrix1, Matrix matrix2) {
    Matrix result = createMatrix(matrix1.rows, matrix1.cols);

    for(int i = 0; i < matrix1.rows; i++) {
        for(int j = 0; j < matrix1.cols; j++) {
            result.values[i][j] = matrix1.values[i][j] + matrix2.values[i][j];
        }
    }

    return result;
}

// Function to perform matrix multiplication
Matrix multiplyMatrix(Matrix matrix1, Matrix matrix2) {
    Matrix result = createMatrix(matrix1.rows, matrix2.cols);

    for(int i = 0; i < matrix1.rows; i++) {
        for(int j = 0; j < matrix2.cols; j++) {
            for(int k = 0; k < matrix1.cols; k++) {
                result.values[i][j] += matrix1.values[i][k] * matrix2.values[k][j];
            }
        }
    }

    return result;
}

int main() {
    Matrix matrix1, matrix2, sum, product;
    int rows, cols;

    // Read matrix dimensions from user
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Create two matrices with specified dimensions
    matrix1 = createMatrix(rows, cols);
    matrix2 = createMatrix(rows, cols);

    // Read matrix values from user
    printf("Enter matrix 1 values:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            scanf("%d", &matrix1.values[i][j]);
        }
    }

    printf("Enter matrix 2 values:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            scanf("%d", &matrix2.values[i][j]);
        }
    }

    // Perform matrix operations
    sum = addMatrix(matrix1, matrix2);
    product = multiplyMatrix(matrix1, matrix2);

    // Print results
    printf("Matrix 1:\n");
    printMatrix(matrix1);
    printf("Matrix 2:\n");
    printMatrix(matrix2);
    printf("Matrix sum:\n");
    printMatrix(sum);
    printf("Matrix product:\n");
    printMatrix(product);

    return 0;
}