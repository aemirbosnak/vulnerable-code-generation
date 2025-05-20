//LLAMA2-13B DATASET v1.0 Category: Benchmarking ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define N 100000
#define M 1000
#define K 10

struct complex {
    double real;
    double imag;
};

struct matrix {
    int rows;
    int cols;
    struct complex **elements;
};

void init_matrix(struct matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            struct complex c;
            c.real = i * j;
            c.imag = i * j * M_PI / 180;
            m->elements[i][j] = c;
        }
    }
}

void add_matrix(struct matrix *a, struct matrix *b) {
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            struct complex sum;
            sum.real = a->elements[i][j].real + b->elements[i][j].real;
            sum.imag = a->elements[i][j].imag + b->elements[i][j].imag;
            a->elements[i][j] = sum;
        }
    }
}

void mul_matrix(struct matrix *a, struct matrix *b) {
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            struct complex product;
            for (int k = 0; k < a->cols; k++) {
                product.real += a->elements[i][k].real * b->elements[k][j].real -
                             a->elements[i][k].imag * b->elements[k][j].imag;
                product.imag += a->elements[i][k].real * b->elements[k][j].imag +
                             a->elements[i][k].imag * b->elements[k][j].real;
            }
            a->elements[i][j] = product;
        }
    }
}

int main() {
    struct matrix a, b, c;
    init_matrix(&a);
    init_matrix(&b);
    init_matrix(&c);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            struct complex temp;
            temp.real = rand() / (double)RAND_MAX;
            temp.imag = rand() / (double)RAND_MAX;
            a.elements[i][j] = temp;
        }
    }

    for (int i = 0; i < K; i++) {
        mul_matrix(&a, &b);
        add_matrix(&a, &c);
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%.2f + %.2fi", c.elements[i][j].real, c.elements[i][j].imag);
            printf(" ");
        }
        printf("\n");
    }

    return 0;
}