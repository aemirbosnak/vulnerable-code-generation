//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 10
#define MAX_COLS 10

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int *data;
} matrix;

// Function to create a matrix
matrix create_matrix(int rows, int cols) {
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
    c.cols = a.cols;
    c.data = (int *)calloc(c.rows * c.cols, sizeof(int));
    
    int i, j;
    for (i = 0; i < a.rows; i++) {
        for (j = 0; j < a.cols; j++) {
            c.data[i * c.cols + j] = a.data[i * a.cols + j] + b.data[i * b.cols + j];
        }
    }
    
    return c;
}

// Function to multiply a matrix by a scalar
matrix scale_matrix(matrix m, int factor) {
    matrix c;
    c.rows = m.rows;
    c.cols = m.cols;
    c.data = (int *)calloc(c.rows * c.cols, sizeof(int));
    
    int i, j;
    for (i = 0; i < m.rows; i++) {
        for (j = 0; j < m.cols; j++) {
            c.data[i * c.cols + j] = m.data[i * m.cols + j] * factor;
        }
    }
    
    return c;
}

int main() {
    matrix a = create_matrix(3, 4);
    matrix b = create_matrix(3, 4);
    matrix c;
    
    // Initialize matrix A
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            a.data[i * 3 * 4 + j] = i * j;
        }
    }
    
    // Initialize matrix B
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            b.data[i * 3 * 4 + j] = i * (j + 1);
        }
    }
    
    // Add matrices A and B
    c = add_matrices(a, b);
    
    // Print matrix C
    print_matrix(c);
    
    // Scale matrix C by a factor of 2
    c = scale_matrix(c, 2);
    
    // Print matrix C again
    print_matrix(c);
    
    return 0;
}