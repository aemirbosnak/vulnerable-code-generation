//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: Ken Thompson
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

void init_matrix(matrix_t *m) {
    m->rows = MATRIX_ROWS;
    m->cols = MATRIX_COLS;
    m->data = calloc(MATRIX_ROWS, sizeof(int *));
    for (int i = 0; i < MATRIX_ROWS; i++) {
        m->data[i] = calloc(MATRIX_COLS, sizeof(int));
    }
}

void print_matrix(matrix_t *m) {
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            printf("%d ", m->data[i][j]);
        }
        printf("\n");
    }
}

void add_matrix(matrix_t *a, matrix_t *b, matrix_t *c) {
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            c->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
}

int main() {
    matrix_t a, b, c;

    init_matrix(&a);
    init_matrix(&b);
    init_matrix(&c);

    // Populate matrices
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            a.data[i][j] = i * j;
            b.data[i][j] = i + j;
            c.data[i][j] = 0;
        }
    }

    // Add matrices
    add_matrix(&a, &b, &c);

    // Print result
    print_matrix(&c);

    return 0;
}