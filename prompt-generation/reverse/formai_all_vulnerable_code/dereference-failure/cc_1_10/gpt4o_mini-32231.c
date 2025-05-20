//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// Define a complex number structure
typedef struct {
    double real;
    double imag;
} Complex;

// Function to add two complex matrices
void addMatrices(Complex **a, Complex **b, Complex **result, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[i][j].real = a[i][j].real + b[i][j].real;
            result[i][j].imag = a[i][j].imag + b[i][j].imag;
        }
    }
}

// Function to subtract two complex matrices
void subtractMatrices(Complex **a, Complex **b, Complex **result, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[i][j].real = a[i][j].real - b[i][j].real;
            result[i][j].imag = a[i][j].imag - b[i][j].imag;
        }
    }
}

// Function to multiply two complex matrices
void multiplyMatrices(Complex **a, Complex **b, Complex **result, int rowsA, int colsA, int colsB) {
    for(int i = 0; i < rowsA; i++) {
        for(int j = 0; j < colsB; j++) {
            result[i][j].real = 0;
            result[i][j].imag = 0;
            for(int k = 0; k < colsA; k++) {
                result[i][j].real += a[i][k].real * b[k][j].real - a[i][k].imag * b[k][j].imag;
                result[i][j].imag += a[i][k].real * b[k][j].imag + a[i][k].imag * b[k][j].real;
            }
        }
    }
}

// Function to transpose a complex matrix
void transposeMatrix(Complex **a, Complex **result, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[j][i].real = a[i][j].real;
            result[j][i].imag = a[i][j].imag;
        }
    }
}

// Function to allocate memory for a matrix
Complex** allocateMatrix(int rows, int cols) {
    Complex **matrix = (Complex**)malloc(rows * sizeof(Complex*));
    for(int i = 0; i < rows; i++) {
        matrix[i] = (Complex*)malloc(cols * sizeof(Complex));
    }
    return matrix;
}

// Function to free memory for a matrix
void freeMatrix(Complex **matrix, int rows) {
    for(int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to print a complex matrix
void printMatrix(Complex **matrix, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("(%lf, %lf) ", matrix[i][j].real, matrix[i][j].imag);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;

    // Input matrix dimensions
    printf("Enter the number of rows and columns for the matrices: ");
    scanf("%d %d", &rows, &cols);

    // Memory allocation for matrices
    Complex **matrixA = allocateMatrix(rows, cols);
    Complex **matrixB = allocateMatrix(rows, cols);
    Complex **result = allocateMatrix(rows, cols);

    // Input for matrix A
    printf("Enter elements of matrix A (real imag):\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("A[%d][%d]: ", i + 1, j + 1);
            scanf("%lf %lf", &matrixA[i][j].real, &matrixA[i][j].imag);
        }
    }

    // Input for matrix B
    printf("Enter elements of matrix B (real imag):\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("B[%d][%d]: ", i + 1, j + 1);
            scanf("%lf %lf", &matrixB[i][j].real, &matrixB[i][j].imag);
        }
    }

    // Performing matrix operations
    addMatrices(matrixA, matrixB, result, rows, cols);
    printf("Sum of matrices A and B:\n");
    printMatrix(result, rows, cols);

    subtractMatrices(matrixA, matrixB, result, rows, cols);
    printf("Difference of matrices A and B:\n");
    printMatrix(result, rows, cols);

    Complex **matrixC = allocateMatrix(cols, rows); // For multiplication
    multiplyMatrices(matrixA, matrixB, result, rows, cols, cols);
    printf("Product of matrices A and B:\n");
    printMatrix(result, rows, cols);

    transposeMatrix(matrixA, matrixC, rows, cols);
    printf("Transpose of matrix A:\n");
    printMatrix(matrixC, cols, rows);

    // Free allocated memory
    freeMatrix(matrixA, rows);
    freeMatrix(matrixB, rows);
    freeMatrix(result, rows);
    freeMatrix(matrixC, cols);

    return 0;
}