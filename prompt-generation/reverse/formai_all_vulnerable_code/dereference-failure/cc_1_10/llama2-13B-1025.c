//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATRIX_ROWS 5
#define MATRIX_COLS 4

typedef struct {
    int rows;
    int cols;
    int **data;
} matrix_t;

void matrix_init(matrix_t *mat, int rows, int cols) {
    mat->rows = rows;
    mat->cols = cols;
    mat->data = calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat->data[i] = calloc(cols, sizeof(int));
    }
}

void matrix_print(matrix_t *mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i][j]);
        }
        printf("\n");
    }
}

void matrix_add(matrix_t *a, matrix_t *b, matrix_t *res) {
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            res->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
}

void matrix_sub(matrix_t *a, matrix_t *b, matrix_t *res) {
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            res->data[i][j] = a->data[i][j] - b->data[i][j];
        }
    }
}

void matrix_mul(matrix_t *a, matrix_t *b, matrix_t *res) {
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            int sum = 0;
            for (int k = 0; k < a->cols; k++) {
                sum += a->data[i][k] * b->data[k][j];
            }
            res->data[i][j] = sum;
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
            a.data[i][j] = i * j;
            b.data[i][j] = i * j + 1;
        }
    }

    matrix_add(&a, &b, &c);
    matrix_sub(&a, &b, &c);
    matrix_mul(&a, &b, &c);

    matrix_print(&c);

    return 0;
}