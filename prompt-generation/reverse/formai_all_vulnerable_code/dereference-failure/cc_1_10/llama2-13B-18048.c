//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 4
#define COLS 4

typedef struct {
    int rows;
    int cols;
    int **matrix;
} matrix_t;

void init_matrix(matrix_t *mat) {
    mat->rows = ROWS;
    mat->cols = COLS;
    mat->matrix = (int **) malloc(ROWS * sizeof(int *));
    for (int i = 0; i < ROWS; i++) {
        mat->matrix[i] = (int *) malloc(COLS * sizeof(int));
        for (int j = 0; j < COLS; j++) {
            mat->matrix[i][j] = i * j;
        }
    }
}

void print_matrix(matrix_t *mat) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", mat->matrix[i][j]);
        }
        printf("\n");
    }
}

void add_matrix(matrix_t *a, matrix_t *b, matrix_t *res) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            res->matrix[i][j] = a->matrix[i][j] + b->matrix[i][j];
        }
    }
}

void mult_matrix(matrix_t *a, matrix_t *b, matrix_t *res) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int sum = 0;
            for (int k = 0; k < COLS; k++) {
                sum += a->matrix[i][k] * b->matrix[k][j];
            }
            res->matrix[i][j] = sum;
        }
    }
}

int main() {
    matrix_t a, b, res;
    init_matrix(&a);
    init_matrix(&b);
    init_matrix(&res);

    // Add two matrices
    add_matrix(&a, &b, &res);
    print_matrix(&res);

    // Multiply two matrices
    mult_matrix(&a, &b, &res);
    print_matrix(&res);

    return 0;
}