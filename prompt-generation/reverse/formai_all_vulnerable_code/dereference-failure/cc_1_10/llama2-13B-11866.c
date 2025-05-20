//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

// Structure to store matrix data
typedef struct {
    int rows;
    int cols;
    int **data;
} matrix_t;

// Function to print matrix
void print_matrix(matrix_t *mat) {
    int i, j;
    for (i = 0; i < mat->rows; i++) {
        for (j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i][j]);
        }
        printf("\n");
    }
}

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

// Function to add two matrices
matrix_t *add_matrices(matrix_t *mat1, matrix_t *mat2) {
    matrix_t *result = create_matrix(mat1->rows, mat2->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            int sum = mat1->data[i][j] + mat2->data[i][j];
            result->data[i][j] = sum % 10;
        }
    }
    return result;
}

// Function to multiply a matrix by a scalar
matrix_t *scale_matrix(matrix_t *mat, int factor) {
    matrix_t *result = create_matrix(mat->rows, mat->cols);
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            result->data[i][j] = mat->data[i][j] * factor;
        }
    }
    return result;
}

int main() {
    matrix_t *mat1 = create_matrix(5, 5);
    matrix_t *mat2 = create_matrix(3, 4);
    matrix_t *result = add_matrices(mat1, mat2);
    print_matrix(result);

    mat1 = create_matrix(5, 5);
    mat2 = create_matrix(4, 3);
    result = add_matrices(mat1, mat2);
    print_matrix(result);

    mat1 = create_matrix(5, 5);
    result = scale_matrix(mat1, 2);
    print_matrix(result);

    return 0;
}