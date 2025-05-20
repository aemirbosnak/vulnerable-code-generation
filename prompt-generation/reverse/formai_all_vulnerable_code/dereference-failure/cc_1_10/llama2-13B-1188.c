//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 10

// Structure to store a matrix
typedef struct {
    int rows;
    int cols;
    int *data;
} Matrix;

// Function to create a matrix
Matrix create_matrix(int r, int c) {
    Matrix m;
    m.rows = r;
    m.cols = c;
    m.data = (int *)calloc(r * c, sizeof(int));
    return m;
}

// Function to print a matrix
void print_matrix(Matrix m) {
    int i, j;
    for (i = 0; i < m.rows; i++) {
        for (j = 0; j < m.cols; j++) {
            printf("%d ", m.data[i * m.cols + j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
Matrix add_matrices(Matrix m1, Matrix m2) {
    Matrix res;
    res.rows = m1.rows;
    res.cols = m2.cols;
    res.data = (int *)calloc(res.rows * res.cols, sizeof(int));
    for (int i = 0; i < res.rows; i++) {
        for (int j = 0; j < res.cols; j++) {
            res.data[i * res.cols + j] = m1.data[i * m1.cols + j] + m2.data[i * m2.cols + j];
        }
    }
    return res;
}

// Function to multiply a matrix by a scalar
Matrix scalar_multiply(Matrix m, int k) {
    Matrix res;
    res.rows = m.rows;
    res.cols = m.cols;
    res.data = (int *)calloc(res.rows * res.cols, sizeof(int));
    for (int i = 0; i < res.rows; i++) {
        for (int j = 0; j < res.cols; j++) {
            res.data[i * res.cols + j] = m.data[i * m.cols + j] * k;
        }
    }
    return res;
}

int main() {
    Matrix m1 = create_matrix(3, 4);
    Matrix m2 = create_matrix(2, 3);
    Matrix m3 = create_matrix(4, 5);

    // Initialize the matrix elements
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            m1.data[i * m1.cols + j] = i * j;
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            m2.data[i * m2.cols + j] = i * j + 1;
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            m3.data[i * m3.cols + j] = i * j + 2;
        }
    }

    // Print the matrices
    print_matrix(m1);
    print_matrix(m2);
    print_matrix(m3);

    // Add the matrices
    Matrix res = add_matrices(m1, m2);
    print_matrix(res);

    // Multiply the matrix by a scalar
    res = scalar_multiply(res, 2);
    print_matrix(res);

    return 0;
}