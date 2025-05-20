//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define ROW_SIZE 5
#define COL_SIZE 3

typedef struct {
    int rows;
    int cols;
    int **matrix;
} Matrix;

void init_matrix(Matrix *m, int rows, int cols) {
    m->rows = rows;
    m->cols = cols;
    m->matrix = calloc(rows, sizeof(int *));

    for (int i = 0; i < rows; i++) {
        m->matrix[i] = calloc(cols, sizeof(int));
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

void add_matrices(Matrix *a, Matrix *b, Matrix *c) {
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            c->matrix[i][j] = a->matrix[i][0] + b->matrix[0][j];
        }
    }
}

void multiply_matrices(Matrix *a, Matrix *b, Matrix *c) {
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            int sum = 0;
            for (int k = 0; k < a->cols; k++) {
                sum += a->matrix[i][k] * b->matrix[k][j];
            }
            c->matrix[i][j] = sum;
        }
    }
}

int main() {
    Matrix a, b, c;

    init_matrix(&a, ROW_SIZE, COL_SIZE);
    init_matrix(&b, ROW_SIZE, COL_SIZE);
    init_matrix(&c, ROW_SIZE, COL_SIZE);

    // Populate matrices
    for (int i = 0; i < ROW_SIZE; i++) {
        for (int j = 0; j < COL_SIZE; j++) {
            a.matrix[i][j] = i * j;
            b.matrix[i][j] = i * j * 2;
        }
    }

    // Add matrices
    add_matrices(&a, &b, &c);

    // Multiply matrices
    multiply_matrices(&a, &b, &c);

    // Print result
    print_matrix(&c);

    return 0;
}