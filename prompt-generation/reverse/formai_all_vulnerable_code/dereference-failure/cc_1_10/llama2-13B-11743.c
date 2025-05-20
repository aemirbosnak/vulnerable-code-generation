//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW_SIZE 5
#define COL_SIZE 10

typedef struct matrix {
    int rows;
    int cols;
    int **data;
} matrix_t;

void init_matrix(matrix_t *m, int rows, int cols) {
    m->rows = rows;
    m->cols = cols;
    m->data = (int **)calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; i++) {
        m->data[i] = (int *)calloc(COL_SIZE, sizeof(int));
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

void add_matrices(matrix_t *a, matrix_t *b, matrix_t *c) {
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            c->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
}

int main() {
    matrix_t a, b, c;

    // Initialize matrices
    init_matrix(&a, 3, 4);
    init_matrix(&b, 4, 5);
    init_matrix(&c, 3, 5);

    // Fill matrices with some data
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            a.data[i][j] = i * j;
        }
    }
    for (int i = 0; i < b.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            b.data[i][j] = i + j;
        }
    }

    // Add matrices
    add_matrices(&a, &b, &c);

    // Print result
    print_matrix(&c);

    return 0;
}