//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define ROW_SIZE 5
#define COL_SIZE 7

typedef struct {
    int rows;
    int cols;
    int **matrix;
} matrix_t;

void init_matrix(matrix_t *m) {
    m->rows = 5;
    m->cols = 7;
    m->matrix = (int **) malloc(m->rows * sizeof(int *));
    for (int i = 0; i < m->rows; i++) {
        m->matrix[i] = (int *) malloc(m->cols * sizeof(int));
        for (int j = 0; j < m->cols; j++) {
            m->matrix[i][j] = i * j;
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

void matrix_add(matrix_t *a, matrix_t *b) {
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            a->matrix[i][j] = a->matrix[i][j] + b->matrix[i][j];
        }
    }
}

void matrix_multiply(matrix_t *a, matrix_t *b) {
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

    matrix_add(&a, &b);
    matrix_multiply(&a, &c);

    print_matrix(&c);

    return 0;
}