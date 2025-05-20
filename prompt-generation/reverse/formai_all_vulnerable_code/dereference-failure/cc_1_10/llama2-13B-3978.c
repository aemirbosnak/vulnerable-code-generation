//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATRIX_ROWS 4
#define MATRIX_COLS 4

typedef struct {
    int rows;
    int cols;
    int **data;
} matrix_t;

void init_matrix(matrix_t *m) {
    m->rows = MATRIX_ROWS;
    m->cols = MATRIX_COLS;
    m->data = calloc(m->rows, sizeof(int *));
    for (int i = 0; i < m->rows; i++) {
        m->data[i] = calloc(m->cols, sizeof(int));
    }
}

void print_matrix(matrix_t *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%d ", m->data[i][j]);
        }
        printf("\n");
    }
}

void matrix_add(matrix_t *a, matrix_t *b, matrix_t *c) {
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            c->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
}

void matrix_mult(matrix_t *a, matrix_t *b, matrix_t *c) {
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            int sum = 0;
            for (int k = 0; k < b->rows; k++) {
                sum += a->data[i][k] * b->data[k][j];
            }
            c->data[i][j] = sum;
        }
    }
}

int main() {
    matrix_t a, b, c;

    init_matrix(&a);
    init_matrix(&b);
    init_matrix(&c);

    a.data[0][0] = 1;
    a.data[0][1] = 2;
    a.data[0][2] = 3;
    a.data[1][0] = 4;
    a.data[1][1] = 5;
    a.data[1][2] = 6;

    b.data[0][0] = 7;
    b.data[0][1] = 8;
    b.data[0][2] = 9;
    b.data[1][0] = 10;
    b.data[1][1] = 11;
    b.data[1][2] = 12;

    matrix_add(&a, &b, &c);
    matrix_mult(&c, &c, &c);

    print_matrix(&c);

    return 0;
}