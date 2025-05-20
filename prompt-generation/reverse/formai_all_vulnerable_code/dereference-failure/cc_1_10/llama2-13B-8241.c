//LLAMA2-13B DATASET v1.0 Category: Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define N 1000
#define M 100
#define K 10

struct Complex {
    double real;
    double imag;
};

struct Matrix {
    int rows;
    int cols;
    double **data;
};

struct Vector {
    int size;
    double *data;
};

void init_matrix(struct Matrix *m, int r, int c) {
    m->rows = r;
    m->cols = c;
    m->data = (double **) malloc(r * sizeof(double *));
    for (int i = 0; i < r; i++) {
        m->data[i] = (double *) malloc(c * sizeof(double));
        for (int j = 0; j < c; j++) {
            m->data[i][j] = rand() % 10 - 5;
        }
    }
}

void init_vector(struct Vector *v, int size) {
    v->size = size;
    v->data = (double *) malloc(size * sizeof(double));
    for (int i = 0; i < size; i++) {
        v->data[i] = rand() % 10 - 5;
    }
}

void add_matrices(struct Matrix *a, struct Matrix *b, struct Matrix *c) {
    c->rows = a->rows;
    c->cols = b->cols;
    c->data = (double **) malloc(c->rows * sizeof(double *));
    for (int i = 0; i < c->rows; i++) {
        c->data[i] = (double *) malloc(c->cols * sizeof(double));
        for (int j = 0; j < c->cols; j++) {
            c->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
}

void multiply_matrices(struct Matrix *a, struct Matrix *b, struct Matrix *c) {
    c->rows = a->cols;
    c->cols = b->rows;
    c->data = (double **) malloc(c->rows * sizeof(double *));
    for (int i = 0; i < c->rows; i++) {
        c->data[i] = (double *) malloc(c->cols * sizeof(double));
        for (int j = 0; j < c->cols; j++) {
            double sum = 0;
            for (int k = 0; k < a->cols; k++) {
                sum += a->data[i][k] * b->data[k][j];
            }
            c->data[i][j] = sum;
        }
    }
}

void print_matrix(struct Matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%.2f ", m->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    struct Matrix a, b, c;
    struct Vector v;

    init_matrix(&a, 3, 3);
    init_matrix(&b, 3, 3);
    init_vector(&v, 10);

    for (int i = 0; i < 10; i++) {
        add_matrices(&a, &b, &c);
        multiply_matrices(&c, &v, &v);
        print_matrix(&v);

        // Add some randomness to the matrices
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                a.data[j][k] = rand() % 10 - 5;
                b.data[j][k] = rand() % 10 - 5;
            }
        }
    }

    return 0;
}