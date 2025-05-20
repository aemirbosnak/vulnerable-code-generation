//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: realistic
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
    m.data = (double*)malloc(rows * cols * sizeof(double));
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
    matrix result;
    result.rows = m1.rows;
    result.cols = m2.cols;
    result.data = (double*)malloc(result.rows * result.cols * sizeof(double));
    
    int i, j;
    for (i = 0; i < result.rows; i++) {
        for (j = 0; j < result.cols; j++) {
            result.data[i * result.cols + j] = m1.data[i * m1.cols + j] + m2.data[i * m2.cols + j];
        }
    }
    
    return result;
}

// Function to multiply a matrix by a scalar
matrix scalar_multiply(matrix m, double scalar) {
    matrix result;
    result.rows = m.rows;
    result.cols = m.cols;
    result.data = (double*)malloc(result.rows * result.cols * sizeof(double));
    
    int i, j;
    for (i = 0; i < result.rows; i++) {
        for (j = 0; j < result.cols; j++) {
            result.data[i * result.cols + j] = m.data[i * m.cols + j] * scalar;
        }
    }
    
    return result;
}

int main() {
    matrix m1 = create_matrix(3, 4);
    matrix m2 = create_matrix(4, 3);
    matrix result;
    
    // Initialize matrix elements
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            m1.data[i * m1.cols + j] = (i * j) % 10;
        }
    }
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            m2.data[i * m2.cols + j] = (i * j) % 10;
        }
    }
    
    // Add matrices
    result = add_matrices(m1, m2);
    print_matrix(result);
    
    // Multiply matrix by scalar
    result = scalar_multiply(m1, 2.0);
    print_matrix(result);
    
    return 0;
}