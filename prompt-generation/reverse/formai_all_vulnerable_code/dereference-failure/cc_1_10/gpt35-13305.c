//FormAI DATASET v1.0 Category: Matrix operations ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

void printMatrix(int rows, int columns, int matrix[rows][columns]);
void addMatrix(int rows, int columns, int matrix1[rows][columns], int matrix2[rows][columns], int result[rows][columns]);
void scalarMultiplyMatrix(int rows, int columns, int matrix[rows][columns], int scalar, int result[rows][columns]);
void matrixMultiply(int rows1, int columns1, int matrix1[rows1][columns1], int rows2, int columns2, int matrix2[rows2][columns2], int result[rows1][columns2]);
void transposeMatrix(int rows, int columns, int matrix[rows][columns], int result[columns][rows]);

int main() {
    int matrix1[3][3] = {{1,2,3},{4,5,6},{7,8,9}}; // Sample 3x3 matrix
    int matrix2[3][3] = {{9,8,7},{6,5,4},{3,2,1}}; // Sample 3x3 matrix
    
    printf("Matrix A:\n");
    printMatrix(3, 3, matrix1); // Print matrix A
    printf("\nMatrix B:\n");
    printMatrix(3, 3, matrix2); // Print matrix B
    
    int result1[3][3]; // Result Matrix will hold the result of matrix addition
    addMatrix(3, 3, matrix1, matrix2, result1); // Add Matrix A and Matrix B
    printf("\nMatrix A + B:\n");
    printMatrix(3, 3, result1); // Print A+B
    
    int scalar = 2; // Scalar for matrix multiplication
    int result2[3][3]; // Result Matrix will hold the result of scalar multiplication
    scalarMultiplyMatrix(3, 3, matrix1, scalar, result2); // Multiply matrix A with scalar
    printf("\n%d * Matrix A:\n", scalar);
    printMatrix(3, 3, result2); // Print scalar*A
    
    int matrix3[3][2] = {{1,2},{3,4},{5,6}}; // Sample 3X2 matrix
    int result3[3][2]; // Result Matrix will hold the multiplication of matrix A and matrix C
    matrixMultiply(3, 3, matrix1, 3, 2, matrix3, result3); // Multiply matrix A and C
    printf("\nMatrix A * Matrix C:\n");
    printMatrix(3, 2, result3); // Print A*C
    
    int result4[3][3]; // Result Matrix will hold the transpose of matrix A
    transposeMatrix(3, 3, matrix1, result4); // Transpose matrix A
    printf("\nA Transpose:\n");
    printMatrix(3, 3, result4); // Print A transpose
    
    return 0;
}

void printMatrix(int rows, int columns, int matrix[rows][columns]) {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int rows, int columns, int matrix1[rows][columns], int matrix2[rows][columns], int result[rows][columns]) {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void scalarMultiplyMatrix(int rows, int columns, int matrix[rows][columns], int scalar, int result[rows][columns]) {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++) {
            result[i][j] = scalar * matrix[i][j];
        }
    }
}

void matrixMultiply(int rows1, int columns1, int matrix1[rows1][columns1], int rows2, int columns2, int matrix2[rows2][columns2], int result[rows1][columns2]) {
    if (columns1 != rows2) {
        printf("Matrix multiplication not possible\n");
        return;
    }
    for (int i=0; i<rows1; i++) {
        for (int j=0; j<columns2; j++) {
            result[i][j] = 0;
            for (int k=0; k<columns1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void transposeMatrix(int rows, int columns, int matrix[rows][columns], int result[columns][rows]) {
    for (int i=0; i<columns; i++) {
        for (int j=0; j<rows; j++) {
            result[i][j] = matrix[j][i];
        }
    }
}