//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000
#define PRIME 31

typedef struct {
    int *data;
    int rows;
    int cols;
} matrix;

void generate_matrix(matrix *m) {
    int i, j;
    srand(time(NULL));
    m->data = (int *)malloc(MAX * sizeof(int));
    for (i = 0; i < MAX; i++) {
        m->data[i] = rand() % PRIME;
    }
    m->rows = m->cols = MAX;
}

void print_matrix(matrix *m) {
    int i, j;
    for (i = 0; i < m->rows; i++) {
        for (j = 0; j < m->cols; j++) {
            printf("%d ", m->data[i * m->cols + j]);
        }
        printf("\n");
    }
}

void multiply_matrices(matrix *a, matrix *b, matrix *c) {
    int i, j, k;
    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < b->cols; j++) {
            c->data[i * b->cols + j] = 0;
            for (k = 0; k < a->cols; k++) {
                c->data[i * b->cols + j] += a->data[i * a->cols + k] * b->data[k * b->cols + j];
            }
        }
    }
}

void main() {
    matrix a, b, c;
    generate_matrix(&a);
    generate_matrix(&b);
    printf("Matrix A:\n");
    print_matrix(&a);
    printf("Matrix B:\n");
    print_matrix(&b);
    multiply_matrices(&a, &b, &c);
    printf("Matrix C:\n");
    print_matrix(&c);
}