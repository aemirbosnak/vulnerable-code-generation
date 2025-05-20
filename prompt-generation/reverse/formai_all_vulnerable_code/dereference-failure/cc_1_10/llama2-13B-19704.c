//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATRIX_ROWS 5
#define MATRIX_COLS 3

typedef struct {
    int rows;
    int cols;
    int **data;
} matrix_t;

// Function to print a matrix
void print_matrix(matrix_t *matrix) {
    int i, j;

    printf("Matrix dimensions: %d x %d\n", matrix->rows, matrix->cols);

    for (i = 0; i < matrix->rows; i++) {
        for (j = 0; j < matrix->cols; j++) {
            printf("%3d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

// Function to create a matrix
matrix_t *create_matrix(int rows, int cols) {
    matrix_t *matrix = (matrix_t *)malloc(sizeof(matrix_t));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (int **)malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; i++) {
        matrix->data[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            matrix->data[i][j] = i * j;
        }
    }

    return matrix;
}

// Function to add two matrices
matrix_t *add_matrices(matrix_t *matrix1, matrix_t *matrix2) {
    matrix_t *result = create_matrix(matrix1->rows, matrix2->cols);

    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix2->cols; j++) {
            result->data[i][j] = matrix1->data[i][0] + matrix2->data[0][j];
        }
    }

    return result;
}

// Function to multiply a matrix by a scalar
matrix_t *scale_matrix(matrix_t *matrix, int factor) {
    matrix_t *result = create_matrix(matrix->rows, matrix->cols);

    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            result->data[i][j] = matrix->data[i][j] * factor;
        }
    }

    return result;
}

int main() {
    matrix_t *matrix1 = create_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *matrix2 = create_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *result = NULL;

    // Initialize matrix1 with some data
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            matrix1->data[i][j] = i * j;
        }
    }

    // Add matrix1 and matrix2
    result = add_matrices(matrix1, matrix2);

    // Print the result
    print_matrix(result);

    // Scale the result by 2
    result = scale_matrix(result, 2);

    // Print the scaled result
    print_matrix(result);

    return 0;
}