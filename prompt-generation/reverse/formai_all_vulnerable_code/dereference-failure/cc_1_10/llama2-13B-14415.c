//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define M 4
#define N 4

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
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
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
matrix scale_matrix(matrix m, int scalar) {
    matrix c;
    c.rows = m.rows;
    c.cols = m.cols;
    c.data = (int *)calloc(c.rows * c.cols, sizeof(int));

    for (int i = 0; i < c.rows; i++) {
        for (int j = 0; j < c.cols; j++) {
            c.data[i * c.cols + j] = m.data[i * m.cols + j] * scalar;
        }
    }

    return c;
}

int main() {
    srand(time(NULL));

    matrix a = create_matrix(M, N);
    matrix b = create_matrix(M, N);
    matrix c = create_matrix(M, N);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            a.data[i * a.cols + j] = rand() % 10;
            b.data[i * b.cols + j] = rand() % 10;
        }
    }

    c = add_matrices(a, b);
    c = scale_matrix(c, 2);

    print_matrix(c);

    return 0;
}