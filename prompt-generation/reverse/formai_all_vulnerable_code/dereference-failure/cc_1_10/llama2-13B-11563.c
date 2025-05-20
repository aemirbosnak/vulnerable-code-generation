//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 5 // number of columns in the matrices
#define M 6 // number of rows in the matrices

// define a structure for matrices
typedef struct {
    int rows;
    int cols;
    int *data;
} Matrix;

// function to create a matrix
Matrix *create_matrix(int rows, int cols) {
    Matrix *m = (Matrix *)malloc(sizeof(Matrix));
    m->rows = rows;
    m->cols = cols;
    m->data = (int *)malloc(sizeof(int) * rows * cols);
    return m;
}

// function to destroy a matrix
void destroy_matrix(Matrix *m) {
    free(m->data);
    free(m);
}

// function to perform matrix multiplication
Matrix *matrix_multiply(Matrix *a, Matrix *b) {
    int i, j, k;
    Matrix *c = create_matrix(a->rows, b->cols);

    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < b->cols; j++) {
            int sum = 0;
            for (k = 0; k < a->cols; k++) {
                sum += a->data[i * a->cols + k] * b->data[k * b->cols + j];
            }
            c->data[i * c->cols + j] = sum;
        }
    }

    return c;
}

// function to perform matrix addition
Matrix *matrix_add(Matrix *a, Matrix *b) {
    int i, j;
    Matrix *c = create_matrix(a->rows, b->cols);

    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < b->cols; j++) {
            c->data[i * c->cols + j] = a->data[i * a->cols + j] + b->data[i * b->cols + j];
        }
    }

    return c;
}

int main() {
    Matrix *a = create_matrix(N, M);
    Matrix *b = create_matrix(N, M);
    Matrix *c;

    // initialize the matrices
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a->data[i * a->cols + j] = i * j;
            b->data[i * b->cols + j] = i * j + 1;
        }
    }

    // perform matrix multiplication
    c = matrix_multiply(a, b);

    // print the result
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", c->data[i * c->cols + j]);
        }
        printf("\n");
    }

    // perform matrix addition
    c = matrix_add(a, b);

    // print the result
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", c->data[i * c->cols + j]);
        }
        printf("\n");
    }

    destroy_matrix(a);
    destroy_matrix(b);
    destroy_matrix(c);

    return 0;
}