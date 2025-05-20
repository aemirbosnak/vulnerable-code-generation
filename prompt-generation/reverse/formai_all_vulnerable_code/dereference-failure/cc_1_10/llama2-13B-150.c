//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MATRIX_ROWS 10
#define MATRIX_COLS 10

typedef struct {
    int rows;
    int cols;
    int *data;
} matrix_t;

matrix_t *create_matrix(int rows, int cols) {
    matrix_t *mat = malloc(sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = malloc(sizeof(int) * rows * cols);
    return mat;
}

void print_matrix(matrix_t *mat) {
    int i, j;
    for (i = 0; i < mat->rows; i++) {
        for (j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i * mat->cols + j]);
        }
        printf("\n");
    }
}

void multiply_matrices(matrix_t *a, matrix_t *b, matrix_t *res) {
    int i, j, k;
    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < b->cols; j++) {
            int sum = 0;
            for (k = 0; k < a->cols; k++) {
                sum += a->data[i * a->cols + k] * b->data[k * b->cols + j];
            }
            res->data[i * res->cols + j] = sum;
        }
    }
}

void add_matrices(matrix_t *a, matrix_t *b, matrix_t *res) {
    int i, j;
    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < res->cols; j++) {
            res->data[i * res->cols + j] = a->data[i * a->cols + j] + b->data[i * b->cols + j];
        }
    }
}

int main() {
    srand(time(NULL));

    matrix_t *a = create_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *b = create_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *res = create_matrix(MATRIX_ROWS, MATRIX_COLS);

    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            a->data[i * a->cols + j] = rand() % 10;
            b->data[i * b->cols + j] = rand() % 10;
        }
    }

    multiply_matrices(a, b, res);
    add_matrices(a, b, res);

    print_matrix(res);

    free(a->data);
    free(b->data);
    free(res->data);
    free(a);
    free(b);
    free(res);

    return 0;
}