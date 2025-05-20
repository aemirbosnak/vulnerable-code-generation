//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    double *data;
} matrix_t;

// Function to create a matrix
matrix_t* create_matrix(int rows, int cols) {
    matrix_t* mat = (matrix_t*)malloc(sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (double*)malloc(rows * cols * sizeof(double));
    return mat;
}

// Function to print a matrix
void print_matrix(matrix_t* mat) {
    int i, j;
    for (i = 0; i < mat->rows; i++) {
        for (j = 0; j < mat->cols; j++) {
            printf("%.2f ", mat->data[i * mat->cols + j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
matrix_t* add_matrices(matrix_t* mat1, matrix_t* mat2) {
    int i, j;
    matrix_t* result = create_matrix(mat1->rows, mat2->cols);
    for (i = 0; i < mat1->rows; i++) {
        for (j = 0; j < mat2->cols; j++) {
            result->data[i * result->cols + j] = mat1->data[i * mat1->cols + j] + mat2->data[i * mat2->cols + j];
        }
    }
    return result;
}

// Function to multiply a matrix by a scalar
matrix_t* scale_matrix(matrix_t* mat, double scale) {
    int i, j;
    matrix_t* result = create_matrix(mat->rows, mat->cols);
    for (i = 0; i < mat->rows; i++) {
        for (j = 0; j < mat->cols; j++) {
            result->data[i * result->cols + j] = scale * mat->data[i * mat->cols + j];
        }
    }
    return result;
}

int main() {
    matrix_t* mat1 = create_matrix(3, 4);
    matrix_t* mat2 = create_matrix(4, 2);
    matrix_t* result = add_matrices(mat1, mat2);
    print_matrix(result);

    result = scale_matrix(mat1, 2.0);
    print_matrix(result);

    return 0;
}