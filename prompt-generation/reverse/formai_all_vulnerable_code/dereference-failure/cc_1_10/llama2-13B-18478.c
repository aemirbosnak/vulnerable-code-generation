//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **data;
} matrix_t;

// Function to create a matrix
matrix_t *create_matrix(int rows, int cols) {
    matrix_t *mat = (matrix_t *)malloc(sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (int **)malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++) {
        mat->data[i] = (int *)malloc(sizeof(int) * cols);
        for (int j = 0; j < cols; j++) {
            mat->data[i][j] = rand() % 10;
        }
    }
    return mat;
}

// Function to perform matrix multiplication
matrix_t *multiply_matrices(matrix_t *mat1, matrix_t *mat2) {
    matrix_t *result = create_matrix(mat1->rows, mat2->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            int sum = 0;
            for (int k = 0; k < mat1->cols; k++) {
                sum += mat1->data[i][k] * mat2->data[k][j];
            }
            result->data[i][j] = sum;
        }
    }
    return result;
}

// Function to perform matrix addition
matrix_t *add_matrices(matrix_t *mat1, matrix_t *mat2) {
    matrix_t *result = create_matrix(mat1->rows, mat2->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            result->data[i][j] = mat1->data[i][j] + mat2->data[i][j];
        }
    }
    return result;
}

int main() {
    matrix_t *mat1 = create_matrix(3, 4);
    matrix_t *mat2 = create_matrix(4, 3);
    matrix_t *result1 = multiply_matrices(mat1, mat2);
    matrix_t *result2 = add_matrices(mat1, mat2);
    for (int i = 0; i < result1->rows; i++) {
        for (int j = 0; j < result1->cols; j++) {
            printf("%d ", result1->data[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < result2->rows; i++) {
        for (int j = 0; j < result2->cols; j++) {
            printf("%d ", result2->data[i][j]);
        }
        printf("\n");
    }
    return 0;
}