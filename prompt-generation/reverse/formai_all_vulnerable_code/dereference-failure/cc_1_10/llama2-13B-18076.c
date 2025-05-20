//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    int rows;
    int cols;
    int **matrix;
} matrix_t;

// Function to print a matrix
void print_matrix(matrix_t *matrix) {
    int i, j;

    for (i = 0; i < matrix->rows; i++) {
        for (j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
matrix_t *add_matrices(matrix_t *matrix1, matrix_t *matrix2) {
    int i, j;
    matrix_t *result;

    result = (matrix_t *)malloc(sizeof(matrix_t));
    result->rows = matrix1->rows + matrix2->rows;
    result->cols = matrix1->cols + matrix2->cols;
    result->matrix = (int **)malloc(result->rows * sizeof(int *));

    for (i = 0; i < result->rows; i++) {
        result->matrix[i] = (int *)malloc(result->cols * sizeof(int));

        for (j = 0; j < result->cols; j++) {
            result->matrix[i][j] = matrix1->matrix[i][j] + matrix2->matrix[i][j];
        }
    }

    return result;
}

// Function to multiply a matrix by a scalar
matrix_t *scale_matrix(matrix_t *matrix, int scalar) {
    int i, j;
    matrix_t *result;

    result = (matrix_t *)malloc(sizeof(matrix_t));
    result->rows = matrix->rows;
    result->cols = matrix->cols;
    result->matrix = (int **)malloc(result->rows * sizeof(int *));

    for (i = 0; i < result->rows; i++) {
        result->matrix[i] = (int *)malloc(result->cols * sizeof(int));

        for (j = 0; j < result->cols; j++) {
            result->matrix[i][j] = matrix->matrix[i][j] * scalar;
        }
    }

    return result;
}

int main() {
    matrix_t *matrix1, *matrix2, *result;

    // Initialize matrix1
    matrix1 = (matrix_t *)malloc(sizeof(matrix_t));
    matrix1->rows = 5;
    matrix1->cols = 3;
    matrix1->matrix = (int **)malloc(matrix1->rows * sizeof(int *));

    for (int i = 0; i < matrix1->rows; i++) {
        matrix1->matrix[i] = (int *)malloc(matrix1->cols * sizeof(int));

        for (int j = 0; j < matrix1->cols; j++) {
            matrix1->matrix[i][j] = i * j;
        }
    }

    // Initialize matrix2
    matrix2 = (matrix_t *)malloc(sizeof(matrix_t));
    matrix2->rows = 4;
    matrix2->cols = 2;
    matrix2->matrix = (int **)malloc(matrix2->rows * sizeof(int *));

    for (int i = 0; i < matrix2->rows; i++) {
        matrix2->matrix[i] = (int *)malloc(matrix2->cols * sizeof(int));

        for (int j = 0; j < matrix2->cols; j++) {
            matrix2->matrix[i][j] = i * j + 1;
        }
    }

    // Add matrix1 and matrix2
    result = add_matrices(matrix1, matrix2);

    // Print the result
    print_matrix(result);

    // Scale matrix1 by 2
    result = scale_matrix(matrix1, 2);

    // Print the result
    print_matrix(result);

    return 0;
}