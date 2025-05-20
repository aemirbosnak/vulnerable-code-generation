//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATRIX_ROWS 5
#define MATRIX_COLS 4

typedef struct {
    int rows;
    int cols;
    int **data;
} matrix_t;

void init_matrix(matrix_t *m) {
    m->rows = MATRIX_ROWS;
    m->cols = MATRIX_COLS;
    m->data = malloc(MATRIX_ROWS * sizeof(int *));
    for (int i = 0; i < MATRIX_ROWS; i++) {
        m->data[i] = malloc(MATRIX_COLS * sizeof(int));
        for (int j = 0; j < MATRIX_COLS; j++) {
            m->data[i][j] = rand() % 10;
        }
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

void add_matrix(matrix_t *a, matrix_t *b) {
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            a->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
}

void mult_matrix(matrix_t *a, matrix_t *b) {
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            int sum = 0;
            for (int k = 0; k < MATRIX_ROWS; k++) {
                sum += a->data[i][k] * b->data[k][j];
            }
            a->data[i][j] = sum;
        }
    }
}

int main() {
    matrix_t a, b, c;

    init_matrix(&a);
    init_matrix(&b);
    init_matrix(&c);

    // Add two matrices
    add_matrix(&a, &b);
    print_matrix(&a);

    // Multiply two matrices
    mult_matrix(&a, &b);
    print_matrix(&c);

    return 0;
}