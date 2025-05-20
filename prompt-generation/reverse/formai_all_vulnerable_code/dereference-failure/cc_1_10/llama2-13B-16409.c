//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATRIX_ROWS 5
#define MATRIX_COLS 4

typedef struct matrix {
    int rows;
    int cols;
    int **data;
} matrix_t;

void matrix_init(matrix_t *m, int rows, int cols) {
    m->rows = rows;
    m->cols = cols;
    m->data = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        m->data[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            m->data[i][j] = (i * j) % 10;
        }
    }
}

void matrix_print(matrix_t *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%d ", m->data[i][j]);
        }
        printf("\n");
    }
}

void matrix_add(matrix_t *m1, matrix_t *m2) {
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m2->cols; j++) {
            m1->data[i][j] = m1->data[i][j] + m2->data[i][j];
        }
    }
}

int main() {
    matrix_t m1, m2, m3;

    matrix_init(&m1, MATRIX_ROWS, MATRIX_COLS);
    matrix_init(&m2, MATRIX_ROWS, MATRIX_COLS);
    matrix_init(&m3, MATRIX_ROWS, MATRIX_COLS);

    matrix_print(&m1);
    matrix_print(&m2);

    matrix_add(&m1, &m2);

    matrix_print(&m3);

    return 0;
}