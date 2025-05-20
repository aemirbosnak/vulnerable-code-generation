//FormAI DATASET v1.0 Category: Matrix operations ; Style: lively
#include <stdio.h>

// function to print a matrix
void printMatrix(int m, int n, int matrix[m][n]) {
    printf("\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// function to add two matrices
void addMatrices(int m, int n, int matrix1[m][n], int matrix2[m][n], int result[m][n]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// function to multiply two matrices
void multiplyMatrices(int l, int m, int n, int matrix1[l][m], int matrix2[m][n], int result[l][n]) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
            for (int k = 0; k < m; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// main function
int main() {
    int matrix1[3][3] = {{1, 2, 3},
                         {4, 5, 6},
                         {7, 8, 9}};
    int matrix2[3][3] = {{9, 8, 7},
                         {6, 5, 4},
                         {3, 2, 1}};

    int result1[3][3];
    addMatrices(3, 3, matrix1, matrix2, result1);
    printf("Matrix Addition Example:\n");
    printf("Matrix 1:\n");
    printMatrix(3, 3, matrix1);
    printf("Matrix 2:\n");
    printMatrix(3, 3, matrix2);
    printf("Result:\n");
    printMatrix(3, 3, result1);

    int matrix3[3][2] = {{1, 2},
                         {3, 4},
                         {5, 6}};
    int matrix4[2][3] = {{7, 8, 9},
                         {4, 5, 6}};

    int result2[3][3];
    multiplyMatrices(3, 2, 3, matrix3, matrix4, result2);
    printf("Matrix Multiplication Example:\n");
    printf("Matrix 3:\n");
    printMatrix(3, 2, matrix3);
    printf("Matrix 4:\n");
    printMatrix(2, 3, matrix4);
    printf("Result:\n");
    printMatrix(3, 3, result2);

    return 0;
}