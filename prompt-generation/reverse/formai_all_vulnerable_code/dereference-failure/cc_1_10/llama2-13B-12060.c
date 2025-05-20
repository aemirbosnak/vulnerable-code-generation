//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 4

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    double *data;
} matrix_t;

// Function to create a matrix
matrix_t* create_matrix(int rows, int cols) {
    matrix_t* mat = (matrix_t*) malloc(sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (double*) malloc(sizeof(double) * rows * cols);
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

// Function to perform matrix multiplication
matrix_t* multiply(matrix_t* mat1, matrix_t* mat2) {
    int i, j, k;
    matrix_t* result = create_matrix(mat1->rows, mat2->cols);
    for (i = 0; i < mat1->rows; i++) {
        for (j = 0; j < mat2->cols; j++) {
            double sum = 0;
            for (k = 0; k < mat1->cols; k++) {
                sum += mat1->data[i * mat1->cols + k] * mat2->data[k * mat2->cols + j];
            }
            result->data[i * result->cols + j] = sum;
        }
    }
    return result;
}

int main() {
    matrix_t* mat1 = create_matrix(3, 2);
    matrix_t* mat2 = create_matrix(2, 3);
    matrix_t* result = multiply(mat1, mat2);
    print_matrix(result);
    return 0;
}