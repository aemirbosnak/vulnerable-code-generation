//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int rows;
    int cols;
    int **data;
} Matrix;

Matrix *createMatrix(int rows, int cols) {
    Matrix *m = malloc(sizeof(Matrix));
    m->rows = rows;
    m->cols = cols;
    m->data = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        m->data[i] = malloc(cols * sizeof(int));
    }
    return m;
}

void destroyMatrix(Matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        free(m->data[i]);
    }
    free(m->data);
    free(m);
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

Matrix *subtractMatrices(Matrix *a, Matrix *b) {
    if (a->rows != b->rows || a->cols != b->cols) {
        return NULL;
    }
    Matrix *c = createMatrix(a->rows, a->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            c->data[i][j] = a->data[i][j] - b->data[i][j];
        }
    }
    return c;
}

Matrix *multiplyMatrices(Matrix *a, Matrix *b) {
    if (a->cols != b->rows) {
        return NULL;
    }
    Matrix *c = createMatrix(a->rows, b->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            c->data[i][j] = 0;
            for (int k = 0; k < a->cols; k++) {
                c->data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }
    return c;
}

int main() {
    Matrix *a = createMatrix(2, 2);
    a->data[0][0] = 1;
    a->data[0][1] = 2;
    a->data[1][0] = 3;
    a->data[1][1] = 4;

    Matrix *b = createMatrix(2, 2);
    b->data[0][0] = 5;
    b->data[0][1] = 6;
    b->data[1][0] = 7;
    b->data[1][1] = 8;

    Matrix *c = addMatrices(a, b);
    printMatrix(c);

    c = subtractMatrices(a, b);
    printMatrix(c);

    c = multiplyMatrices(a, b);
    printMatrix(c);

    destroyMatrix(a);
    destroyMatrix(b);
    destroyMatrix(c);

    return 0;
}