//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 10
#define COLS 10

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int *data;
} matrix_t;

// Function to create a new matrix
matrix_t *new_matrix(int rows, int cols) {
    matrix_t *mat = (matrix_t *) malloc(sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (int *) malloc(sizeof(int) * rows * cols);
    return mat;
}

// Function to print a matrix
void print_matrix(matrix_t *mat) {
    int i, j;
    for (i = 0; i < mat->rows; i++) {
        for (j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i * mat->cols + j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
matrix_t *add_matrices(matrix_t *mat1, matrix_t *mat2) {
    matrix_t *result = new_matrix(mat1->rows, mat2->cols);
    int i, j, k;
    for (i = 0; i < mat1->rows; i++) {
        for (j = 0; j < mat2->cols; j++) {
            int sum = mat1->data[i * mat1->cols + j] + mat2->data[j];
            result->data[i * result->cols + j] = sum;
        }
    }
    return result;
}

// Function to multiply a matrix by a scalar
matrix_t *scale_matrix(matrix_t *mat, int scale) {
    matrix_t *result = new_matrix(mat->rows, mat->cols);
    int i, j;
    for (i = 0; i < mat->rows; i++) {
        for (j = 0; j < mat->cols; j++) {
            result->data[i * result->cols + j] = scale * mat->data[i * mat->cols + j];
        }
    }
    return result;
}

int main() {
    matrix_t *mat1 = new_matrix(ROWS, COLS);
    matrix_t *mat2 = new_matrix(ROWS, COLS);
    matrix_t *result;

    // Initialize matrix elements
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            mat1->data[i * mat1->cols + j] = i * j;
            mat2->data[i * mat2->cols + j] = i * j + 1;
        }
    }

    // Add matrices
    result = add_matrices(mat1, mat2);
    print_matrix(result);

    // Scale matrix
    result = scale_matrix(result, 2);
    print_matrix(result);

    return 0;
}