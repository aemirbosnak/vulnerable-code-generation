//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix {
    int rows;
    int cols;
    int **data;
} Matrix;

Matrix* createMatrix(int rows, int cols) {
    Matrix *matrix = malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = malloc(cols * sizeof(int));
    }
    return matrix;
}

void freeMatrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}

void printMatrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Create two matrices
    Matrix *matrix1 = createMatrix(3, 4);
    Matrix *matrix2 = createMatrix(4, 2);

    // Populate the matrices with some data
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix1->cols; j++) {
            matrix1->data[i][j] = i * matrix1->cols + j;
        }
    }

    for (int i = 0; i < matrix2->rows; i++) {
        for (int j = 0; j < matrix2->cols; j++) {
            matrix2->data[i][j] = i * matrix2->cols + j;
        }
    }

    // Print the matrices
    printf("Matrix 1:\n");
    printMatrix(matrix1);

    printf("Matrix 2:\n");
    printMatrix(matrix2);

    // Multiply the matrices
    Matrix *result = createMatrix(matrix1->rows, matrix2->cols);
    for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->cols; j++) {
            int sum = 0;
            for (int k = 0; k < matrix1->cols; k++) {
                sum += matrix1->data[i][k] * matrix2->data[k][j];
            }
            result->data[i][j] = sum;
        }
    }

    // Print the result
    printf("Result:\n");
    printMatrix(result);

    // Free the matrices
    freeMatrix(matrix1);
    freeMatrix(matrix2);
    freeMatrix(result);

    return 0;
}