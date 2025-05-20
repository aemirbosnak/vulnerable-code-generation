//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define ROWS 4
#define COLS 4

typedef struct {
    int rows;
    int cols;
    int *data;
} Matrix;

void init_matrix(Matrix *m) {
    m->rows = ROWS;
    m->cols = COLS;
    m->data = (int *)calloc(m->rows * m->cols, sizeof(int));
}

void print_matrix(Matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%d ", m->data[i * m->cols + j]);
        }
        printf("\n");
    }
}

void add_matrices(Matrix *a, Matrix *b, Matrix *c) {
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            c->data[i * c->cols + j] = a->data[i * a->cols + j] + b->data[i * b->cols + j];
        }
    }
}

void multiply_matrices(Matrix *a, Matrix *b, Matrix *c) {
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            int sum = 0;
            for (int k = 0; k < b->rows; k++) {
                sum += a->data[i * a->cols + k] * b->data[k * b->cols + j];
            }
            c->data[i * c->cols + j] = sum;
        }
    }
}

int main() {
    Matrix a, b, c;

    init_matrix(&a);
    init_matrix(&b);
    init_matrix(&c);

    a.data[0 * a.cols + 0] = 1;
    a.data[0 * a.cols + 1] = 2;
    a.data[0 * a.cols + 2] = 3;
    a.data[0 * a.cols + 3] = 4;

    b.data[0 * b.cols + 0] = 5;
    b.data[0 * b.cols + 1] = 6;
    b.data[0 * b.cols + 2] = 7;
    b.data[0 * b.cols + 3] = 8;

    add_matrices(&a, &b, &c);

    print_matrix(&c);

    multiply_matrices(&a, &b, &c);

    print_matrix(&c);

    return 0;
}