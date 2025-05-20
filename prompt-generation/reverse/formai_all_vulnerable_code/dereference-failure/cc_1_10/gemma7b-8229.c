//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1024

typedef struct Matrix {
    int rows, cols;
    double **data;
} Matrix;

Matrix *createMatrix(int r, int c) {
    Matrix *m = malloc(sizeof(Matrix));
    m->rows = r;
    m->cols = c;
    m->data = malloc(r * c * sizeof(double));
    return m;
}

void printMatrix(Matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%f ", m->data[i][j]);
        }
        printf("\n");
    }
}

Matrix *addMatrix(Matrix *a, Matrix *b) {
    if (a->rows != b->rows || a->cols != b->cols) {
        return NULL;
    }
    Matrix *c = createMatrix(a->rows, a->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            c->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
    return c;
}

int main() {
    Matrix *a = createMatrix(2, 2);
    a->data[0][0] = 1.0;
    a->data[0][1] = 2.0;
    a->data[1][0] = 3.0;
    a->data[1][1] = 4.0;

    Matrix *b = createMatrix(2, 2);
    b->data[0][0] = 5.0;
    b->data[0][1] = 6.0;
    b->data[1][0] = 7.0;
    b->data[1][1] = 8.0;

    Matrix *c = addMatrix(a, b);

    printMatrix(c);

    return 0;
}