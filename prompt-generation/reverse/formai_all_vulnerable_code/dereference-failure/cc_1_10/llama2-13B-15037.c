//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000

// Define a structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    double *data;
} Matrix;

// Define a function to create a matrix
Matrix create_matrix(int rows, int cols) {
    Matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = (double*)calloc(rows * cols, sizeof(double));
    return m;
}

// Define a function to print a matrix
void print_matrix(Matrix m) {
    int i, j;
    for (i = 0; i < m.rows; i++) {
        for (j = 0; j < m.cols; j++) {
            printf("%.2f ", m.data[i * m.cols + j]);
        }
        printf("\n");
    }
}

// Define a function to perform matrix addition
Matrix add_matrices(Matrix m1, Matrix m2) {
    Matrix result;
    result.rows = m1.rows;
    result.cols = m2.cols;
    result.data = (double*)calloc(result.rows * result.cols, sizeof(double));
    for (int i = 0; i < result.rows; i++) {
        for (int j = 0; j < result.cols; j++) {
            result.data[i * result.cols + j] = m1.data[i * m1.cols + j] + m2.data[i * m2.cols + j];
        }
    }
    return result;
}

// Define a function to perform matrix multiplication
Matrix multiply_matrices(Matrix m1, Matrix m2) {
    Matrix result;
    result.rows = m1.cols;
    result.cols = m2.rows;
    result.data = (double*)calloc(result.rows * result.cols, sizeof(double));
    for (int i = 0; i < result.rows; i++) {
        for (int j = 0; j < result.cols; j++) {
            double sum = 0;
            for (int k = 0; k < m1.cols; k++) {
                sum += m1.data[i * m1.cols + k] * m2.data[k * m2.rows + j];
            }
            result.data[i * result.cols + j] = sum;
        }
    }
    return result;
}

int main() {
    // Create two matrices
    Matrix m1 = create_matrix(N, N);
    Matrix m2 = create_matrix(N, N);

    // Fill the matrices with random data
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            m1.data[i * m1.cols + j] = (double)rand() / RAND_MAX;
            m2.data[i * m2.cols + j] = (double)rand() / RAND_MAX;
        }
    }

    // Perform matrix addition
    Matrix result = add_matrices(m1, m2);

    // Print the result
    print_matrix(result);

    // Perform matrix multiplication
    result = multiply_matrices(m1, m2);

    // Print the result
    print_matrix(result);

    return 0;
}