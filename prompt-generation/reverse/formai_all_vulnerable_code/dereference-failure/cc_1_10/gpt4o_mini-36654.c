//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    double **data;
} Matrix;

// Function to create a matrix
Matrix* createMatrix(int rows, int cols) {
    Matrix *matrix = (Matrix *)malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;

    matrix->data = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = (double *)malloc(cols * sizeof(double));
    }
    
    return matrix;
}

// Function to free a matrix
void freeMatrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}

// Function to fill the matrix with random values
void fillMatrix(Matrix *matrix, int lower, int upper) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            matrix->data[i][j] = lower + (rand() % (upper - lower + 1));
        }
    }
}

// Function to print the matrix
void printMatrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%.2f\t", matrix->data[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
Matrix* addMatrices(Matrix *a, Matrix *b) {
    if (a->rows != b->rows || a->cols != b->cols) {
        fprintf(stderr, "Matrix dimensions do not match for addition!\n");
        exit(EXIT_FAILURE);
    }

    Matrix *result = createMatrix(a->rows, a->cols);
    
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            result->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
    
    return result;
}

// Function to multiply two matrices
Matrix* multiplyMatrices(Matrix *a, Matrix *b) {
    if (a->cols != b->rows) {
        fprintf(stderr, "Matrix dimensions do not match for multiplication!\n");
        exit(EXIT_FAILURE);
    }

    Matrix *result = createMatrix(a->rows, b->cols);
    
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            result->data[i][j] = 0;
            for (int k = 0; k < a->cols; k++) {
                result->data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }
    
    return result;
}

// Function to transpose a matrix
Matrix* transposeMatrix(Matrix *matrix) {
    Matrix *result = createMatrix(matrix->cols, matrix->rows);
    
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            result->data[j][i] = matrix->data[i][j];
        }
    }
    
    return result;
}

int main() {
    int rowsA, colsA, rowsB, colsB;

    // Get dimensions for the first matrix
    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d", &rowsA, &colsA);
    
    // Get dimensions for the second matrix
    printf("Enter rows and columns for second matrix: ");
    scanf("%d %d", &rowsB, &colsB);

    // Create matrices
    Matrix *matrixA = createMatrix(rowsA, colsA);
    Matrix *matrixB = createMatrix(rowsB, colsB);

    // Fill matrices with random values
    fillMatrix(matrixA, 1, 10);
    fillMatrix(matrixB, 1, 10);

    // Print matrices
    printf("Matrix A:\n");
    printMatrix(matrixA);
    
    printf("\nMatrix B:\n");
    printMatrix(matrixB);

    // Matrix addition
    if (rowsA == rowsB && colsA == colsB) {
        Matrix *sumMatrix = addMatrices(matrixA, matrixB);
        printf("\nSum of A and B:\n");
        printMatrix(sumMatrix);
        freeMatrix(sumMatrix);
    } else {
        printf("\nMatrices A and B cannot be added due to dimension mismatch.\n");
    }
    
    // Matrix multiplication
    if (colsA == rowsB) {
        Matrix *productMatrix = multiplyMatrices(matrixA, matrixB);
        printf("\nProduct of A and B:\n");
        printMatrix(productMatrix);
        freeMatrix(productMatrix);
    } else {
        printf("\nMatrices A and B cannot be multiplied due to dimension mismatch.\n");
    }

    // Transpose of matrix A
    Matrix *transposedMatrixA = transposeMatrix(matrixA);
    printf("\nTranspose of Matrix A:\n");
    printMatrix(transposedMatrixA);
    
    // Clean up allocated memory
    freeMatrix(matrixA);
    freeMatrix(matrixB);
    freeMatrix(transposedMatrixA);
    
    return 0;
}