//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 5
#define N 7

typedef struct {
    int rows;
    int cols;
    int *data;
} Matrix;

void init_matrix(Matrix *m) {
    m->rows = M;
    m->cols = N;
    m->data = (int *)calloc(m->rows * m->cols, sizeof(int));
}

void print_matrix(Matrix *m) {
    int i, j;
    for (i = 0; i < m->rows; i++) {
        for (j = 0; j < m->cols; j++) {
            printf("%d ", m->data[i * m->cols + j]);
        }
        printf("\n");
    }
}

void add_matrix(Matrix *a, Matrix *b, Matrix *c) {
    int i, j, k;
    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < a->cols; j++) {
            for (k = 0; k < b->rows; k++) {
                c->data[i * c->cols + j] += a->data[i * a->cols + j] + b->data[k * b->cols + j];
            }
        }
    }
}

int main() {
    Matrix a, b, c;
    init_matrix(&a);
    init_matrix(&b);
    init_matrix(&c);

    // Populate matrices
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            a.data[i * a.cols + j] = i * j;
            b.data[i * b.cols + j] = i * j + 1;
        }
    }

    // Add matrices
    add_matrix(&a, &b, &c);

    // Print result
    print_matrix(&c);

    return 0;
}