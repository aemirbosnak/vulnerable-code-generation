//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATRIX_ROWS 5
#define MATRIX_COLS 4

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **matrix;
} matrix_t;

// Function to create a new matrix
matrix_t *new_matrix(int rows, int cols) {
    matrix_t *mat = malloc(sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->matrix = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat->matrix[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            mat->matrix[i][j] = 0;
        }
    }
    return mat;
}

// Function to print a matrix
void print_matrix(matrix_t *mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
matrix_t *add_matrices(matrix_t *mat1, matrix_t *mat2) {
    matrix_t *result = new_matrix(mat1->rows, mat2->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            result->matrix[i][j] = mat1->matrix[i][j] + mat2->matrix[i][j];
        }
    }
    return result;
}

// Function to multiply a matrix by a scalar
matrix_t *multiply_matrix_by_scalar(matrix_t *mat, int scalar) {
    matrix_t *result = new_matrix(mat->rows, mat->cols);
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            result->matrix[i][j] = scalar * mat->matrix[i][j];
        }
    }
    return result;
}

int main() {
    matrix_t *mat1 = new_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *mat2 = new_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *result = add_matrices(mat1, mat2);
    print_matrix(result);

    matrix_t *mat3 = new_matrix(MATRIX_ROWS, MATRIX_COLS);
    result = multiply_matrix_by_scalar(mat3, 2);
    print_matrix(result);

    return 0;
}