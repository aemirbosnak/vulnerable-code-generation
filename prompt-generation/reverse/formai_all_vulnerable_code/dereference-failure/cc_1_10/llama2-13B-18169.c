//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 4
#define COLS 3

// Structure to store a matrix
typedef struct {
    int rows;
    int cols;
    int **data;
} matrix_t;

// Function to create a matrix
matrix_t *create_matrix(int rows, int cols) {
    matrix_t *mat = (matrix_t *)calloc(1, sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (int **)calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat->data[i] = (int *)calloc(cols, sizeof(int));
    }
    return mat;
}

// Function to print a matrix
void print_matrix(matrix_t *mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
matrix_t *add_matrices(matrix_t *mat1, matrix_t *mat2) {
    matrix_t *result = create_matrix(mat1->rows, mat2->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            result->data[i][j] = mat1->data[i][j] + mat2->data[i][j];
        }
    }
    return result;
}

// Function to multiply a matrix by a scalar
matrix_t *multiply_matrix_by_scalar(matrix_t *mat, int scalar) {
    matrix_t *result = create_matrix(mat->rows, mat->cols);
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            result->data[i][j] = mat->data[i][j] * scalar;
        }
    }
    return result;
}

// Function to transpose a matrix
matrix_t *transpose_matrix(matrix_t *mat) {
    matrix_t *result = create_matrix(mat->cols, mat->rows);
    for (int i = 0; i < mat->cols; i++) {
        for (int j = 0; j < mat->rows; j++) {
            result->data[i][j] = mat->data[j][i];
        }
    }
    return result;
}

int main() {
    matrix_t *mat1 = create_matrix(ROWS, COLS);
    matrix_t *mat2 = create_matrix(ROWS, COLS);
    matrix_t *result1 = add_matrices(mat1, mat2);
    matrix_t *result2 = multiply_matrix_by_scalar(mat1, 2);
    matrix_t *result3 = transpose_matrix(mat1);

    print_matrix(mat1);
    print_matrix(mat2);
    print_matrix(result1);
    print_matrix(result2);
    print_matrix(result3);

    return 0;
}