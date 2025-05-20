//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>

#define MATRIX_ROWS 10
#define MATRIX_COLS 10
#define MATRIX_SIZE (MATRIX_ROWS * MATRIX_COLS)

typedef struct matrix {
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

void add_matrix(matrix_t *m1, matrix_t *m2) {
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            m1->data[i][j] += m2->data[i][j];
        }
    }
}

int main() {
    srand(time(NULL));
    matrix_t m1, m2, res;
    init_matrix(&m1);
    init_matrix(&m2);
    init_matrix(&res);

    // Add two matrices
    add_matrix(&m1, &m2);

    // Print the result
    print_matrix(&res);

    return 0;
}