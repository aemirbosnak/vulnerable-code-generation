//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MATRIX_DIM 3

typedef struct {
    int rows;
    int cols;
    double *data;
} Matrix;

Matrix *create_matrix(int rows, int cols) {
    Matrix *m = (Matrix *)malloc(sizeof(Matrix));
    m->rows = rows;
    m->cols = cols;
    m->data = (double *)malloc(sizeof(double) * rows * cols);
    return m;
}

void print_matrix(Matrix *m) {
    int i, j;
    for (i = 0; i < m->rows; i++) {
        for (j = 0; j < m->cols; j++) {
            printf("%.2f ", m->data[i * m->cols + j]);
        }
        printf("\n");
    }
}

Matrix *add_matrices(Matrix *a, Matrix *b) {
    Matrix *c = create_matrix(a->rows, b->cols);
    int i, j, k;
    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < b->cols; j++) {
            c->data[i * c->cols + j] = a->data[i * a->cols + j] + b->data[i * b->cols + j];
        }
    }
    return c;
}

Matrix *multiply_matrices(Matrix *a, Matrix *b) {
    Matrix *c = create_matrix(a->rows, b->cols * a->cols);
    int i, j, k;
    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < b->cols; j++) {
            for (k = 0; k < a->cols; k++) {
                c->data[i * c->cols + j * a->cols + k] =
                    a->data[i * a->cols + k] * b->data[j * b->cols + k];
            }
        }
    }
    return c;
}

int main() {
    Matrix *a = create_matrix(2, 3);
    Matrix *b = create_matrix(3, 2);
    Matrix *c;

    // Initialize matrices
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            a->data[i * a->cols + j] = i * j;
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            b->data[i * b->cols + j] = i * j;
        }
    }

    // Add matrices
    c = add_matrices(a, b);
    print_matrix(c);

    // Multiply matrices
    c = multiply_matrices(a, b);
    print_matrix(c);

    return 0;
}