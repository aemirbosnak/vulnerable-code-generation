//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW_SIZE 5
#define COL_SIZE 10

// Structure to store a matrix
typedef struct {
    int rows;
    int cols;
    int *data;
} Matrix;

// Function to initialize a matrix
Matrix init_matrix(int rows, int cols) {
    Matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = (int *)calloc(rows * cols, sizeof(int));
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
    int i, j, k;
    
    // Initialize result matrix
    res.rows = m1.rows;
    res.cols = m2.cols;
    res.data = (int *)calloc(res.rows * res.cols, sizeof(int));
    
    // Add elements row-wise
    for (i = 0; i < res.rows; i++) {
        for (j = 0; j < res.cols; j++) {
            res.data[i * res.cols + j] = m1.data[i * m1.cols + j] + m2.data[i * m2.cols + j];
        }
    }
    
    return res;
}

// Function to multiply a matrix by a scalar
Matrix scalar_mult(Matrix m, int scalar) {
    Matrix res;
    int i, j;
    
    // Initialize result matrix
    res.rows = m.rows;
    res.cols = m.cols;
    res.data = (int *)calloc(res.rows * res.cols, sizeof(int));
    
    // Multiply elements element-wise
    for (i = 0; i < res.rows; i++) {
        for (j = 0; j < res.cols; j++) {
            res.data[i * res.cols + j] = m.data[i * m.cols + j] * scalar;
        }
    }
    
    return res;
}

int main() {
    Matrix m1 = init_matrix(3, 4);
    Matrix m2 = init_matrix(2, 3);
    Matrix m3 = init_matrix(4, 5);
    
    // Add matrices
    Matrix res = add_matrices(m1, m2);
    print_matrix(res);
    
    // Multiply matrix by scalar
    res = scalar_mult(m3, 2);
    print_matrix(res);
    
    return 0;
}