//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Matrix operations

// Define a structure for a matrix
typedef struct {
    int rows;
    int cols;
    int *data;
} matrix_t;

// Create a matrix
matrix_t *create_matrix(int rows, int cols) {
    matrix_t *mat = malloc(sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = malloc(sizeof(int) * rows * cols);
    return mat;
}

// Print a matrix
void print_matrix(matrix_t *mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i * mat->cols + j]);
        }
        printf("\n");
    }
}

// Add two matrices
matrix_t *add_matrices(matrix_t *a, matrix_t *b) {
    matrix_t *result = create_matrix(a->rows, b->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            result->data[i * result->cols + j] = a->data[i * a->cols + j] + b->data[i * b->cols + j];
        }
    }
    return result;
}

// Multiply a matrix by a scalar
matrix_t *multiply_matrix_by_scalar(matrix_t *mat, int scalar) {
    matrix_t *result = create_matrix(mat->rows, mat->cols);
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            result->data[i * result->cols + j] = scalar * mat->data[i * mat->cols + j];
        }
    }
    return result;
}

int main() {
    matrix_t *a = create_matrix(3, 4);
    matrix_t *b = create_matrix(3, 3);
    matrix_t *c = add_matrices(a, b);
    matrix_t *d = multiply_matrix_by_scalar(c, 2);
    print_matrix(d);
    return 0;
}