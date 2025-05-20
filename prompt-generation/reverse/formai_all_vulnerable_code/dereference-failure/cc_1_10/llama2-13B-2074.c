//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    int rows;
    int cols;
    double *data;
} matrix;

matrix create_matrix(int rows, int cols) {
    matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = (double*)calloc(rows * cols, sizeof(double));
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

matrix add_matrices(matrix a, matrix b) {
    matrix c;
    c.rows = a.rows;
    c.cols = a.cols;
    c.data = (double*)calloc(c.rows * c.cols, sizeof(double));
    for (int i = 0; i < c.rows; i++) {
        for (int j = 0; j < c.cols; j++) {
            c.data[i * c.cols + j] = a.data[i * a.cols + j] + b.data[i * b.cols + j];
        }
    }
    return c;
}

matrix multiply_matrices(matrix a, matrix b) {
    matrix c;
    c.rows = a.rows;
    c.cols = b.cols;
    c.data = (double*)calloc(c.rows * c.cols, sizeof(double));
    for (int i = 0; i < c.rows; i++) {
        for (int j = 0; j < c.cols; j++) {
            double sum = 0;
            for (int k = 0; k < a.cols; k++) {
                sum += a.data[i * a.cols + k] * b.data[k * b.cols + j];
            }
            c.data[i * c.cols + j] = sum;
        }
    }
    return c;
}

int main() {
    matrix a = create_matrix(5, 3);
    matrix b = create_matrix(3, 4);
    matrix c = add_matrices(a, b);
    matrix d = multiply_matrices(a, b);
    print_matrix(a);
    print_matrix(b);
    print_matrix(c);
    print_matrix(d);
    return 0;
}