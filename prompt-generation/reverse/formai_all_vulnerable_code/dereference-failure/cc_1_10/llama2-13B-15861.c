//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **data;
} matrix_t;

// Function to create a matrix
matrix_t *create_matrix(int rows, int cols) {
    matrix_t *matrix = (matrix_t *)calloc(1, sizeof(matrix_t));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (int **)calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = (int *)calloc(cols, sizeof(int));
    }
    return matrix;
}

// Function to print a matrix
void print_matrix(matrix_t *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
matrix_t *add_matrices(matrix_t *matrix1, matrix_t *matrix2) {
    matrix_t *result = create_matrix(matrix1->rows, matrix2->cols);
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix2->cols; j++) {
            result->data[i][j] = matrix1->data[i][j] + matrix2->data[i][j];
        }
    }
    return result;
}

// Function to multiply a matrix by a scalar
matrix_t *multiply_matrix_by_scalar(matrix_t *matrix, int scalar) {
    matrix_t *result = create_matrix(matrix->rows, matrix->cols);
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            result->data[i][j] = matrix->data[i][j] * scalar;
        }
    }
    return result;
}

int main() {
    matrix_t *matrix1 = create_matrix(3, 4);
    matrix_t *matrix2 = create_matrix(3, 2);
    matrix_t *result1 = add_matrices(matrix1, matrix2);
    matrix_t *result2 = multiply_matrix_by_scalar(matrix1, 2);

    print_matrix(matrix1);
    print_matrix(matrix2);
    print_matrix(result1);
    print_matrix(result2);

    return 0;
}