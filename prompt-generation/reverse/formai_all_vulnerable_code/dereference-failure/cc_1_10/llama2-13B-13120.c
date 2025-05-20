//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATRIX_ROWS 4
#define MATRIX_COLS 4

typedef struct matrix {
    int rows;
    int cols;
    int *data;
} matrix_t;

void matrix_print(matrix_t *matrix) {
    int i, j;
    for (i = 0; i < matrix->rows; i++) {
        for (j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i * matrix->cols + j]);
        }
        printf("\n");
    }
}

matrix_t *matrix_create(int rows, int cols) {
    matrix_t *matrix = malloc(sizeof(matrix_t));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = malloc(sizeof(int) * rows * cols);
    return matrix;
}

void matrix_destroy(matrix_t *matrix) {
    free(matrix->data);
    free(matrix);
}

matrix_t *matrix_mult(matrix_t *a, matrix_t *b) {
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
            b->data[i * b->cols + j] = i * j + 1;
        }
    }

    // Matrix multiplication
    c = matrix_mult(a, b);

    // Print result
    matrix_print(c);

    // Clean up
    matrix_destroy(a);
    matrix_destroy(b);
    matrix_destroy(c);

    return 0;
}