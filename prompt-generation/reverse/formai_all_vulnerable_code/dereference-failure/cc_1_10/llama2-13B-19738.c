//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW_SIZE 4
#define COL_SIZE 4

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **matrix;
} matrix_t;

// Function to create a new matrix
matrix_t *new_matrix(int rows, int cols) {
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
    matrix_t *result = new_matrix(mat1->rows, mat2->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            int sum = mat1->matrix[i][j] + mat2->matrix[i][j];
            result->matrix[i][j] = sum % 10;
        }
    }
    return result;
}

// Function to multiply a matrix by a scalar
matrix_t *scale_matrix(matrix_t *mat, int scalar) {
    matrix_t *result = new_matrix(mat->rows, mat->cols);
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            result->matrix[i][j] = scalar * mat->matrix[i][j];
        }
    }
    return result;
}

int main() {
    matrix_t *mat1 = new_matrix(3, 4);
    matrix_t *mat2 = new_matrix(2, 4);
    matrix_t *result1 = add_matrices(mat1, mat2);
    matrix_t *result2 = scale_matrix(mat1, 2);

    print_matrix(mat1);
    print_matrix(mat2);
    print_matrix(result1);
    print_matrix(result2);

    return 0;
}