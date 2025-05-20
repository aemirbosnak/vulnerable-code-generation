//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define a matrix structure
typedef struct Matrix {
    int rows;
    int cols;
    double **data;
} Matrix;

// Function to create a matrix
Matrix *createMatrix(int rows, int cols) {
    Matrix *matrix = (Matrix *)malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = (double *)malloc(cols * sizeof(double));
    }
    return matrix;
}

// Function to print a matrix
void printMatrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%lf ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
Matrix *addMatrices(Matrix *a, Matrix *b) {
    int rows = a->rows;
    int cols = a->cols;
    Matrix *c = createMatrix(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            c->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }

    return c;
}

int main() {
    Matrix *a = createMatrix(2, 3);
    a->data[0][0] = 10;
    a->data[0][1] = 20;
    a->data[0][2] = 30;
    a->data[1][0] = 40;
    a->data[1][1] = 50;
    a->data[1][2] = 60;

    Matrix *b = createMatrix(2, 3);
    b->data[0][0] = 15;
    b->data[0][1] = 25;
    b->data[0][2] = 35;
    b->data[1][0] = 45;
    b->data[1][1] = 55;
    b->data[1][2] = 65;

    Matrix *c = addMatrices(a, b);

    printMatrix(c);

    return 0;
}