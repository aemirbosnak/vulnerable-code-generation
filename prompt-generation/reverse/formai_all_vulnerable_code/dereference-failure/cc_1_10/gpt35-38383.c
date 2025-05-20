//FormAI DATASET v1.0 Category: Matrix operations ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Define matrix structure
typedef struct Matrix {
    int rows;
    int cols;
    int **data;
} Matrix;

// Allocate memory for matrix
Matrix *matrixAlloc(int rows, int cols) {
    Matrix *matrix = malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = malloc(sizeof(int) * cols);
    }
    return matrix;
}

// Free memory for matrix
void matrixFree(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}

// Fill matrix with random values
void matrixFillRandom(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            matrix->data[i][j] = rand() % 10;
        }
    }
}

// Print matrix
void matrixPrint(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

// Add two matrices
Matrix *matrixAdd(Matrix *matrix1, Matrix *matrix2) {
    if (matrix1->rows != matrix2->rows || matrix1->cols != matrix2->cols) {
        return NULL;
    }
    Matrix *result = matrixAlloc(matrix1->rows, matrix1->cols);
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix1->cols; j++) {
            result->data[i][j] = matrix1->data[i][j] + matrix2->data[i][j];
        }
    }
    return result;
}

int main(void) {
    // Allocate matrices
    Matrix *matrix1 = matrixAlloc(3, 3);
    Matrix *matrix2 = matrixAlloc(3, 3);
    Matrix *matrix3;

    // Fill matrices with random values
    matrixFillRandom(matrix1);
    matrixFillRandom(matrix2);

    // Print matrices
    printf("Matrix 1:\n");
    matrixPrint(matrix1);
    printf("\n");

    printf("Matrix 2:\n");
    matrixPrint(matrix2);
    printf("\n");

    // Add matrices and print result
    matrix3 = matrixAdd(matrix1, matrix2);
    if (matrix3 != NULL) {
        printf("Matrix 1 + Matrix 2:\n");
        matrixPrint(matrix3);
        printf("\n");
    }

    // Free matrices
    matrixFree(matrix1);
    matrixFree(matrix2);
    matrixFree(matrix3);
    return 0;
}