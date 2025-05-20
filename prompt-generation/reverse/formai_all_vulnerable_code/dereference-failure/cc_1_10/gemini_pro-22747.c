//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: shocked
// Prepare for the Matrix Extravaganza!

#include <stdlib.h>
#include <stdio.h>

// We're dealing with matrices, so let's define them
typedef int** Matrix;

// Function to create a matrix with given dimensions
Matrix createMatrix(int rows, int cols) {
    Matrix matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    return matrix;
}

// Function to print a matrix
void printMatrix(Matrix matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices of same size
Matrix addMatrices(Matrix matrix1, Matrix matrix2, int rows, int cols) {
    Matrix result = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

// Function to multiply two matrices
Matrix multiplyMatrices(Matrix matrix1, Matrix matrix2, int rows1, int cols1, int rows2, int cols2) {
    if (cols1 != rows2) {
        printf("Matrix multiplication not possible due to incompatible dimensions.\n");
        return NULL;
    }
    Matrix result = createMatrix(rows1, cols2);
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}

// Get ready for the grand finale: Matrix Transpose!
Matrix transposeMatrix(Matrix matrix, int rows, int cols) {
    Matrix transpose = createMatrix(cols, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
    return transpose;
}

// And now, let's orchestrate our matrix operations!
int main() {
    printf("Behold, the Matrix Matrix!");
    
    // Create two matrices for our dramatic performance
    int rows1 = 3, cols1 = 4, rows2 = 4, cols2 = 3;
    Matrix matrix1 = createMatrix(rows1, cols1);
    Matrix matrix2 = createMatrix(rows2, cols2);
    
    // Fill them with electrifying values
    printf("Matrix 1: Electrify with these values:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            scanf("%d ", &matrix1[i][j]);
        }
    }
    
    printf("Matrix 2: Time to charge it up:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            scanf("%d ", &matrix2[i][j]);
        }
    }
    
    // Let the sparks fly with matrix addition
    Matrix additionResult = addMatrices(matrix1, matrix2, rows1, cols1);
    printf("Witness the electrifying union: Matrix Addition!\n");
    printMatrix(additionResult, rows1, cols1);
    
    // Unleash the power of matrix multiplication
    Matrix multiplicationResult = multiplyMatrices(matrix1, matrix2, rows1, cols1, rows2, cols2);
    if (multiplicationResult) {
        printf("Prepare for the cosmic dance: Matrix Multiplication!\n");
        printMatrix(multiplicationResult, rows1, cols2);
    }
    
    // Time for a magical transformation: Matrix Transpose
    Matrix transposeResult1 = transposeMatrix(matrix1, rows1, cols1);
    Matrix transposeResult2 = transposeMatrix(matrix2, rows2, cols2);
    printf("Behold the mind-bending Matrix Transpose:\n");
    printf("Matrix 1 Transposed:\n");
    printMatrix(transposeResult1, cols1, rows1);
    printf("Matrix 2 Transposed:\n");
    printMatrix(transposeResult2, cols2, rows2);
    
    // Release the matrices from their computational captivity
    free(matrix1);
    free(matrix2);
    free(additionResult);
    free(multiplicationResult);
    free(transposeResult1);
    free(transposeResult2);
    
    return 0;
}