//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MATRIX_ROWS 10
#define MATRIX_COLS 10

typedef struct matrix {
    int rows;
    int cols;
    int **data;
} matrix_t;

void init_matrix(matrix_t *m) {
    m->rows = MATRIX_ROWS;
    m->cols = MATRIX_COLS;
    m->data = calloc(m->rows, sizeof(int *));
    for (int i = 0; i < m->rows; i++) {
        m->data[i] = calloc(m->cols, sizeof(int));
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
            res->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
}

int main() {
    srand(time(NULL));
    matrix_t *a, *b, *res;
    init_matrix(&a);
    init_matrix(&b);
    init_matrix(&res);

    // Generate random data
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            a->data[i][j] = rand() % 10;
        }
    }
    for (int i = 0; i < b->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            b->data[i][j] = rand() % 10;
        }
    }

    // Add matrices
    add_matrices(a, b, res);

    // Print result
    print_matrix(res);

    return 0;
}