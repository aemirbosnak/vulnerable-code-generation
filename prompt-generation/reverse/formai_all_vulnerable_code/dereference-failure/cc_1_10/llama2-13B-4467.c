//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define ROWS 4
#define COLS 4

// Structure to represent a matrix
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
    m.data = calloc(rows * cols, sizeof(int));
    return m;
}

// Function to print a matrix
void print_matrix(matrix m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            printf("%d ", m.data[i * m.cols + j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
matrix add_matrices(matrix m1, matrix m2) {
    matrix result;
    result.rows = m1.rows;
    result.cols = m2.cols;
    result.data = calloc(result.rows * result.cols, sizeof(int));
    
    for (int i = 0; i < m1.rows; i++) {
        for (int j = 0; j < m2.cols; j++) {
            result.data[i * result.cols + j] = m1.data[i * m1.cols + j] + m2.data[i * m2.cols + j];
        }
    }
    
    return result;
}

// Function to multiply a matrix by a scalar
matrix scale_matrix(matrix m, int factor) {
    matrix result;
    result.rows = m.rows;
    result.cols = m.cols;
    result.data = calloc(result.rows * result.cols, sizeof(int));
    
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            result.data[i * result.cols + j] = m.data[i * m.cols + j] * factor;
        }
    }
    
    return result;
}

int main() {
    matrix m1 = init_matrix(ROWS, COLS);
    matrix m2 = init_matrix(ROWS, COLS);
    matrix result;
    
    // Initialize matrix elements
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            m1.data[i * m1.cols + j] = i * j;
            m2.data[i * m2.cols + j] = i * j + 1;
        }
    }
    
    // Add matrices
    result = add_matrices(m1, m2);
    
    // Scale matrix by a factor of 2
    result = scale_matrix(result, 2);
    
    // Print result
    print_matrix(result);
    
    return 0;
}