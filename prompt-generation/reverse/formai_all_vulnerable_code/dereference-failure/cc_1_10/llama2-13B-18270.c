//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MATRIX_ROWS 5
#define MATRIX_COLS 7

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **data;
} matrix_t;

// Function to initialize a matrix
matrix_t *init_matrix(int rows, int cols) {
    matrix_t *mat = (matrix_t *)malloc(sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat->data[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            mat->data[i][j] = (i + j) % 10;
        }
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

// Function to perform matrix addition
matrix_t *add_matrices(matrix_t *mat1, matrix_t *mat2) {
    matrix_t *result = init_matrix(mat1->rows, mat2->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            int sum = mat1->data[i][j] + mat2->data[i][j];
            result->data[i][j] = sum % 10;
        }
    }
    return result;
}

// Function to perform matrix multiplication
matrix_t *multiply_matrices(matrix_t *mat1, matrix_t *mat2) {
    matrix_t *result = init_matrix(mat1->rows, mat2->cols * mat1->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            int prod = 0;
            for (int k = 0; k < mat1->cols; k++) {
                prod += mat1->data[i][k] * mat2->data[k][j];
            }
            result->data[i][j] = prod % 10;
        }
    }
    return result;
}

int main() {
    matrix_t *mat1 = init_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *mat2 = init_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *result1 = add_matrices(mat1, mat2);
    matrix_t *result2 = multiply_matrices(mat1, mat2);
    print_matrix(result1);
    print_matrix(result2);
    return 0;
}