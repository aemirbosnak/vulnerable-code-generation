//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: systematic
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

void init_matrix(matrix_t *m) {
    m->rows = ROWS;
    m->cols = COLS;
    m->matrix = (int **)calloc(m->rows, sizeof(int *));
    for (int i = 0; i < m->rows; i++) {
        m->matrix[i] = (int *)calloc(m->cols, sizeof(int));
    }
}

void print_matrix(matrix_t *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%d ", m->matrix[i][j]);
        }
        printf("\n");
    }
}

void add_matrix(matrix_t *a, matrix_t *b, matrix_t *c) {
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            c->matrix[i][j] = a->matrix[i][j] + b->matrix[i][j];
        }
    }
}

void multiply_matrix(matrix_t *a, matrix_t *b, matrix_t *c) {
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            int sum = 0;
            for (int k = 0; k < a->cols; k++) {
                sum += a->matrix[i][k] * b->matrix[k][j];
            }
            c->matrix[i][j] = sum;
        }
    }
}

int main() {
    matrix_t a, b, c;
    init_matrix(&a);
    init_matrix(&b);
    init_matrix(&c);

    // Matrix addition
    add_matrix(&a, &b, &c);
    print_matrix(&c);

    // Matrix multiplication
    multiply_matrix(&a, &b, &c);
    print_matrix(&c);

    return 0;
}