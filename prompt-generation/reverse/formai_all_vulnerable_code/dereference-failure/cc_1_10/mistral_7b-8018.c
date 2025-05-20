//MISTRAL-7B DATASET v1.0 Category: Matrix operations ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define ROWS 2
#define COLS 2

void printMatrix(float mat[][COLS], char* name) {
    printf("\n%s:\n", name);
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j)
            printf(" %0.2f ", mat[i][j]);
        printf("\n");
    }
}

float** inputMatrix(char* name, int rows, int cols) {
    float** mat;
    mat = (float**)calloc(rows, sizeof(float*));
    for (int i = 0; i < rows; ++i) {
        mat[i] = (float*)calloc(cols, sizeof(float));
        for (int j = 0; j < cols; ++j) {
            printf("Enter element %s[%d][%d]: ", name, i, j);
            scanf("%f", &mat[i][j]);
        }
    }
    return mat;
}

float** multiplyMatrices(float** mat1, float** mat2) {
    float** result;
    result = (float**)calloc(ROWS, sizeof(float*));

    for (int i = 0; i < ROWS; ++i) {
        result[i] = (float*)calloc(COLS, sizeof(float));
        for (int j = 0; j < COLS; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < COLS; ++k)
                result[i][j] += mat1[i][k] * mat2[k][j];
        }
    }
    return result;
}

void freeMatrix(float** mat, int rows) {
    for (int i = 0; i < rows; ++i)
        free(mat[i]);
    free(mat);
}

int main() {
    float** A, **B, **C;

    A = inputMatrix("Matrix A", ROWS, COLS);
    B = inputMatrix("Matrix B", ROWS, COLS);

    printMatrix(A, "Matrix A");
    printMatrix(B, "Matrix B");

    C = multiplyMatrices(A, B);

    printMatrix(C, "Product of Matrices A and B");

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            A[i][j] += C[i][j];
            B[i][j] -= C[i][j];
        }
    }

    printMatrix(A, "Matrix A + Product and Matrix B - Product");

    freeMatrix(A, ROWS);
    freeMatrix(B, ROWS);
    freeMatrix(C, ROWS);

    return 0;
}