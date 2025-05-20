//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MATRIX_ROWS 10
#define MATRIX_COLS 10

typedef struct {
    int rows;
    int cols;
    int *data;
} matrix_t;

void matrix_init(matrix_t *m, int rows, int cols) {
    m->rows = rows;
    m->cols = cols;
    m->data = calloc(rows * cols, sizeof(int));
}

void matrix_free(matrix_t *m) {
    free(m->data);
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

void matrix_add(matrix_t *a, matrix_t *b) {
    int i, j;
    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < a->cols; j++) {
            a->data[i * a->cols + j] = a->data[i * a->cols + j] + b->data[i * b->cols + j];
        }
    }
}

void matrix_mult(matrix_t *a, matrix_t *b) {
    int i, j, k;
    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < b->cols; j++) {
            int sum = 0;
            for (k = 0; k < a->cols; k++) {
                sum += a->data[i * a->cols + k] * b->data[k * b->cols + j];
            }
            a->data[i * a->cols + j] = sum;
        }
    }
}

int main() {
    matrix_t a, b, c;

    matrix_init(&a, MATRIX_ROWS, MATRIX_COLS);
    matrix_init(&b, MATRIX_ROWS, MATRIX_COLS);
    matrix_init(&c, MATRIX_ROWS, MATRIX_COLS);

    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            a.data[i * a.cols + j] = i * j;
            b.data[i * b.cols + j] = i + j;
        }
    }

    matrix_add(&a, &b);
    matrix_mult(&a, &c);

    matrix_print(&c);

    matrix_free(&a);
    matrix_free(&b);
    matrix_free(&c);

    return 0;
}