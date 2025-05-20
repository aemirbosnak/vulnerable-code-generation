//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: scalable
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
    matrix_t *mat = malloc(sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++) {
        mat->data[i] = malloc(sizeof(int) * cols);
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
    int rows1 = mat1->rows, rows2 = mat2->rows;
    int cols1 = mat1->cols, cols2 = mat2->cols;
    matrix_t *result = create_matrix(rows1 + rows2, cols1 + cols2);

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            result->data[i][j] = mat1->data[i][j] + mat2->data[i][j];
        }
    }

    return result;
}

// Function to multiply a matrix by a scalar
matrix_t *scalar_mult(matrix_t *mat, int scalar) {
    int rows = mat->rows, cols = mat->cols;
    matrix_t *result = create_matrix(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result->data[i][j] = scalar * mat->data[i][j];
        }
    }

    return result;
}

int main() {
    matrix_t *mat1 = create_matrix(3, 4);
    matrix_t *mat2 = create_matrix(2, 3);
    matrix_t *result = add_matrices(mat1, mat2);
    print_matrix(result);

    matrix_t *result2 = scalar_mult(mat1, 2);
    print_matrix(result2);

    return 0;
}