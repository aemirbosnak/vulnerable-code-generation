//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    double *data;
} matrix;

// Function to create a new matrix
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
        printf("Invalid input matrices\n");
        return result;
    }
    
    result.rows = m1.rows;
    result.cols = m1.cols;
    result.data = (double*)calloc(result.rows * result.cols, sizeof(double));
    
    for (i = 0; i < result.rows; i++) {
        for (j = 0; j < result.cols; j++) {
            result.data[i * result.cols + j] = m1.data[i * m1.cols + j] + m2.data[i * m2.cols + j];
        }
    }
    
    return result;
}

int main() {
    matrix m1 = create_matrix(3, 4);
    matrix m2 = create_matrix(4, 3);
    matrix result = add_matrices(m1, m2);
    
    print_matrix(result);
    
    return 0;
}