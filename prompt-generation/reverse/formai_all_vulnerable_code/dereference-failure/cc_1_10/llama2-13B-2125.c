//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATRIX_ROWS 5
#define MATRIX_COLS 3

typedef struct {
    int rows;
    int cols;
    int **data;
} matrix_t;

void matrix_init(matrix_t *matrix) {
    matrix->rows = MATRIX_ROWS;
    matrix->cols = MATRIX_COLS;
    matrix->data = calloc(matrix->rows, sizeof(int *));
    for (int i = 0; i < matrix->rows; i++) {
        matrix->data[i] = calloc(matrix->cols, sizeof(int));
    }
}

void matrix_print(matrix_t *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

void matrix_add(matrix_t *a, matrix_t *b) {
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            a->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
}

void matrix_subtract(matrix_t *a, matrix_t *b) {
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            a->data[i][j] = a->data[i][j] - b->data[i][j];
        }
    }
}

void matrix_multiply(matrix_t *a, matrix_t *b) {
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            int sum = 0;
            for (int k = 0; k < a->cols; k++) {
                sum += a->data[i][k] * b->data[k][j];
            }
            a->data[i][j] = sum;
        }
    }
}

int main() {
    matrix_t a, b, c;

    matrix_init(&a);
    matrix_init(&b);
    matrix_init(&c);

    // Initialize matrix A
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            a.data[i][j] = i * j;
        }
    }

    // Initialize matrix B
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            b.data[i][j] = i + j;
        }
    }

    // Matrix addition
    matrix_add(&a, &b);

    // Matrix subtraction
    matrix_subtract(&a, &b);

    // Matrix multiplication
    matrix_multiply(&a, &b);

    matrix_print(&c);

    return 0;
}