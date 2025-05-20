//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: secure
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

// Function to create a new matrix
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
    for (int i = 0; i < c.rows; i++) {
        for (int j = 0; j < c.cols; j++) {
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
    for (int i = 0; i < c.rows; i++) {
        for (int j = 0; j < c.cols; j++) {
            c.data[i * c.cols + j] = m.data[i * m.cols + j] * factor;
        }
    }
    return c;
}

int main() {
    matrix a = create_matrix(3, 4);
    matrix b = create_matrix(3, 4);
    matrix c = create_matrix(3, 4);

    // Initialize matrix elements
    a.data[0 * a.cols + 0] = 1;
    a.data[0 * a.cols + 1] = 2;
    a.data[0 * a.cols + 2] = 3;
    a.data[0 * a.cols + 3] = 4;

    b.data[0 * b.cols + 0] = 5;
    b.data[0 * b.cols + 1] = 6;
    b.data[0 * b.cols + 2] = 7;
    b.data[0 * b.cols + 3] = 8;

    // Add matrices
    c = add_matrices(a, b);

    // Scale matrix by 2
    c = scale_matrix(c, 2);

    // Print result
    print_matrix(c);

    return 0;
}