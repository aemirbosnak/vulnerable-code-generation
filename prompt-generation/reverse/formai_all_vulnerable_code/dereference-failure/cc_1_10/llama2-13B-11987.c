//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW_COUNT 5
#define COL_COUNT 7

typedef struct {
    int rows;
    int cols;
    int **matrix;
} Matrix;

void init_matrix(Matrix *m) {
    m->rows = ROW_COUNT;
    m->cols = COL_COUNT;
    m->matrix = malloc(m->rows * sizeof(int *));
    for (int i = 0; i < m->rows; i++) {
        m->matrix[i] = malloc(m->cols * sizeof(int));
        for (int j = 0; j < m->cols; j++) {
            m->matrix[i][j] = rand() % 10;
        }
    }
}

void print_matrix(Matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%d ", m->matrix[i][j]);
        }
        printf("\n");
    }
}

void add_matrix(Matrix *m1, Matrix *m2) {
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m2->cols; j++) {
            m1->matrix[i][j] = m1->matrix[i][j] + m2->matrix[0][j];
        }
    }
}

int main() {
    Matrix m1, m2, result;

    init_matrix(&m1);
    init_matrix(&m2);

    add_matrix(&m1, &m2);

    print_matrix(&result);

    return 0;
}