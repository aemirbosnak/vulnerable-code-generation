//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 5
#define MAX_COLS 5

typedef struct Matrix {
    int **data;
    int rows;
    int cols;
} Matrix;

Matrix* createMatrix(int r, int c) {
    Matrix* m = (Matrix*)malloc(sizeof(Matrix));
    m->rows = r;
    m->cols = c;
    m->data = (int**)malloc(r * sizeof(int*) + c * sizeof(int));
    for (int i = 0; i < r; i++) {
        m->data[i] = (int*)malloc(c * sizeof(int));
    }
    return m;
}

void printMatrix(Matrix* m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%d ", m->data[i][j]);
        }
        printf("\n");
    }
}

Matrix* addMatrices(Matrix* a, Matrix* b) {
    int r = a->rows;
    int c = a->cols;
    Matrix* cMatrix = createMatrix(r, c);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cMatrix->data[i][j] = 0;
            for (int k = 0; k < b->rows; k++) {
                for (int l = 0; l < b->cols; l++) {
                    cMatrix->data[i][j] += a->data[k][l] * b->data[k][l];
                }
            }
        }
    }

    return cMatrix;
}

int main() {
    Matrix* a = createMatrix(2, 3);
    a->data[0][0] = 1;
    a->data[0][1] = 2;
    a->data[0][2] = 3;
    a->data[1][0] = 4;
    a->data[1][1] = 5;
    a->data[1][2] = 6;

    Matrix* b = createMatrix(2, 3);
    b->data[0][0] = 7;
    b->data[0][1] = 8;
    b->data[0][2] = 9;
    b->data[1][0] = 10;
    b->data[1][1] = 11;
    b->data[1][2] = 12;

    Matrix* c = addMatrices(a, b);

    printMatrix(c);

    return 0;
}