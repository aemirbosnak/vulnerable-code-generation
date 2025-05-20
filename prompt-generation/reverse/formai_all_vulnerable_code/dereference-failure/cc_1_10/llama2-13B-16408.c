//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 6

typedef struct {
    int rows;
    int cols;
    int *data;
} matrix_t;

void init_matrix(matrix_t *m) {
    m->rows = ROWS;
    m->cols = COLS;
    m->data = (int *)calloc(m->rows * m->cols, sizeof(int));
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

void add_matrix(matrix_t *a, matrix_t *b, matrix_t *c) {
    int i, j, k;
    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < a->cols; j++) {
            c->data[i * c->cols + j] = a->data[i * a->cols + j] + b->data[i * b->cols + j];
        }
    }
}

void mult_matrix(matrix_t *a, matrix_t *b, matrix_t *c) {
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
    matrix_t a, b, c;

    // Initialize matrices
    init_matrix(&a);
    init_matrix(&b);
    init_matrix(&c);

    // Set matrix values
    a.data[0 * a.cols + 0] = 1;
    a.data[0 * a.cols + 1] = 2;
    a.data[0 * a.cols + 2] = 3;
    a.data[1 * a.cols + 0] = 4;
    a.data[1 * a.cols + 1] = 5;
    a.data[1 * a.cols + 2] = 6;

    b.data[0 * b.cols + 0] = 7;
    b.data[0 * b.cols + 1] = 8;
    b.data[0 * b.cols + 2] = 9;
    b.data[1 * b.cols + 0] = 10;
    b.data[1 * b.cols + 1] = 11;
    b.data[1 * b.cols + 2] = 12;

    // Perform matrix operations
    add_matrix(&a, &b, &c);
    mult_matrix(&a, &b, &c);

    // Print matrices
    print_matrix(&a);
    print_matrix(&b);
    print_matrix(&c);

    return 0;
}