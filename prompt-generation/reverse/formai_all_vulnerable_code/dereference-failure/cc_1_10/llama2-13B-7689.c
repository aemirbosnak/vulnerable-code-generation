//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: rigorous
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
    m->data = (int *)malloc(rows * cols * sizeof(int));
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

void add_matrices(Matrix *a, Matrix *b, Matrix *res) {
    int i, j, k;
    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < a->cols; j++) {
            for (k = 0; k < b->cols; k++) {
                res->data[i * res->cols + j + k] = a->data[i * a->cols + j] + b->data[k];
            }
        }
    }
}

void multiply_matrices(Matrix *a, Matrix *b, Matrix *res) {
    int i, j, k;
    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < a->cols; j++) {
            for (k = 0; k < b->rows; k++) {
                int sum = 0;
                for (int l = 0; l < b->cols; l++) {
                    sum += a->data[i * a->cols + j] * b->data[k * b->cols + l];
                }
                res->data[i * res->cols + j + k] = sum;
            }
        }
    }
}

int main() {
    Matrix a, b, res;

    // Initialize matrices
    init_matrix(&a, 3, 3);
    init_matrix(&b, 3, 2);
    init_matrix(&res, 3, 3);

    // Set matrix elements
    a.data[0 * a.cols + 0] = 1; a.data[0 * a.cols + 1] = 2; a.data[0 * a.cols + 2] = 3;
    a.data[1 * a.cols + 0] = 4; a.data[1 * a.cols + 1] = 5; a.data[1 * a.cols + 2] = 6;
    a.data[2 * a.cols + 0] = 7; a.data[2 * a.cols + 1] = 8; a.data[2 * a.cols + 2] = 9;

    b.data[0 * b.cols + 0] = 10; b.data[0 * b.cols + 1] = 20;
    b.data[1 * b.cols + 0] = 30; b.data[1 * b.cols + 1] = 40;

    // Perform matrix operations
    add_matrices(&a, &b, &res);
    multiply_matrices(&a, &b, &res);

    // Print results
    print_matrix(&res);

    return 0;
}