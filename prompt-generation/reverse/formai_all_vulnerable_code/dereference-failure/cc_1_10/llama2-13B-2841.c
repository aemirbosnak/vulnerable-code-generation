//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATRIX_ROMANCE 1

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    double* data;
} matrix;

// Function to create a matrix
matrix create_matrix(int rows, int cols) {
    matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = (double*)calloc(rows * cols, sizeof(double));
    return m;
}

// Function to perform matrix multiplication
matrix multiply_matrices(matrix A, matrix B) {
    int rows_A = A.rows;
    int cols_A = A.cols;
    int rows_B = B.rows;
    int cols_B = B.cols;
    matrix C;

    C.rows = rows_A;
    C.cols = cols_B;
    C.data = (double*)calloc(rows_A * cols_B, sizeof(double));

    for (int i = 0; i < rows_A; i++) {
        for (int j = 0; j < cols_B; j++) {
            double sum = 0;
            for (int k = 0; k < cols_A; k++) {
                sum += A.data[i * cols_A + k] * B.data[k * cols_B + j];
            }
            C.data[i * cols_B + j] = sum;
        }
    }

    return C;
}

int main() {
    matrix A = create_matrix(3, 2);
    matrix B = create_matrix(2, 3);
    matrix C = multiply_matrices(A, B);

    printf("A = \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%.2f ", A.data[i * 2 + j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("B = \n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%.2f ", B.data[i * 3 + j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("C = \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%.2f ", C.data[i * 3 + j]);
        }
        printf("\n");
    }
    return 0;
}