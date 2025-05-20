//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Matrix {
    int rows;
    int cols;
    int **data;
} Matrix;

Matrix *createMatrix(int rows, int cols) {
    Matrix *matrix = (Matrix *)malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = (int *)malloc(cols * sizeof(int));
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

Matrix *addMatrix(Matrix *a, Matrix *b) {
    if (a->rows != b->rows || a->cols != b->cols) {
        printf("Error: matrices must have the same dimensions to be added.\n");
        exit(1);
    }
    Matrix *c = createMatrix(a->rows, a->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            c->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
    return c;
}

Matrix *multiplyMatrix(Matrix *a, Matrix *b) {
    if (a->cols != b->rows) {
        printf("Error: number of columns in first matrix must equal number of rows in second matrix.\n");
        exit(1);
    }
    Matrix *c = createMatrix(a->rows, b->cols);
    for (int i = 0; i < c->rows; i++) {
        for (int j = 0; j < c->cols; j++) {
            c->data[i][j] = 0;
            for (int k = 0; k < a->cols; k++) {
                c->data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }
    return c;
}

int main() {
    // Initialize matrices A and B
    Matrix *A = createMatrix(2, 3);
    A->data[0][0] = 1;
    A->data[0][1] = 2;
    A->data[0][2] = 3;
    A->data[1][0] = 4;
    A->data[1][1] = 5;
    A->data[1][2] = 6;

    Matrix *B = createMatrix(3, 2);
    B->data[0][0] = 1;
    B->data[0][1] = 2;
    B->data[1][0] = 3;
    B->data[1][1] = 4;
    B->data[2][0] = 5;
    B->data[2][1] = 6;

    // Print the original matrices
    printf("Matrix A:\n");
    printMatrix(A);
    printf("Matrix B:\n");
    printMatrix(B);

    // Add the two matrices
    Matrix *C = addMatrix(A, B);

    // Print the result
    printf("Matrix A + Matrix B:\n");
    printMatrix(C);

    // Multiply the two matrices
    Matrix *D = multiplyMatrix(A, B);

    // Print the result
    printf("Matrix A * Matrix B:\n");
    printMatrix(D);

    // Free the allocated memory
    destroyMatrix(A);
    destroyMatrix(B);
    destroyMatrix(C);
    destroyMatrix(D);

    return 0;
}