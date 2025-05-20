//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: random
#include <stdio.h>
#include <stdlib.h>

// Matrix structure
typedef struct {
    int rows;
    int cols;
    int **data;
} Matrix;

// Function to create a matrix
Matrix createMatrix(int rows, int cols) {
    Matrix mat;
    mat.rows = rows;
    mat.cols = cols;
    mat.data = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat.data[i] = malloc(cols * sizeof(int));
    }
    return mat;
}

// Function to free a matrix
void freeMatrix(Matrix mat) {
    for (int i = 0; i < mat.rows; i++) {
        free(mat.data[i]);
    }
    free(mat.data);
}

// Function to fill a matrix with random values
void fillMatrix(Matrix mat) {
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            mat.data[i][j] = rand() % 10; // Random values from 0 to 9
        }
    }
}

// Function to print a matrix
void printMatrix(Matrix mat) {
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            printf("%d ", mat.data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to add two matrices
Matrix addMatrices(Matrix a, Matrix b) {
    if (a.rows != b.rows || a.cols != b.cols) {
        fprintf(stderr, "Error: Matrices dimensions must match for addition!\n");
        exit(EXIT_FAILURE);
    }
    Matrix result = createMatrix(a.rows, a.cols);
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            result.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    return result;
}

// Function to multiply two matrices
Matrix multiplyMatrices(Matrix a, Matrix b) {
    if (a.cols != b.rows) {
        fprintf(stderr, "Error: Incompatible matrices for multiplication!\n");
        exit(EXIT_FAILURE);
    }
    Matrix result = createMatrix(a.rows, b.cols);
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < a.cols; k++) {
                result.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return result;
}

// Function to transpose a matrix
Matrix transposeMatrix(Matrix mat) {
    Matrix transposed = createMatrix(mat.cols, mat.rows);
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            transposed.data[j][i] = mat.data[i][j];
        }
    }
    return transposed;
}

// Main function to demonstrate matrix operations
int main() {
    srand(time(NULL));

    // Create and fill two matrices
    Matrix matA = createMatrix(3, 2);
    Matrix matB = createMatrix(2, 3);

    fillMatrix(matA);
    fillMatrix(matB);

    printf("Matrix A (3x2):\n");
    printMatrix(matA);
    
    printf("Matrix B (2x3):\n");
    printMatrix(matB);

    // Adding two matrices (must be the same dimension)
    Matrix matC = addMatrices(matA, createMatrix(matA.rows, matA.cols));
    printf("Matrix C (A + A):\n");
    printMatrix(matC);

    // Multiplying matrices A and B
    Matrix matD = multiplyMatrices(matA, matB);
    printf("Matrix D (A * B):\n");
    printMatrix(matD);

    // Transposing matrix A
    Matrix matA_T = transposeMatrix(matA);
    printf("Transposed Matrix A:\n");
    printMatrix(matA_T);

    // Cleanup
    freeMatrix(matA);
    freeMatrix(matB);
    freeMatrix(matC);
    freeMatrix(matD);
    freeMatrix(matA_T);

    return 0;
}