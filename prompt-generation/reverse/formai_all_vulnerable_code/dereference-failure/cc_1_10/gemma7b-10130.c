//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define the Matrix structure
typedef struct Matrix {
    int rows;
    int cols;
    double **data;
} Matrix;

// Function to create a Matrix
Matrix *createMatrix(int rows, int cols) {
    Matrix *matrix = malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (double**)malloc(rows * sizeof(double *));
    for (int i = 0; i < matrix->rows; i++) {
        matrix->data[i] = (double*)malloc(cols * sizeof(double));
    }
    return matrix;
}

// Function to add two Matrices
Matrix *addMatrices(Matrix *a, Matrix *b) {
    int rows = a->rows;
    int cols = a->cols;
    Matrix *c = createMatrix(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            double sum = 0.0;
            for (int k = 0; k < a->rows; k++) {
                for (int l = 0; l < a->cols; l++) {
                    sum += a->data[k][l] * b->data[k][l];
                }
            }
            c->data[i][j] = sum;
        }
    }
    return c;
}

int main() {
    // Create two Matrices
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

    // Add the two Matrices
    Matrix *c = addMatrices(a, b);

    // Print the result
    for (int i = 0; i < c->rows; i++) {
        for (int j = 0; j < c->cols; j++) {
            printf("%f ", c->data[i][j]);
        }
        printf("\n");
    }

    return 0;
}