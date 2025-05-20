//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    m.data = (double *)calloc(rows * cols, sizeof(double));
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
    matrix res;
    res.rows = m1.rows;
    res.cols = m2.cols;
    res.data = (double *)calloc(res.rows * res.cols, sizeof(double));
    for (int i = 0; i < res.rows; i++) {
        for (int j = 0; j < res.cols; j++) {
            res.data[i * res.cols + j] = m1.data[i * m1.cols + j] + m2.data[i * m2.cols + j];
        }
    }
    return res;
}

// Function to multiply a matrix by a scalar
matrix scalar_mult(matrix m, double scalar) {
    matrix res;
    res.rows = m.rows;
    res.cols = m.cols;
    res.data = (double *)calloc(res.rows * res.cols, sizeof(double));
    for (int i = 0; i < res.rows; i++) {
        for (int j = 0; j < res.cols; j++) {
            res.data[i * res.cols + j] = m.data[i * m.cols + j] * scalar;
        }
    }
    return res;
}

int main() {
    matrix m1 = create_matrix(3, 4);
    matrix m2 = create_matrix(3, 2);
    matrix res;

    // Initialize matrix elements
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            m1.data[i * 4 + j] = (j % 2) * (i % 2);
        }
    }

    // Print initial matrix
    print_matrix(m1);

    // Add matrices
    res = add_matrices(m1, m2);
    print_matrix(res);

    // Multiply matrix by scalar
    res = scalar_mult(res, 2.5);
    print_matrix(res);

    return 0;
}