//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 5 // number of matrices
#define N 3 // number of columns in each matrix
#define K 2 // number of rows in each matrix

typedef struct {
    int rows;
    int cols;
    int data[N][K];
} Matrix;

// function to print a matrix
void print_matrix(Matrix *m) {
    int i, j;
    for (i = 0; i < m->rows; i++) {
        for (j = 0; j < m->cols; j++) {
            printf("%d ", m->data[i][j]);
        }
        printf("\n");
    }
}

// function to add two matrices
Matrix add_matrices(Matrix a, Matrix b) {
    Matrix c;
    c.rows = a.rows;
    c.cols = a.cols;
    for (int i = 0; i < c.rows; i++) {
        for (int j = 0; j < c.cols; j++) {
            c.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    return c;
}

// function to multiply a matrix by a scalar
Matrix scalar_mult(Matrix m, int n) {
    Matrix c;
    c.rows = m.rows;
    c.cols = m.cols;
    for (int i = 0; i < c.rows; i++) {
        for (int j = 0; j < c.cols; j++) {
            c.data[i][j] = m.data[i][j] * n;
        }
    }
    return c;
}

int main() {
    Matrix a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
           b = {{10, 20, 30}, {40, 50, 60}, {70, 80, 90}},
           c;

    // print the matrices
    print_matrix(&a);
    print_matrix(&b);

    // add the matrices
    c = add_matrices(a, b);
    print_matrix(&c);

    // multiply the matrix by a scalar
    c = scalar_mult(a, 2);
    print_matrix(&c);

    return 0;
}