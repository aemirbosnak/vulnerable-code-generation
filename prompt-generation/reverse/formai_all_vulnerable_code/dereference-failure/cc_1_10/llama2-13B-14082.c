//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATRIX_ROWS 5
#define MATRIX_COLS 6

typedef struct matrix {
    int rows;
    int cols;
    int **data;
} matrix_t;

void init_matrix(matrix_t *mat) {
    mat->rows = MATRIX_ROWS;
    mat->cols = MATRIX_COLS;
    mat->data = (int **)calloc(MATRIX_ROWS, sizeof(int *));
    for (int i = 0; i < MATRIX_ROWS; i++) {
        mat->data[i] = (int *)calloc(MATRIX_COLS, sizeof(int));
    }
}

void print_matrix(matrix_t *mat) {
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            printf("%d ", mat->data[i][j]);
        }
        printf("\n");
    }
}

void add_matrices(matrix_t *a, matrix_t *b, matrix_t *res) {
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            res->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
}

void multiply_matrices(matrix_t *a, matrix_t *b, matrix_t *res) {
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            int sum = 0;
            for (int k = 0; k < MATRIX_COLS; k++) {
                sum += a->data[i][k] * b->data[k][j];
            }
            res->data[i][j] = sum;
        }
    }
}

int main() {
    matrix_t a, b, res;

    init_matrix(&a);
    init_matrix(&b);
    init_matrix(&res);

    // Set up matrices
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            a.data[i][j] = i * j;
            b.data[i][j] = i * j + 1;
            res.data[i][j] = 0;
        }
    }

    // Add matrices
    add_matrices(&a, &b, &res);

    // Print result
    print_matrix(&res);

    // Multiply matrices
    multiply_matrices(&a, &b, &res);

    // Print result
    print_matrix(&res);

    return 0;
}