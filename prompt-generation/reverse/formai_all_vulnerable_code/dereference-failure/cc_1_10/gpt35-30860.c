//FormAI DATASET v1.0 Category: Matrix operations ; Style: brave
#include <stdio.h>

// function to print a matrix
void printMatrix(int A[][3], int rows, int cols) {
    printf("[");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", A[i][j]);
        }
        if (i != rows - 1) {
            printf("\n ");
        }
    }
    printf("]\n");
}

// function to add two matrices
void addMatrix(int A[][3], int B[][3], int C[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// function to subtract two matrices
void subtractMatrix(int A[][3], int B[][3], int C[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// function to multiply two matrices
void multiplyMatrix(int A[][3], int B[][3], int C[][3], int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int B[2][3] = {
        {7, 8, 9},
        {10, 11, 12}
    };

    int C[2][3];

    printf("Matrix A:\n");
    printMatrix(A, 2, 3);

    printf("Matrix B:\n");
    printMatrix(B, 2, 3);

    // add matrices
    addMatrix(A, B, C, 2, 3);
    printf("Matrix A + B:\n");
    printMatrix(C, 2, 3);

    // subtract matrices
    subtractMatrix(A, B, C, 2, 3);
    printf("Matrix A - B:\n");
    printMatrix(C, 2, 3);

    int D[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int E[4][2] = {
        {13, 14},
        {15, 16},
        {17, 18},
        {19, 20}
    };

    int F[3][2];

    printf("Matrix D:\n");
    printMatrix(D, 3, 4);

    printf("Matrix E:\n");
    printMatrix(E, 4, 2);

    // multiply matrices
    multiplyMatrix(D, E, F, 3, 4, 2);
    printf("Matrix D * E:\n");
    printMatrix(F, 3, 2);

    return 0;
}