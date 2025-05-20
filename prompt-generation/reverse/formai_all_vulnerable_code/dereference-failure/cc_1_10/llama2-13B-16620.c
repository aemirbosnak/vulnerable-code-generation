//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MATRIX_SIZE 100

typedef struct {
    int rows;
    int cols;
    double *data;
} matrix_t;

matrix_t *create_matrix(int rows, int cols) {
    matrix_t *mat = malloc(sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = malloc(sizeof(double) * rows * cols);
    return mat;
}

void print_matrix(matrix_t *mat) {
    int i, j;
    for (i = 0; i < mat->rows; i++) {
        for (j = 0; j < mat->cols; j++) {
            printf("%.2f ", mat->data[i * mat->cols + j]);
        }
        printf("\n");
    }
}

void add_matrices(matrix_t *a, matrix_t *b) {
    int i, j;
    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < a->cols; j++) {
            a->data[i * a->cols + j] += b->data[i * b->cols + j];
        }
    }
}

void scale_matrix(matrix_t *mat, double scale) {
    int i, j;
    for (i = 0; i < mat->rows; i++) {
        for (j = 0; j < mat->cols; j++) {
            mat->data[i * mat->cols + j] *= scale;
        }
    }
}

int main() {
    matrix_t *a, *b, *c;
    a = create_matrix(5, 3);
    b = create_matrix(3, 4);
    c = create_matrix(5, 4);

    // Initialize matrices
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            a->data[i * a->cols + j] = i * j;
        }
    }
    for (int i = 0; i < b->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            b->data[i * b->cols + j] = i + j;
        }
    }

    // Add matrices
    add_matrices(a, b);

    // Scale matrix
    scale_matrix(c, 2.0);

    // Print matrices
    print_matrix(a);
    print_matrix(b);
    print_matrix(c);

    return 0;
}