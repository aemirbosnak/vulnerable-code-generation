//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    int rows;
    int cols;
    int *data;
} Matrix;

void matrix_init(Matrix *m, int rows, int cols) {
    m->rows = rows;
    m->cols = cols;
    m->data = malloc(rows * cols * sizeof(int));
}

void matrix_destroy(Matrix *m) {
    free(m->data);
}

int matrix_get(Matrix *m, int row, int col) {
    return m->data[row * m->cols + col];
}

void matrix_set(Matrix *m, int row, int col, int value) {
    m->data[row * m->cols + col] = value;
}

Matrix matrix_add(Matrix *a, Matrix *b) {
    Matrix c;
    c.rows = a->rows;
    c.cols = a->cols;
    c.data = malloc(c.rows * c.cols * sizeof(int));

    for (int i = 0; i < c.rows; i++) {
        for (int j = 0; j < c.cols; j++) {
            c.data[i * c.cols + j] = a->data[i * a->cols + j] + b->data[i * b->cols + j];
        }
    }

    return c;
}

Matrix matrix_subtract(Matrix *a, Matrix *b) {
    Matrix c;
    c.rows = a->rows;
    c.cols = a->cols;
    c.data = malloc(c.rows * c.cols * sizeof(int));

    for (int i = 0; i < c.rows; i++) {
        for (int j = 0; j < c.cols; j++) {
            c.data[i * c.cols + j] = a->data[i * a->cols + j] - b->data[i * b->cols + j];
        }
    }

    return c;
}

Matrix matrix_multiply(Matrix *a, Matrix *b) {
    Matrix c;
    c.rows = a->cols;
    c.cols = b->rows;
    c.data = malloc(c.rows * c.cols * sizeof(int));

    for (int i = 0; i < c.rows; i++) {
        for (int j = 0; j < c.cols; j++) {
            int sum = 0;
            for (int k = 0; k < a->cols; k++) {
                sum += a->data[i * a->cols + k] * b->data[k * b->rows + j];
            }
            c.data[i * c.cols + j] = sum;
        }
    }

    return c;
}

int main() {
    Matrix a, b, c;

    matrix_init(&a, 3, 4);
    matrix_init(&b, 4, 3);
    matrix_init(&c, 3, 3);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            matrix_set(&a, i, j, i * j);
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            matrix_set(&b, i, j, i * j);
        }
    }

    Matrix result = matrix_add(&a, &b);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", result.data[i * result.cols + j]);
        }
        printf("\n");
    }

    matrix_destroy(&a);
    matrix_destroy(&b);
    matrix_destroy(&c);

    return 0;
}