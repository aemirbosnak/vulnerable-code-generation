//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **data;
} matrix_t;

// Function to create a matrix with a given size
matrix_t *create_matrix(int rows, int cols) {
    matrix_t *mat = (matrix_t *)malloc(sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat->data[i] = (int *)malloc(cols * sizeof(int));
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

// Function to subtract one matrix from another
matrix_t *subtract_matrices(matrix_t *mat1, matrix_t *mat2) {
    matrix_t *result = create_matrix(mat1->rows, mat2->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            result->data[i][j] = mat1->data[i][j] - mat2->data[i][j];
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

int main() {
    matrix_t *mat1 = create_matrix(3, 4);
    matrix_t *mat2 = create_matrix(3, 4);
    matrix_t *result;

    // Initialize the matrices
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            mat1->data[i][j] = i * j;
            mat2->data[i][j] = i * j + 1;
        }
    }

    // Add the matrices
    result = add_matrices(mat1, mat2);
    print_matrix(result);

    // Subtract the matrices
    result = subtract_matrices(mat1, mat2);
    print_matrix(result);

    // Multiply a matrix by a scalar
    result = multiply_matrix_by_scalar(mat1, 2);
    print_matrix(result);

    return 0;
}