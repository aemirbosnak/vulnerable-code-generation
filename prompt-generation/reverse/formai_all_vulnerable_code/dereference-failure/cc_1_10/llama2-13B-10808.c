//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    int rows;
    int cols;
    int **data;
} matrix_t;

void init_matrix(matrix_t *m, int rows, int cols) {
    m->rows = rows;
    m->cols = cols;
    m->data = (int **)calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; i++) {
        m->data[i] = (int *)calloc(cols, sizeof(int));
    }
}

void print_matrix(matrix_t *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%d ", m->data[i][j]);
        }
        printf("\n");
    }
}

void add_matrices(matrix_t *a, matrix_t *b, matrix_t *res) {
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            res->data[i][j] = a->data[i][0] + b->data[0][j];
        }
    }
}

void multiply_matrices(matrix_t *a, matrix_t *b, matrix_t *res) {
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            int sum = 0;
            for (int k = 0; k < a->cols; k++) {
                sum += a->data[i][k] * b->data[k][j];
            }
            res->data[i][j] = sum;
        }
    }
}

int main() {
    matrix_t a, b, c;

    // Initialize matrices
    init_matrix(&a, 3, 4);
    init_matrix(&b, 4, 3);
    init_matrix(&c, 3, 3);

    // Add matrices
    add_matrices(&a, &b, &c);

    // Multiply matrices
    multiply_matrices(&a, &b, &c);

    // Print results
    print_matrix(&c);

    return 0;
}