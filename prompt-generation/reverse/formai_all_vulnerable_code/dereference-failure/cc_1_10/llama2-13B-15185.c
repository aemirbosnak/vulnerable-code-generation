//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATRIX_ROWS 4
#define MATRIX_COLS 4

typedef struct {
    int rows;
    int cols;
    int *data;
} matrix_t;

void matrix_print(matrix_t *mat) {
    int i, j;
    for (i = 0; i < mat->rows; i++) {
        for (j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i * mat->cols + j]);
        }
        printf("\n");
    }
}

matrix_t *matrix_create(int rows, int cols) {
    matrix_t *mat = (matrix_t *)calloc(1, sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (int *)calloc(rows * cols, sizeof(int));
    return mat;
}

matrix_t *matrix_add(matrix_t *a, matrix_t *b) {
    matrix_t *c = matrix_create(a->rows, a->cols);
    int i, j;
    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < a->cols; j++) {
            c->data[i * c->cols + j] = a->data[i * a->cols + j] + b->data[i * b->cols + j];
        }
    }
    return c;
}

matrix_t *matrix_subtract(matrix_t *a, matrix_t *b) {
    matrix_t *c = matrix_create(a->rows, a->cols);
    int i, j;
    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < a->cols; j++) {
            c->data[i * c->cols + j] = a->data[i * a->cols + j] - b->data[i * b->cols + j];
        }
    }
    return c;
}

matrix_t *matrix_multiply(matrix_t *a, matrix_t *b) {
    matrix_t *c = matrix_create(a->rows, b->cols);
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
    return c;
}

int main() {
    matrix_t *a = matrix_create(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *b = matrix_create(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *c;

    // Initialize matrices
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            a->data[i * a->cols + j] = i * j;
            b->data[i * b->cols + j] = i * (j + 1);
        }
    }

    // Perform matrix operations
    c = matrix_add(a, b);
    matrix_print(c);

    c = matrix_subtract(a, b);
    matrix_print(c);

    c = matrix_multiply(a, b);
    matrix_print(c);

    return 0;
}