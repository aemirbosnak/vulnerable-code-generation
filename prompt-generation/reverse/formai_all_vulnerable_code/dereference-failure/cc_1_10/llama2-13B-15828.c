//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: intelligent
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

void matrix_print(matrix_t *mat) {
    int i, j;

    for (i = 0; i < mat->rows; i++) {
        for (j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i][j]);
        }
        printf("\n");
    }
}

matrix_t *matrix_create(int rows, int cols) {
    matrix_t *mat = (matrix_t *)malloc(sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (int **)malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; i++) {
        mat->data[i] = (int *)malloc(cols * sizeof(int));
    }

    return mat;
}

matrix_t *matrix_add(matrix_t *a, matrix_t *b) {
    matrix_t *c = matrix_create(a->rows, a->cols);

    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            c->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }

    return c;
}

matrix_t *matrix_multiply(matrix_t *a, matrix_t *b) {
    matrix_t *c = matrix_create(a->rows, b->cols);

    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            int sum = 0;

            for (int k = 0; k < a->cols; k++) {
                sum += a->data[i][k] * b->data[k][j];
            }

            c->data[i][j] = sum;
        }
    }

    return c;
}

int main() {
    matrix_t *a = matrix_create(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *b = matrix_create(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *c;

    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            a->data[i][j] = i * j;
            b->data[i][j] = i * j + 1;
        }
    }

    c = matrix_add(a, b);
    matrix_print(c);

    c = matrix_multiply(a, b);
    matrix_print(c);

    free(a);
    free(b);
    free(c);

    return 0;
}