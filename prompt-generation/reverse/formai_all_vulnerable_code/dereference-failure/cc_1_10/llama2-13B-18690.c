//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 5

// Structure to store matrix data
typedef struct {
    int rows;
    int cols;
    int **data;
} matrix_t;

// Function to print matrix elements
void print_matrix(matrix_t *mat) {
    int i, j;
    for (i = 0; i < mat->rows; i++) {
        for (j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i][j]);
        }
        printf("\n");
    }
}

// Function to initialize matrix
matrix_t *init_matrix(int rows, int cols) {
    matrix_t *mat = (matrix_t *)calloc(1, sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (int **)calloc(mat->rows, sizeof(int *));
    for (int i = 0; i < mat->rows; i++) {
        mat->data[i] = (int *)calloc(mat->cols, sizeof(int));
    }
    return mat;
}

// Function to add two matrices
matrix_t *add_matrices(matrix_t *mat1, matrix_t *mat2) {
    matrix_t *result = init_matrix(mat1->rows, mat2->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            result->data[i][j] = mat1->data[i][j] + mat2->data[i][j];
        }
    }
    return result;
}

// Function to multiply a matrix by a scalar
matrix_t *scale_matrix(matrix_t *mat, int factor) {
    matrix_t *result = init_matrix(mat->rows, mat->cols);
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            result->data[i][j] = mat->data[i][j] * factor;
        }
    }
    return result;
}

int main() {
    matrix_t *mat1 = init_matrix(M, M);
    matrix_t *mat2 = init_matrix(M, M);
    matrix_t *result = NULL;

    // Initialize matrix elements
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            mat1->data[i][j] = i * j;
            mat2->data[i][j] = i + j;
        }
    }

    // Add matrices
    result = add_matrices(mat1, mat2);

    // Scale matrix
    result = scale_matrix(result, 2);

    // Print result
    print_matrix(result);

    return 0;
}