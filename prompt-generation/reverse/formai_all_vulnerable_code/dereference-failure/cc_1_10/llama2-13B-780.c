//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 100
#define N 100

// Structure to store a matrix
typedef struct {
    int rows;
    int cols;
    int *data;
} matrix;

// Function to initialize a matrix
matrix init_matrix(int rows, int cols) {
    matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = (int *)calloc(rows * cols, sizeof(int));
    return m;
}

// Function to print a matrix
void print_matrix(matrix m) {
    int i, j;
    for (i = 0; i < m.rows; i++) {
        for (j = 0; j < m.cols; j++) {
            printf("%d ", m.data[i * m.cols + j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
matrix add_matrices(matrix a, matrix b) {
    matrix c;
    c.rows = a.rows;
    c.cols = b.cols;
    c.data = (int *)calloc(c.rows * c.cols, sizeof(int));
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            c.data[i * c.cols + j] = a.data[i * a.cols + j] + b.data[i * b.cols + j];
        }
    }
    return c;
}

// Function to multiply a matrix by a scalar
matrix scalar_multiply(matrix m, int scalar) {
    matrix c;
    c.rows = m.rows;
    c.cols = m.cols;
    c.data = (int *)calloc(c.rows * c.cols, sizeof(int));
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            c.data[i * c.cols + j] = m.data[i * m.cols + j] * scalar;
        }
    }
    return c;
}

int main() {
    matrix a = init_matrix(M, N);
    matrix b = init_matrix(M, N);
    matrix c = init_matrix(M, N);
    matrix d = init_matrix(M, N);

    // Initialize matrices
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            a.data[i * a.cols + j] = i * j;
            b.data[i * b.cols + j] = i * (j + 1);
        }
    }

    // Add matrices
    c = add_matrices(a, b);
    d = add_matrices(c, c);

    // Print matrices
    print_matrix(a);
    print_matrix(b);
    print_matrix(c);
    print_matrix(d);

    // Multiply a matrix by a scalar
    c = scalar_multiply(a, 2);
    d = scalar_multiply(c, 3);

    // Print matrices
    print_matrix(c);
    print_matrix(d);

    return 0;
}