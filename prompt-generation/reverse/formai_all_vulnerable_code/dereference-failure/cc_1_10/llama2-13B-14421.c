//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MATRIX_ROWS 10
#define MATRIX_COLS 10

typedef struct matrix {
    int rows;
    int cols;
    int *data;
} matrix_t;

matrix_t *create_matrix(int rows, int cols) {
    matrix_t *matrix = malloc(sizeof(matrix_t));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = malloc(sizeof(int) * rows * cols);
    return matrix;
}

void print_matrix(matrix_t *matrix) {
    int i, j;
    for (i = 0; i < matrix->rows; i++) {
        for (j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i * matrix->cols + j]);
        }
        printf("\n");
    }
}

void matrix_add(matrix_t *a, matrix_t *b) {
    int i, j;
    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < a->cols; j++) {
            a->data[i * a->cols + j] += b->data[i * b->cols + j];
        }
    }
}

void matrix_subtract(matrix_t *a, matrix_t *b) {
    int i, j;
    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < a->cols; j++) {
            a->data[i * a->cols + j] -= b->data[i * b->cols + j];
        }
    }
}

void matrix_multiply(matrix_t *a, matrix_t *b) {
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
    srand(time(NULL));

    matrix_t *a = create_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *b = create_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *c = create_matrix(MATRIX_ROWS, MATRIX_COLS);

    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            a->data[i * a->cols + j] = rand() % 10;
            b->data[i * b->cols + j] = rand() % 10;
        }
    }

    matrix_add(a, b);
    matrix_subtract(a, b);
    matrix_multiply(a, b);

    print_matrix(a);
    print_matrix(b);
    print_matrix(c);

    return 0;
}