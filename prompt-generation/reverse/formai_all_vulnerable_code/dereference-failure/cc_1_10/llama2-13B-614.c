//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: careful
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
    matrix result;
    int i, j;
    
    // Check for invalid input
    if (m1.rows != m2.rows || m1.cols != m2.cols) {
        printf("Invalid input matrices!\n");
        return result;
    }
    
    // Create result matrix
    result.rows = m1.rows;
    result.cols = m1.cols;
    result.data = (double*)calloc(result.rows * result.cols, sizeof(double));
    
    // Add matrices element-wise
    for (i = 0; i < m1.rows; i++) {
        for (j = 0; j < m1.cols; j++) {
            result.data[i * result.cols + j] = m1.data[i * m1.cols + j] + m2.data[i * m2.cols + j];
        }
    }
    
    return result;
}

int main() {
    matrix m1 = create_matrix(3, 4);
    matrix m2 = create_matrix(3, 4);
    matrix result;
    
    // Initialize matrices
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            m1.data[i * m1.cols + j] = (i + j) % 2 ? 1.0 : 0.5;
            m2.data[i * m2.cols + j] = (i + j) % 3 ? 2.0 : 1.5;
        }
    }
    
    // Add matrices
    result = add_matrices(m1, m2);
    
    // Print result
    print_matrix(result);
    
    return 0;
}