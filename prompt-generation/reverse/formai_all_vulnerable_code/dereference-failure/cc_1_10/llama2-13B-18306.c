//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 5
#define N 3
#define P 2

typedef struct {
    int rows;
    int cols;
    int *data;
} matrix_t;

matrix_t *create_matrix(int r, int c) {
    matrix_t *m = (matrix_t *)malloc(sizeof(matrix_t));
    m->rows = r;
    m->cols = c;
    m->data = (int *)malloc(r * c * sizeof(int));
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

void add_matrices(matrix_t *a, matrix_t *b, matrix_t *c) {
    int i, j, k;
    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < a->cols; j++) {
            c->data[i * c->cols + j] = a->data[i * a->cols + j] + b->data[i * b->cols + j];
        }
    }
}

void multiply_matrices(matrix_t *a, matrix_t *b, matrix_t *c) {
    int i, j, k;
    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < b->cols; j++) {
            int sum = 0;
            for (k = 0; k < a->cols; k++) {
                sum += a->data[i * a->cols + k] * b->data[k * b->cols + j];
            }
            c->data[i * c->cols + j] = sum;
        }
    }
}

int main() {
    matrix_t *a, *b, *c;
    a = create_matrix(M, N);
    b = create_matrix(M, P);
    c = create_matrix(M, P);

    // Initialize matrices
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            a->data[i * a->cols + j] = i * j;
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            b->data[i * b->cols + j] = i * j + 1;
        }
    }

    // Add matrices
    add_matrices(a, b, c);

    // Print result
    print_matrix(c);

    // Multiply matrices
    multiply_matrices(a, b, c);

    // Print result
    print_matrix(c);

    return 0;
}