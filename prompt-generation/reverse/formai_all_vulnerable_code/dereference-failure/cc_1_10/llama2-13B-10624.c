//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MATRIX_ROWS 5
#define MATRIX_COLS 7

typedef struct {
    int rows;
    int cols;
    int **matrix;
} matrix_t;

void init_matrix(matrix_t *m) {
    m->rows = MATRIX_ROWS;
    m->cols = MATRIX_COLS;
    m->matrix = (int **)calloc(m->rows, sizeof(int *));
    for (int i = 0; i < m->rows; i++) {
        m->matrix[i] = (int *)calloc(m->cols, sizeof(int));
        for (int j = 0; j < m->cols; j++) {
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

void add_matrix(matrix_t *a, matrix_t *b) {
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            a->matrix[i][j] = a->matrix[i][j] + b->matrix[i][j];
        }
    }
}

int main() {
    matrix_t a, b, c;

    init_matrix(&a);
    init_matrix(&b);
    init_matrix(&c);

    // Add matrices horizontally
    add_matrix(&a, &b);
    add_matrix(&a, &c);

    // Add matrices vertically
    add_matrix(&b, &c);

    // Print the result
    print_matrix(&c);

    return 0;
}