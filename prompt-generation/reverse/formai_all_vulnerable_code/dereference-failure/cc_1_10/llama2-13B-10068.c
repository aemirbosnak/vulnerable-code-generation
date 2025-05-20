//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATRIX_ROWS 4
#define MATRIX_COLS 4

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **data;
} matrix_t;

// Function to create a new matrix
matrix_t *new_matrix(int rows, int cols) {
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
    matrix_t *result = new_matrix(mat1->rows, mat2->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            int sum = mat1->data[i][j] + mat2->data[i][j];
            result->data[i][j] = sum % 10;
        }
    }
    return result;
}

// Function to multiply a matrix by a scalar
matrix_t *scale_matrix(matrix_t *mat, int scale) {
    matrix_t *result = new_matrix(mat->rows, mat->cols);
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            result->data[i][j] = mat->data[i][j] * scale;
        }
    }
    return result;
}

int main() {
    matrix_t *mat1 = new_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *mat2 = new_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *result = add_matrices(mat1, mat2);
    print_matrix(result);

    matrix_t *scaled_mat = scale_matrix(mat1, 2);
    print_matrix(scaled_mat);

    return 0;
}