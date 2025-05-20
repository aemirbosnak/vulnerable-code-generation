//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 10

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    double *data;
} matrix;

// Function to create a matrix
matrix create_matrix(int rows, int cols) {
    matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = (double*)calloc(rows * cols, sizeof(double));
    return m;
}

// Function to print a matrix
void print_matrix(matrix m) {
    int i, j;
    for (i = 0; i < m.rows; i++) {
        for (j = 0; j < m.cols; j++) {
            printf("%.2f ", m.data[i * m.cols + j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
matrix add_matrices(matrix m1, matrix m2) {
    int i, j;
    matrix result;
    result.rows = m1.rows;
    result.cols = m2.cols;
    result.data = (double*)calloc(result.rows * result.cols, sizeof(double));
    for (i = 0; i < m1.rows; i++) {
        for (j = 0; j < m2.cols; j++) {
            result.data[i * result.cols + j] = m1.data[i * m1.cols + j] + m2.data[i * m2.cols + j];
        }
    }
    return result;
}

// Function to multiply a matrix by a scalar
matrix scalar_multiply(matrix m, double scalar) {
    int i, j;
    matrix result;
    result.rows = m.rows;
    result.cols = m.cols;
    result.data = (double*)calloc(result.rows * result.cols, sizeof(double));
    for (i = 0; i < m.rows; i++) {
        for (j = 0; j < m.cols; j++) {
            result.data[i * result.cols + j] = scalar * m.data[i * m.cols + j];
        }
    }
    return result;
}

// Function to transpose a matrix
matrix transpose(matrix m) {
    int i, j;
    matrix result;
    result.rows = m.cols;
    result.cols = m.rows;
    result.data = (double*)calloc(result.rows * result.cols, sizeof(double));
    for (i = 0; i < m.rows; i++) {
        for (j = 0; j < m.cols; j++) {
            result.data[i * result.cols + j] = m.data[j * m.cols + i];
        }
    }
    return result;
}

int main() {
    matrix m1 = create_matrix(N, N);
    matrix m2 = create_matrix(N, N);
    matrix m3 = create_matrix(N, N);

    // Initialize the matrices
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            m1.data[i * m1.cols + j] = i * j;
            m2.data[i * m2.cols + j] = i * j + 1;
            m3.data[i * m3.cols + j] = i * j + 2;
        }
    }

    // Add the matrices
    m3 = add_matrices(m1, m2);

    // Multiply the matrix by a scalar
    m3 = scalar_multiply(m3, 3);

    // Transpose the matrix
    m3 = transpose(m3);

    // Print the result
    print_matrix(m3);

    return 0;
}