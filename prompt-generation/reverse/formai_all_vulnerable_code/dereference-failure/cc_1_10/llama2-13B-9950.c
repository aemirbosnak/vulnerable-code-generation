//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATRIX_ROWS 4
#define MATRIX_COLS 4

typedef struct {
    int rows;
    int cols;
    int **elements;
} matrix_t;

void init_matrix(matrix_t *m) {
    m->rows = MATRIX_ROWS;
    m->cols = MATRIX_COLS;
    m->elements = calloc(m->rows, sizeof(int *));
    for (int i = 0; i < m->rows; i++) {
        m->elements[i] = calloc(m->cols, sizeof(int));
    }
}

void print_matrix(matrix_t *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%d ", m->elements[i][j]);
        }
        printf("\n");
    }
}

void add_matrices(matrix_t *a, matrix_t *b, matrix_t *res) {
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            res->elements[i][j] = a->elements[i][j] + b->elements[i][j];
        }
    }
}

int main() {
    matrix_t a, b, res;

    // Initialize matrices
    init_matrix(&a);
    init_matrix(&b);
    init_matrix(&res);

    // Set matrix values
    a.elements[0][0] = 1;
    a.elements[0][1] = 2;
    a.elements[0][2] = 3;
    a.elements[1][0] = 4;
    a.elements[1][1] = 5;
    a.elements[1][2] = 6;
    b.elements[0][0] = 7;
    b.elements[0][1] = 8;
    b.elements[0][2] = 9;
    b.elements[1][0] = 10;
    b.elements[1][1] = 11;
    b.elements[1][2] = 12;

    // Add matrices
    add_matrices(&a, &b, &res);

    // Print result
    print_matrix(&res);

    return 0;
}