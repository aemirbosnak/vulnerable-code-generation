//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define M 5
#define N 3

typedef struct {
    int rows, cols;
    int *data;
} CMatrix;

CMatrix *create_matrix(int rows, int cols) {
    CMatrix *mat = (CMatrix *)malloc(sizeof(CMatrix));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (int *)malloc(rows * cols * sizeof(int));
    return mat;
}

void print_matrix(CMatrix *mat) {
    int i, j;
    for (i = 0; i < mat->rows; i++) {
        for (j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i * mat->cols + j]);
        }
        printf("\n");
    }
}

void c_matrix_operations(CMatrix *a, CMatrix *b, CMatrix *c) {
    int i, j, k;
    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < a->cols; j++) {
            for (k = 0; k < b->rows; k++) {
                c->data[i * c->cols + j] += a->data[i * a->cols + j] * b->data[k * b->cols + j];
            }
        }
    }
}

int main() {
    srand(time(NULL));
    CMatrix *a = create_matrix(M, N);
    CMatrix *b = create_matrix(M, N);
    CMatrix *c = create_matrix(M, N);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            a->data[i * a->cols + j] = rand() % 10;
            b->data[i * b->cols + j] = rand() % 10;
        }
    }

    c_matrix_operations(a, b, c);

    print_matrix(c);

    return 0;
}