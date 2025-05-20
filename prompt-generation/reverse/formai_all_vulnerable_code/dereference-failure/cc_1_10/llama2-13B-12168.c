//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

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
    m.data = malloc(rows * cols * sizeof(int));
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
    c.data = malloc(c.rows * c.cols * sizeof(int));
    for (int i = 0; i < c.rows; i++) {
        for (int j = 0; j < c.cols; j++) {
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
    c.data = malloc(c.rows * c.cols * sizeof(int));
    for (int i = 0; i < c.rows; i++) {
        for (int j = 0; j < c.cols; j++) {
            c.data[i * c.cols + j] = m.data[i * m.cols + j] * scalar;
        }
    }
    return c;
}

int main() {
    matrix a = create_matrix(3, 4);
    matrix b = create_matrix(4, 3);
    matrix c = add_matrices(a, b);
    matrix d = scalar_multiply(c, 2);

    print_matrix(a);
    print_matrix(b);
    print_matrix(c);
    print_matrix(d);

    return 0;
}