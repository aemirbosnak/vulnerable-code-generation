//LLAMA2-13B DATASET v1.0 Category: Benchmarking ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <assert.h>

#define N 1000000
#define M 1000
#define K 10

struct complex {
    double real;
    double imag;
};

struct matrix {
    int rows;
    int cols;
    struct complex **data;
};

void init_matrix(struct matrix *m, int r, int c) {
    m->rows = r;
    m->cols = c;
    m->data = malloc(r * sizeof(struct complex *) * c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            m->data[i][j] = (struct complex) {0, 0};
        }
    }
}

void free_matrix(struct matrix *m) {
    free(m->data);
}

void add_matrix(struct matrix *a, struct matrix *b) {
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            a->data[i][j].real += b->data[i][j].real;
            a->data[i][j].imag += b->data[i][j].imag;
        }
    }
}

void mult_matrix(struct matrix *a, struct matrix *b) {
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            struct complex c = {0, 0};
            for (int k = 0; k < a->cols; k++) {
                c.real += a->data[i][k].real * b->data[k][j].real - a->data[i][k].imag * b->data[k][j].imag;
                c.imag += a->data[i][k].real * b->data[k][j].imag + a->data[i][k].imag * b->data[k][j].real;
            }
            a->data[i][j] = c;
        }
    }
}

void print_matrix(struct matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%.2f + %.2fi ", m->data[i][j].real, m->data[i][j].imag);
        }
        printf("\n");
    }
}

int main() {
    struct matrix A, B, C;
    init_matrix(&A, N, N);
    init_matrix(&B, N, M);
    init_matrix(&C, N, K);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            A.data[i][j].real = (double)i / (double)N;
            A.data[i][j].imag = (double)j / (double)M;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            C.data[i][j].real = (double)i / (double)N;
            C.data[i][j].imag = (double)j / (double)K;
        }
    }

    add_matrix(&A, &B);
    mult_matrix(&A, &C);
    print_matrix(&C);

    free_matrix(&A);
    free_matrix(&B);
    free_matrix(&C);

    return 0;
}