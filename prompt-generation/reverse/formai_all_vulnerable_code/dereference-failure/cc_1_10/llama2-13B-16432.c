//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

typedef struct {
    int rows;
    int cols;
    int *data;
} matrix_t;

matrix_t *create_matrix(int r, int c) {
    matrix_t *m = malloc(sizeof(matrix_t));
    m->rows = r;
    m->cols = c;
    m->data = malloc(r * c * sizeof(int));
    return m;
}

void print_matrix(matrix_t *m) {
    int i, j;
    for (i = 0; i < m->rows; i++) {
        for (j = 0; j < m->cols; j++) {
            printf("%d ", m->data[i * m->cols + j]);
        }
        printf("\n");
    }
}

matrix_t *add_matrices(matrix_t *a, matrix_t *b) {
    matrix_t *c = create_matrix(a->rows, b->cols);
    int i, j, k;
    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < b->cols; j++) {
            c->data[i * c->cols + j] = a->data[i * a->cols + j] + b->data[i * b->cols + j];
        }
    }
    return c;
}

matrix_t *multiply_matrices(matrix_t *a, matrix_t *b) {
    matrix_t *c = create_matrix(a->rows, b->cols * a->cols);
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
    matrix_t *a, *b, *c;
    a = create_matrix(3, 4);
    b = create_matrix(4, 2);
    c = add_matrices(a, b);
    print_matrix(c);
    c = multiply_matrices(a, b);
    print_matrix(c);
    return 0;
}