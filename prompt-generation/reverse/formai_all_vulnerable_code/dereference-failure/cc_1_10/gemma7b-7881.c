//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 4

typedef struct Matrix {
    int **data;
    int rows;
    int cols;
} Matrix;

Matrix *createMatrix(int r, int c) {
    Matrix *m = (Matrix *)malloc(sizeof(Matrix));
    m->rows = r;
    m->cols = c;
    m->data = (int **)malloc(sizeof(int *) * r);
    for (int i = 0; i < r; i++) {
        m->data[i] = (int *)malloc(sizeof(int) * c);
    }
    return m;
}

void printMatrix(Matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%d ", m->data[i][j]);
        }
        printf("\n");
    }
}

Matrix *addMatrices(Matrix *a, Matrix *b) {
    Matrix *c = createMatrix(a->rows, a->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            c->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
    return c;
}

int main() {
    Matrix *a = createMatrix(ROWS, COLS);
    a->data[0][0] = 1;
    a->data[0][1] = 2;
    a->data[0][2] = 3;
    a->data[0][3] = 4;
    a->data[1][0] = 5;
    a->data[1][1] = 6;
    a->data[1][2] = 7;
    a->data[1][3] = 8;
    a->data[2][0] = 9;
    a->data[2][1] = 10;
    a->data[2][2] = 11;
    a->data[2][3] = 12;

    Matrix *b = createMatrix(ROWS, COLS);
    b->data[0][0] = 3;
    b->data[0][1] = 4;
    b->data[0][2] = 5;
    b->data[0][3] = 6;
    b->data[1][0] = 7;
    b->data[1][1] = 8;
    b->data[1][2] = 9;
    b->data[1][3] = 10;
    b->data[2][0] = 11;
    b->data[2][1] = 12;
    b->data[2][2] = 13;
    b->data[2][3] = 14;

    Matrix *c = addMatrices(a, b);

    printMatrix(c);

    return 0;
}