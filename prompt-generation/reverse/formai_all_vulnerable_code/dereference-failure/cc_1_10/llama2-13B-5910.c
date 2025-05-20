//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATRIX_ROWS 10
#define MATRIX_COLS 10

typedef struct matrix {
    int rows;
    int cols;
    int *data;
} matrix_t;

void matrix_init(matrix_t *m, int rows, int cols) {
    m->rows = rows;
    m->cols = cols;
    m->data = calloc(rows * cols, sizeof(int));
}

void matrix_print(matrix_t *m) {
    int i, j;
    for (i = 0; i < m->rows; i++) {
        for (j = 0; j < m->cols; j++) {
            printf("%d ", m->data[i * m->cols + j]);
        }
        printf("\n");
    }
}

void matrix_add(matrix_t *a, matrix_t *b, matrix_t *c) {
    int i, j, k;
    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < a->cols; j++) {
            c->data[i * c->cols + j] = a->data[i * a->cols + j] + b->data[i * b->cols + j];
        }
    }
}

int main() {
    matrix_t a, b, c;

    matrix_init(&a, MATRIX_ROWS, MATRIX_COLS);
    matrix_init(&b, MATRIX_ROWS, MATRIX_COLS);
    matrix_init(&c, MATRIX_ROWS, MATRIX_COLS);

    // Populate matrices
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            a.data[i * a.cols + j] = i * j;
            b.data[i * b.cols + j] = i * (j + 1);
        }
    }

    // Add matrices
    matrix_add(&a, &b, &c);

    // Print result
    matrix_print(&c);

    return 0;
}