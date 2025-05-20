//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 10
#define MAX_COLS 10

typedef struct {
    int rows;
    int cols;
    int **matrix;
} matrix_t;

void init_matrix(matrix_t *m, int rows, int cols) {
    m->rows = rows;
    m->cols = cols;
    m->matrix = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        m->matrix[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            m->matrix[i][j] = rand() % 10;
        }
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

int main() {
    matrix_t a, b, c;

    init_matrix(&a, 5, 5);
    init_matrix(&b, 5, 5);
    init_matrix(&c, 5, 5);

    add_matrix(&a, &b, &c);

    print_matrix(&c);

    return 0;
}