//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 10
#define MAX_COLS 10

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
    mat->matrix = (int **)malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++) {
        mat->matrix[i] = (int *)malloc(sizeof(int) * cols);
        for (int j = 0; j < cols; j++) {
            mat->matrix[i][j] = (i + j) % 2 == 0 ? 1 : 0;
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
    matrix_t *result = create_matrix(mat1->rows, mat2->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
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

int main() {
    matrix_t *mat1 = create_matrix(3, 3);
    matrix_t *mat2 = create_matrix(3, 4);
    matrix_t *result = add_matrices(mat1, mat2);
    print_matrix(result);

    matrix_t *mat3 = create_matrix(4, 3);
    result = multiply_matrix_by_scalar(mat3, 2);
    print_matrix(result);

    return 0;
}