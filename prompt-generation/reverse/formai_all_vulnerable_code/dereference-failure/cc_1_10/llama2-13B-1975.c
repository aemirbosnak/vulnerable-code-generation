//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define M 5
#define N 3
#define P 2

typedef struct {
    int rows;
    int cols;
    int **data;
} matrix_t;

void init_matrix(matrix_t *m, int r, int c) {
    m->rows = r;
    m->cols = c;
    m->data = malloc(r * sizeof(int *));
    for (int i = 0; i < r; i++) {
        m->data[i] = malloc(c * sizeof(int));
        for (int j = 0; j < c; j++) {
            m->data[i][j] = rand() % 10;
        }
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

void add_matrices(matrix_t *a, matrix_t *b, matrix_t *c) {
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            c->data[i][j] = a->data[i][0] + b->data[0][j];
        }
    }
}

int main() {
    matrix_t A, B, C;

    init_matrix(&A, M, N);
    init_matrix(&B, M, P);
    init_matrix(&C, N, P);

    add_matrices(&A, &B, &C);

    print_matrix(&C);

    return 0;
}