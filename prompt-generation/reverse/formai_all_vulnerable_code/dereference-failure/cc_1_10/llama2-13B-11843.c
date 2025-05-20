//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 5
#define COLS 6

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **matrix;
} matrix_t;

// Function to create a matrix
matrix_t *create_matrix(int rows, int cols) {
    matrix_t *mat = (matrix_t *)malloc(sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat->matrix[i] = (int *)malloc(cols * sizeof(int));
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
    int rows1 = mat1->rows;
    int cols1 = mat1->cols;
    int rows2 = mat2->rows;
    int cols2 = mat2->cols;
    matrix_t *result = create_matrix(rows1 + rows2, cols1 + cols2);

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            result->matrix[i][j] = mat1->matrix[i][j] + mat2->matrix[i][j];
        }
    }

    for (int i = rows1; i < rows1 + rows2; i++) {
        for (int j = 0; j < cols1 + cols2; j++) {
            result->matrix[i][j] = mat1->matrix[i][j] + mat2->matrix[i][j];
        }
    }

    return result;
}

// Function to multiply a matrix by a scalar
matrix_t *multiply_matrix_by_scalar(matrix_t *mat, int scalar) {
    matrix_t *result = create_matrix(mat->rows, mat->cols);

    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            result->matrix[i][j] = mat->matrix[i][j] * scalar;
        }
    }

    return result;
}

// Function to transpose a matrix
matrix_t *transpose_matrix(matrix_t *mat) {
    matrix_t *result = create_matrix(mat->rows, mat->cols);

    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            result->matrix[i][j] = mat->matrix[j][i];
        }
    }

    return result;
}

int main() {
    matrix_t *mat1 = create_matrix(ROWS, COLS);
    matrix_t *mat2 = create_matrix(ROWS, COLS);
    matrix_t *result = add_matrices(mat1, mat2);
    print_matrix(result);

    result = multiply_matrix_by_scalar(mat1, 2);
    print_matrix(result);

    result = transpose_matrix(mat1);
    print_matrix(result);

    return 0;
}