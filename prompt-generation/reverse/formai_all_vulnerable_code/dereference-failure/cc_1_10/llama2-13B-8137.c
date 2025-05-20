//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define M 10 // magic number for matrix size
#define N 5 // number of operations to perform

typedef struct {
    int rows;
    int cols;
    int *data;
} matrix_t;

matrix_t *create_matrix(int r, int c) {
    matrix_t *m = malloc(sizeof(matrix_t));
    m->rows = r;
    m->cols = c;
    m->data = malloc(r * c * sizeof(int));
    return m;
}

void print_matrix(matrix_t *m) {
    int i, j;
    for (i = 0; i < m->rows; i++) {
        for (j = 0; j < m->cols; j++) {
            printf("%d ", m->data[i * m->cols + j]);
        }
        printf("\n");
    }
}

void add_matrix(matrix_t *m1, matrix_t *m2) {
    int i, j, k;
    for (i = 0; i < m1->rows; i++) {
        for (j = 0; j < m2->cols; j++) {
            m1->data[i * m1->cols + j] += m2->data[i * m2->cols + j];
        }
    }
}

void multiply_matrix(matrix_t *m1, matrix_t *m2) {
    int i, j, k;
    for (i = 0; i < m1->rows; i++) {
        for (j = 0; j < m2->cols; j++) {
            int sum = 0;
            for (k = 0; k < m2->rows; k++) {
                sum += m1->data[i * m1->cols + k] * m2->data[k * m2->cols + j];
            }
            m1->data[i * m1->cols + j] = sum;
        }
    }
}

int main() {
    srand(time(NULL));

    matrix_t *m1 = create_matrix(M, M);
    matrix_t *m2 = create_matrix(M, M);

    // generate random data
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            m1->data[i * M + j] = rand() % 10;
            m2->data[i * M + j] = rand() % 10;
        }
    }

    // perform operations
    add_matrix(m1, m2);
    multiply_matrix(m1, m2);

    // print results
    print_matrix(m1);
    print_matrix(m2);

    return 0;
}