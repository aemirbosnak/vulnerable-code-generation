//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MATRIX_ROWS 10
#define MATRIX_COLS 10
#define MATRIX_SIZE (MATRIX_ROWS * MATRIX_COLS)

typedef struct {
    int rows;
    int cols;
    int *data;
} matrix_t;

matrix_t *create_matrix(int rows, int cols) {
    matrix_t *matrix = (matrix_t *)malloc(sizeof(matrix_t));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (int *)malloc(sizeof(int) * MATRIX_SIZE);
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

void add_matrix(matrix_t *a, matrix_t *b) {
    int i, j, k;
    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < a->cols; j++) {
            for (k = 0; k < b->cols; k++) {
                a->data[i * a->cols + j] += b->data[k * b->cols + j];
            }
        }
    }
}

void multiply_matrix(matrix_t *a, matrix_t *b) {
    int i, j, k;
    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < a->cols; j++) {
            int sum = 0;
            for (k = 0; k < b->cols; k++) {
                sum += a->data[i * a->cols + j] * b->data[k * b->cols + j];
            }
            a->data[i * a->cols + j] = sum;
        }
    }
}

int main() {
    srandom(time(NULL));
    matrix_t *a = create_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *b = create_matrix(MATRIX_ROWS, MATRIX_COLS);

    for (int i = 0; i < MATRIX_SIZE; i++) {
        a->data[i] = random() % 10;
        b->data[i] = random() % 10;
    }

    add_matrix(a, b);
    multiply_matrix(a, b);

    print_matrix(a);
    print_matrix(b);

    return 0;
}