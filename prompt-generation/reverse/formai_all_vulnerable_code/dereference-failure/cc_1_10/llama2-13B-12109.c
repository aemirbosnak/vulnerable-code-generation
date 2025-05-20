//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 5
#define COLS 7

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

void add_matrix(matrix_t *a, matrix_t *b) {
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            a->matrix[i][j] = a->matrix[i][j] + b->matrix[i][j];
        }
    }
}

void mult_matrix(matrix_t *a, matrix_t *b) {
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            int sum = 0;
            for (int k = 0; k < a->cols; k++) {
                sum += a->matrix[i][k] * b->matrix[k][j];
            }
            a->matrix[i][j] = sum;
        }
    }
}

int main() {
    matrix_t a, b, c;

    init_matrix(&a);
    init_matrix(&b);
    init_matrix(&c);

    // Set up the matrices
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            a.matrix[i][j] = i * j;
            b.matrix[i][j] = i * j + 1;
            c.matrix[i][j] = 0;
        }
    }

    // Add the matrices
    add_matrix(&a, &b);

    // Multiply the matrices
    mult_matrix(&a, &c);

    // Print the result
    print_matrix(&c);

    return 0;
}