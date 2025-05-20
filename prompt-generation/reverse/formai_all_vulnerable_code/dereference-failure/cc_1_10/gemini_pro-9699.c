//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix {
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
    // Create two matrices
    Matrix *a = createMatrix(2, 3);
    Matrix *b = createMatrix(3, 2);

    // Initialize the matrices
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            a->data[i][j] = rand() % 10;
        }
    }
    for (int i = 0; i < b->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            b->data[i][j] = rand() % 10;
        }
    }

    // Print the matrices
    printf("Matrix A:\n");
    printMatrix(a);
    printf("\nMatrix B:\n");
    printMatrix(b);

    // Add the matrices
    Matrix *c = addMatrices(a, b);
    if (c) {
        printf("\nMatrix A + Matrix B:\n");
        printMatrix(c);
        destroyMatrix(c);
    } else {
        printf("\nMatrices cannot be added.\n");
    }

    // Multiply the matrices
    Matrix *d = multiplyMatrices(a, b);
    if (d) {
        printf("\nMatrix A * Matrix B:\n");
        printMatrix(d);
        destroyMatrix(d);
    } else {
        printf("Matrices cannot be multiplied.\n");
    }

    // Destroy the matrices
    destroyMatrix(a);
    destroyMatrix(b);

    return 0;
}