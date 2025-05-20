//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory for a matrix
double** createMatrix(int rows, int cols) {
    double **matrix = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (double*)malloc(cols * sizeof(double));
    }
    return matrix;
}

// Function to free memory allocated for a matrix
void freeMatrix(double **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to populate a matrix with random values
void populateMatrix(double **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = (double)(rand() % 100);  // Random values between 0-99
        }
    }
}

// Function to print a matrix
void printMatrix(double **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%6.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
double** addMatrices(double **A, double **B, int rows, int cols) {
    double **result = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

// Function to multiply two matrices
double** multiplyMatrices(double **A, double **B, int A_rows, int A_cols, int B_cols) {
    double **result = createMatrix(A_rows, B_cols);
    for (int i = 0; i < A_rows; i++) {
        for (int j = 0; j < B_cols; j++) {
            result[i][j] = 0;
            for (int k = 0; k < A_cols; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

// Function to transpose a matrix
double** transposeMatrix(double **matrix, int rows, int cols) {
    double **transposed = createMatrix(cols, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
    return transposed;
}

int main() {
    int rows, cols;
    printf("Enter the number of rows and columns for the matrix: ");
    scanf("%d %d", &rows, &cols);

    double **A = createMatrix(rows, cols);
    double **B = createMatrix(rows, cols);
    
    // Populate matrices A and B
    populateMatrix(A, rows, cols);
    populateMatrix(B, rows, cols);
    
    // Print Matrices
    printf("Matrix A:\n");
    printMatrix(A, rows, cols);
    
    printf("\nMatrix B:\n");
    printMatrix(B, rows, cols);
    
    // Add Matrices
    double **sum = addMatrices(A, B, rows, cols);
    printf("\nSum of A and B:\n");
    printMatrix(sum, rows, cols);
    
    // Transpose Matrix A
    double **transposedA = transposeMatrix(A, rows, cols);
    printf("\nTranspose of Matrix A:\n");
    printMatrix(transposedA, cols, rows);
    
    // Multiply Matrices A and B
    double **product = multiplyMatrices(A, B, rows, cols, cols);
    printf("\nProduct of A and B:\n");
    printMatrix(product, rows, cols);
    
    // Free allocated memory
    freeMatrix(A, rows);
    freeMatrix(B, rows);
    freeMatrix(sum, rows);
    freeMatrix(transposedA, cols);
    freeMatrix(product, rows);

    return 0;
}