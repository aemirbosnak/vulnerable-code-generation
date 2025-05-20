//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int** createMatrix(int rows, int cols);
void freeMatrix(int** matrix, int rows);
void printMatrix(int** matrix, int rows, int cols);
int** matrixAddition(int** A, int** B, int rows, int cols);
int** matrixMultiplication(int** A, int** B, int Arows, int Acols, int Brows);
int** transposeMatrix(int** matrix, int rows, int cols);

int main() {
    int rowsA, colsA, rowsB, colsB;

    // Read dimensions for matrix A
    printf("Enter number of rows for Matrix A: ");
    scanf("%d", &rowsA);
    printf("Enter number of columns for Matrix A: ");
    scanf("%d", &colsA);
    
    // Create and populate matrix A
    int** A = createMatrix(rowsA, colsA);
    printf("Enter elements for Matrix A:\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    
    // Read dimensions for matrix B
    printf("Enter number of rows for Matrix B: ");
    scanf("%d", &rowsB);
    printf("Enter number of columns for Matrix B: ");
    scanf("%d", &colsB);
    
    // Create and populate matrix B
    int** B = createMatrix(rowsB, colsB);
    printf("Enter elements for Matrix B:\n");
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Display matrices
    printf("Matrix A:\n");
    printMatrix(A, rowsA, colsA);
    
    printf("Matrix B:\n");
    printMatrix(B, rowsB, colsB);

    // Matrix Addition
    if (rowsA == rowsB && colsA == colsB) {
        int** sum = matrixAddition(A, B, rowsA, colsA);
        printf("Sum of Matrix A and B:\n");
        printMatrix(sum, rowsA, colsA);
        freeMatrix(sum, rowsA);
    } else {
        printf("Matrix addition is not possible due to incompatible dimensions.\n");
    }

    // Matrix Multiplication
    if (colsA == rowsB) {
        int** product = matrixMultiplication(A, B, rowsA, colsA, rowsB);
        printf("Product of Matrix A and B:\n");
        printMatrix(product, rowsA, colsB);
        freeMatrix(product, rowsA);
    } else {
        printf("Matrix multiplication is not possible due to incompatible dimensions.\n");
    }   

    // Transpose of matrix A
    int** transposedA = transposeMatrix(A, rowsA, colsA);
    printf("Transpose of Matrix A:\n");
    printMatrix(transposedA, colsA, rowsA);
    freeMatrix(transposedA, colsA);

    // Free allocated memory
    freeMatrix(A, rowsA);
    freeMatrix(B, rowsB);

    return 0;
}

int** createMatrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    return matrix;
}

void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int** matrixAddition(int** A, int** B, int rows, int cols) {
    int** result = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

int** matrixMultiplication(int** A, int** B, int Arows, int Acols, int Brows) {
    int** result = createMatrix(Arows, Brows);
    for (int i = 0; i < Arows; i++) {
        for (int j = 0; j < Brows; j++) {
            result[i][j] = 0;
            for (int k = 0; k < Acols; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

int** transposeMatrix(int** matrix, int rows, int cols) {
    int** transposed = createMatrix(cols, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
    return transposed;
}