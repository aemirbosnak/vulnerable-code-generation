//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 10
#define MAX_COLS 10

typedef struct {
    int rows;
    int cols;
    int *data;
} Matrix;

void init_matrix(Matrix *m, int rows, int cols) {
    m->rows = rows;
    m->cols = cols;
    m->data = (int *)calloc(rows * cols, sizeof(int));
}

void print_matrix(Matrix *m) {
    int i, j;
    for (i = 0; i < m->rows; i++) {
        for (j = 0; j < m->cols; j++) {
            printf("%d ", m->data[i * m->cols + j]);
        }
        printf("\n");
    }
}

void add_matrices(Matrix *m1, Matrix *m2, Matrix *res) {
    int i, j;
    for (i = 0; i < m1->rows; i++) {
        for (j = 0; j < m2->cols; j++) {
            res->data[i * res->cols + j] = m1->data[i * m1->cols + j] + m2->data[i * m2->cols + j];
        }
    }
}

void multiply_matrices(Matrix *m1, Matrix *m2, Matrix *res) {
    int i, j, k;
    for (i = 0; i < m1->rows; i++) {
        for (j = 0; j < m2->cols; j++) {
            int sum = 0;
            for (k = 0; k < m2->rows; k++) {
                sum += m1->data[i * m1->cols + k] * m2->data[k * m2->cols + j];
            }
            res->data[i * res->cols + j] = sum;
        }
    }
}

int main() {
    Matrix m1, m2, res;
    init_matrix(&m1, 3, 3);
    init_matrix(&m2, 3, 3);
    init_matrix(&res, 3, 3);

    // Populate matrices
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m1.data[i * m1.cols + j] = i * j;
            m2.data[i * m2.cols + j] = i * (j + 1);
        }
    }

    // Add matrices
    add_matrices(&m1, &m2, &res);

    // Print result
    print_matrix(&res);

    // Multiply matrices
    multiply_matrices(&m1, &m2, &res);

    // Print result
    print_matrix(&res);

    return 0;
}