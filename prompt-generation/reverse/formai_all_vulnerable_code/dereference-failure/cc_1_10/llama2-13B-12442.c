//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 4
#define COLS 4

typedef struct {
    int rows;
    int cols;
    int *data;
} matrix_t;

matrix_t *create_matrix(int rows, int cols) {
    matrix_t *mat = (matrix_t *)calloc(1, sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (int *)calloc(rows * cols, sizeof(int));
    return mat;
}

void print_matrix(matrix_t *mat) {
    int i, j;
    for (i = 0; i < mat->rows; i++) {
        for (j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i * mat->cols + j]);
        }
        printf("\n");
    }
}

matrix_t *add_matrices(matrix_t *a, matrix_t *b) {
    matrix_t *sum = create_matrix(a->rows, b->cols);
    int i, j, k;
    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < b->cols; j++) {
            for (k = 0; k < a->cols; k++) {
                sum->data[i * sum->cols + j] += a->data[i * a->cols + k] + b->data[k * b->cols + j];
            }
        }
    }
    return sum;
}

matrix_t *multiply_matrices(matrix_t *a, matrix_t *b) {
    matrix_t *product = create_matrix(a->rows, b->cols);
    int i, j, k;
    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < b->cols; j++) {
            int sum = 0;
            for (k = 0; k < a->cols; k++) {
                sum += a->data[i * a->cols + k] * b->data[k * b->cols + j];
            }
            product->data[i * product->cols + j] = sum;
        }
    }
    return product;
}

int main() {
    matrix_t *a = create_matrix(ROWS, COLS);
    matrix_t *b = create_matrix(ROWS, COLS);
    matrix_t *c = create_matrix(ROWS, COLS);
    matrix_t *d = create_matrix(ROWS, COLS);

    // Initialize matrices
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            a->data[i * a->cols + j] = i * j;
            b->data[i * b->cols + j] = i * j + 1;
            c->data[i * c->cols + j] = a->data[i * a->cols + j] + b->data[i * b->cols + j];
            d->data[i * d->cols + j] = c->data[i * c->cols + j] + 1;
        }
    }

    // Perform matrix addition
    c = add_matrices(a, b);
    print_matrix(c);

    // Perform matrix multiplication
    d = multiply_matrices(a, b);
    print_matrix(d);

    return 0;
}