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
    matrix_t* mat = (matrix_t*) malloc(sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (double*) malloc(rows * cols * sizeof(double));
    return mat;
}

// Function to free a matrix
void free_matrix(matrix_t* mat) {
    free(mat->data);
    free(mat);
}

// Function to perform matrix multiplication
matrix_t* multiply_matrices(matrix_t* mat1, matrix_t* mat2) {
    int rows1 = mat1->rows;
    int cols1 = mat1->cols;
    int rows2 = mat2->rows;
    int cols2 = mat2->cols;
    int rows3 = rows1 * rows2;
    int cols3 = cols1 * cols2;
    matrix_t* result = create_matrix(rows3, cols3);

    for (int i = 0; i < rows3; i++) {
        for (int j = 0; j < cols3; j++) {
            double sum = 0;
            for (int k = 0; k < rows1; k++) {
                for (int l = 0; l < cols2; l++) {
                    sum += mat1->data[i * mat1->cols + k] * mat2->data[k * mat2->cols + l];
                }
            }
            result->data[i * result->cols + j] = sum;
        }
    }

    return result;
}

int main() {
    matrix_t* mat1 = create_matrix(3, 2);
    matrix_t* mat2 = create_matrix(2, 3);
    matrix_t* result = multiply_matrices(mat1, mat2);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%.2f ", result->data[i * result->cols + j]);
        }
        printf("\n");
    }

    free_matrix(mat1);
    free_matrix(mat2);
    free_matrix(result);

    return 0;
}