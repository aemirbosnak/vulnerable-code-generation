//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATRIX_ROWS 10
#define MATRIX_COLS 10

typedef struct matrix {
    int rows;
    int cols;
    int **data;
} matrix_t;

matrix_t *create_matrix(int rows, int cols) {
    matrix_t *mat = (matrix_t *)calloc(1, sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (int **)calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat->data[i] = (int *)calloc(cols, sizeof(int));
    }
    return mat;
}

void print_matrix(matrix_t *mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i][j]);
        }
        printf("\n");
    }
}

void multiply_matrices(matrix_t *a, matrix_t *b, matrix_t **c) {
    if (a->rows != b->cols) {
        printf("Matrix dimensions must be compatible\n");
        return;
    }
    *c = create_matrix(a->rows, b->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            int sum = 0;
            for (int k = 0; k < a->cols; k++) {
                sum += a->data[i][k] * b->data[k][j];
            }
            (*c)->data[i][j] = sum;
        }
    }
}

int main() {
    matrix_t *a = create_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *b = create_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *c;

    // Initialize matrices
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            a->data[i][j] = i * j;
            b->data[i][j] = i + j;
        }
    }

    // Multiply matrices
    multiply_matrices(a, b, &c);

    // Print result
    print_matrix(c);

    return 0;
}