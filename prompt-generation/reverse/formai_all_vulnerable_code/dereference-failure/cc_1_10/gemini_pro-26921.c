//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int rows;
    int cols;
    int **data;
} Matrix;

Matrix *createMatrix(int rows, int cols) {
    Matrix *matrix = malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = malloc(sizeof(int) * cols);
    }
    return matrix;
}

void destroyMatrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}

void printMatrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

Matrix *addMatrices(Matrix *a, Matrix *b) {
    if (a->rows != b->rows || a->cols != b->cols) {
        printf("Error: matrices must have the same dimensions\n");
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
        printf("Error: matrices must have the same dimensions\n");
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
        printf("Error: number of columns in matrix A must match number of rows in matrix B\n");
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
    // Romeo and Juliet matrices
    Matrix *romeo = createMatrix(4, 3);
    romeo->data[0][0] = 1;
    romeo->data[0][1] = 2;
    romeo->data[0][2] = 3;
    romeo->data[1][0] = 4;
    romeo->data[1][1] = 5;
    romeo->data[1][2] = 6;
    romeo->data[2][0] = 7;
    romeo->data[2][1] = 8;
    romeo->data[2][2] = 9;
    romeo->data[3][0] = 10;
    romeo->data[3][1] = 11;
    romeo->data[3][2] = 12;

    Matrix *juliet = createMatrix(3, 4);
    juliet->data[0][0] = 13;
    juliet->data[0][1] = 14;
    juliet->data[0][2] = 15;
    juliet->data[0][3] = 16;
    juliet->data[1][0] = 17;
    juliet->data[1][1] = 18;
    juliet->data[1][2] = 19;
    juliet->data[1][3] = 20;
    juliet->data[2][0] = 21;
    juliet->data[2][1] = 22;
    juliet->data[2][2] = 23;
    juliet->data[2][3] = 24;

    // Add the matrices
    Matrix *love = addMatrices(romeo, juliet);
    printf("Romeo + Juliet:\n");
    printMatrix(love);

    // Subtract the matrices
    Matrix *hate = subtractMatrices(romeo, juliet);
    printf("Romeo - Juliet:\n");
    printMatrix(hate);

    // Multiply the matrices
    Matrix *children = multiplyMatrices(romeo, juliet);
    printf("Romeo * Juliet:\n");
    printMatrix(children);

    // Destroy the matrices
    destroyMatrix(romeo);
    destroyMatrix(juliet);
    destroyMatrix(love);
    destroyMatrix(hate);
    destroyMatrix(children);

    return 0;
}