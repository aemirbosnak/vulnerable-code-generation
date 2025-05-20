//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 4
#define COLS 4

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **data;
} matrix;

// Function to create a new matrix
matrix create_matrix(int rows, int cols) {
    matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; i++) {
        m.data[i] = calloc(cols, sizeof(int));
    }
    return m;
}

// Function to print a matrix
void print_matrix(matrix m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            printf("%d ", m.data[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
matrix add_matrices(matrix a, matrix b) {
    matrix c;
    c.rows = a.rows;
    c.cols = a.cols;
    c.data = calloc(c.rows, sizeof(int *));
    for (int i = 0; i < c.rows; i++) {
        c.data[i] = calloc(c.cols, sizeof(int));
        for (int j = 0; j < c.cols; j++) {
            c.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    return c;
}

// Function to multiply a matrix by a scalar
matrix scalar_multiply(matrix m, int scalar) {
    matrix c;
    c.rows = m.rows;
    c.cols = m.cols;
    c.data = calloc(c.rows, sizeof(int *));
    for (int i = 0; i < c.rows; i++) {
        c.data[i] = calloc(c.cols, sizeof(int));
        for (int j = 0; j < c.cols; j++) {
            c.data[i][j] = m.data[i][j] * scalar;
        }
    }
    return c;
}

int main() {
    matrix a = create_matrix(3, 3);
    matrix b = create_matrix(3, 3);
    matrix c = create_matrix(3, 3);

    // Initialize the matrices
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            a.data[i][j] = i * j;
            b.data[i][j] = i + j;
        }
    }

    // Add the matrices
    c = add_matrices(a, b);

    // Print the result
    print_matrix(c);

    // Multiply the matrix by a scalar
    c = scalar_multiply(c, 2);

    // Print the result
    print_matrix(c);

    return 0;
}