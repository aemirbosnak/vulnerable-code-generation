//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 4

typedef struct {
    int rows;
    int cols;
    int *data;
} mat;

mat *new_mat(int r, int c) {
    mat *m = malloc(sizeof(mat));
    m->rows = r;
    m->cols = c;
    m->data = malloc(r * c * sizeof(int));
    return m;
}

void mat_print(mat *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%d ", m->data[i * m->cols + j]);
        }
        printf("\n");
    }
}

void mat_add(mat *a, mat *b) {
    int i, j, k;
    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < a->cols; j++) {
            a->data[i * a->cols + j] += b->data[i * b->cols + j];
        }
    }
}

void mat_sub(mat *a, mat *b) {
    int i, j, k;
    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < a->cols; j++) {
            a->data[i * a->cols + j] -= b->data[i * b->cols + j];
        }
    }
}

void mat_mul(mat *a, mat *b) {
    int i, j, k;
    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < b->cols; j++) {
            int sum = 0;
            for (k = 0; k < a->cols; k++) {
                sum += a->data[i * a->cols + k] * b->data[k * b->cols + j];
            }
            a->data[i * a->cols + j] = sum;
        }
    }
}

int main() {
    mat *a, *b, *c;

    a = new_mat(N, N);
    b = new_mat(N, N);
    c = new_mat(N, N);

    // Initialize matrices
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a->data[i * a->cols + j] = i * j;
            b->data[i * b->cols + j] = i * (j + 1);
            c->data[i * c->cols + j] = 0;
        }
    }

    // Perform matrix operations
    mat_add(a, b);
    mat_sub(a, b);
    mat_mul(a, b);

    // Print results
    mat_print(a);
    mat_print(b);
    mat_print(c);

    return 0;
}