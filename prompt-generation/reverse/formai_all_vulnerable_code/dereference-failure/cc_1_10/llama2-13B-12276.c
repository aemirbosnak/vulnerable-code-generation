//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define some constants and macros
#define M 3  // size of the matrices
#define N 4  // number of elements in each row and column
#define EPS 0.000001  // small positive number for floating-point comparisons

// Structure to represent a matrix
typedef struct {
    int rows;  // number of rows
    int cols;  // number of columns
    double *data;  // matrix elements
} matrix;

// Function to initialize a matrix with random values
matrix init_matrix(int rows, int cols) {
    matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = malloc(rows * cols * sizeof(double));
    for (int i = 0; i < rows * cols; i++) {
        m.data[i] = (double)rand() / RAND_MAX;
    }
    return m;
}

// Function to print a matrix
void print_matrix(matrix m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            printf("%.2f ", m.data[i * m.cols + j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
matrix add_matrices(matrix a, matrix b) {
    matrix c;
    c.rows = a.rows;
    c.cols = a.cols;
    c.data = malloc(c.rows * c.cols * sizeof(double));
    for (int i = 0; i < c.rows; i++) {
        for (int j = 0; j < c.cols; j++) {
            c.data[i * c.cols + j] = a.data[i * a.cols + j] + b.data[i * b.cols + j];
        }
    }
    return c;
}

// Function to multiply a matrix by a scalar
matrix scalar_multiply(matrix m, double scalar) {
    matrix c;
    c.rows = m.rows;
    c.cols = m.cols;
    c.data = malloc(c.rows * c.cols * sizeof(double));
    for (int i = 0; i < c.rows; i++) {
        for (int j = 0; j < c.cols; j++) {
            c.data[i * c.cols + j] = m.data[i * m.cols + j] * scalar;
        }
    }
    return c;
}

// Function to transpose a matrix
matrix transpose(matrix m) {
    matrix c;
    c.rows = m.cols;
    c.cols = m.rows;
    c.data = malloc(c.rows * c.cols * sizeof(double));
    for (int i = 0; i < c.rows; i++) {
        for (int j = 0; j < c.cols; j++) {
            c.data[i * c.cols + j] = m.data[j * m.cols + i];
        }
    }
    return c;
}

int main() {
    // Initialize matrices
    matrix a = init_matrix(2, 3);
    matrix b = init_matrix(3, 2);
    matrix c = init_matrix(2, 2);

    // Add matrices
    c = add_matrices(a, b);

    // Multiply matrix by scalar
    matrix d = scalar_multiply(c, 2.5);

    // Transpose matrix
    matrix e = transpose(d);

    // Print matrices
    print_matrix(a);
    print_matrix(b);
    print_matrix(c);
    print_matrix(d);
    print_matrix(e);

    return 0;
}