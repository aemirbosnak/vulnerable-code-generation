//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define MATRIX_ROWS 5
#define MATRIX_COLS 7

typedef struct {
    int rows;
    int cols;
    int **matrix;
} matrix_t;

void matrix_init(matrix_t *m, int rows, int cols) {
    m->rows = rows;
    m->cols = cols;
    m->matrix = calloc(m->rows, sizeof(int *));
    for (int i = 0; i < m->rows; i++) {
        m->matrix[i] = calloc(m->cols, sizeof(int));
    }
}

void matrix_print(matrix_t *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%d ", m->matrix[i][j]);
        }
        printf("\n");
    }
}

void matrix_add(matrix_t *m1, matrix_t *m2) {
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m2->cols; j++) {
            m1->matrix[i][j] = m1->matrix[i][j] + m2->matrix[i][j];
        }
    }
}

void matrix_mul(matrix_t *m1, matrix_t *m2) {
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m2->cols; j++) {
            int sum = 0;
            for (int k = 0; k < m2->rows; k++) {
                sum += m1->matrix[i][k] * m2->matrix[k][j];
            }
            m1->matrix[i][j] = sum;
        }
    }
}

int main() {
    matrix_t m1, m2, m3;

    matrix_init(&m1, MATRIX_ROWS, MATRIX_COLS);
    matrix_init(&m2, MATRIX_ROWS, MATRIX_COLS);
    matrix_init(&m3, MATRIX_ROWS, MATRIX_COLS);

    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            m1.matrix[i][j] = i * j;
            m2.matrix[i][j] = i * j * 2;
        }
    }

    matrix_add(&m1, &m2);
    matrix_add(&m1, &m2);
    matrix_mul(&m1, &m3);

    matrix_print(&m1);

    return 0;
}