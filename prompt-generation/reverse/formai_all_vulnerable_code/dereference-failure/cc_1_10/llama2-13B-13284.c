//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 1024

typedef struct {
    int rows;
    int cols;
    double *data;
} matrix;

matrix create_matrix(int r, int c) {
    matrix m;
    m.rows = r;
    m.cols = c;
    m.data = (double*)malloc(r * c * sizeof(double));
    return m;
}

void print_matrix(matrix m) {
    int i, j;
    for (i = 0; i < m.rows; i++) {
        for (j = 0; j < m.cols; j++) {
            printf("%.2f ", m.data[i * m.cols + j]);
        }
        printf("\n");
    }
}

void add_matrices(matrix a, matrix b, matrix c) {
    int i, j, k;
    for (i = 0; i < a.rows; i++) {
        for (j = 0; j < a.cols; j++) {
            for (k = 0; k < b.rows; k++) {
                c.data[i * c.cols + j] += a.data[i * a.cols + j] + b.data[k * b.cols + j];
            }
        }
    }
}

void subtract_matrices(matrix a, matrix b, matrix c) {
    int i, j, k;
    for (i = 0; i < a.rows; i++) {
        for (j = 0; j < a.cols; j++) {
            for (k = 0; k < b.rows; k++) {
                c.data[i * c.cols + j] -= a.data[i * a.cols + j] - b.data[k * b.cols + j];
            }
        }
    }
}

void multiply_matrices(matrix a, matrix b, matrix c) {
    int i, j, k;
    for (i = 0; i < a.rows; i++) {
        for (j = 0; j < a.cols; j++) {
            for (k = 0; k < b.rows; k++) {
                c.data[i * c.cols + j] += a.data[i * a.cols + j] * b.data[k * b.cols + j];
            }
        }
    }
}

int main() {
    matrix a = create_matrix(3, 4);
    matrix b = create_matrix(4, 3);
    matrix c = create_matrix(3, 3);

    // Initialize matrix elements
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            a.data[i * a.cols + j] = (i * j) % 10;
        }
    }

    for (int i = 0; i < b.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            b.data[i * b.cols + j] = (i * j) % 10;
        }
    }

    // Perform operations
    add_matrices(a, b, c);
    subtract_matrices(a, b, c);
    multiply_matrices(a, b, c);

    // Print result
    print_matrix(c);

    return 0;
}