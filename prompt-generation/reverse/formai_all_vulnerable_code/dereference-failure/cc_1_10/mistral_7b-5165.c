//MISTRAL-7B DATASET v1.0 Category: Matrix operations ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

typedef struct Matrix {
    double data[ROWS][COLS];
} Matrix;

Matrix createMatrix(void);
void printMatrix(const Matrix *matrix);
Matrix multiplyMatrices(const Matrix *A, const Matrix *B);

int main() {
    srand(time(NULL));

    Matrix A = createMatrix();
    Matrix B = createMatrix();
    Matrix C = multiplyMatrices(&A, &B);

    printf("Matrix A:\n");
    printMatrix(&A);

    printf("\nMatrix B:\n");
    printMatrix(&B);

    printf("\nMatrix C (A * B):\n");
    printMatrix(&C);

    free(A.data);
    free(B.data);
    free(C.data);

    return 0;
}

Matrix createMatrix() {
    Matrix matrix;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            matrix.data[i][j] = (double) rand() / RAND_MAX;
        }
    }
    return matrix;
}

void printMatrix(const Matrix *matrix) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("%.2f ", matrix->data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

Matrix multiplyMatrices(const Matrix *A, const Matrix *B) {
    Matrix C;

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            C.data[i][j] = 0.0;
            for (int k = 0; k < COLS; ++k) {
                C.data[i][j] += A->data[i][k] * B->data[k][j];
            }
        }
    }

    return C;
}