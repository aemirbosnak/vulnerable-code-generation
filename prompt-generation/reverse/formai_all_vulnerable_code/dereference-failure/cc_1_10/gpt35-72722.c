//FormAI DATASET v1.0 Category: Matrix operations ; Style: genious
#include <stdio.h>

void printMatrix(int n, int m, int matrix[n][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int n, int m, int matrix1[n][m], int matrix2[n][m], int result[n][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtractMatrices(int n, int m, int matrix1[n][m], int matrix2[n][m], int result[n][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void multiplyMatrices(int n1, int m1, int matrix1[n1][m1], int n2, int m2, int matrix2[n2][m2], int result[n1][m2]) {
    if (m1 != n2) {
        printf("Error: number of columns in matrix 1 does not match number of rows in matrix 2\n");
        return;
    }

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < m1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int matrix1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    printf("Matrix 1:\n");
    printMatrix(3, 3, matrix1);

    printf("\nMatrix 2:\n");
    printMatrix(3, 3, matrix2);

    int sum[3][3];
    addMatrices(3, 3, matrix1, matrix2, sum);
    printf("\nMatrix 1 + Matrix 2:\n");
    printMatrix(3, 3, sum);

    int difference[3][3];
    subtractMatrices(3, 3, matrix1, matrix2, difference);
    printf("\nMatrix 1 - Matrix 2:\n");
    printMatrix(3, 3, difference);

    int product[3][3];
    multiplyMatrices(3, 3, matrix1, 3, 3, matrix2, product);
    printf("\nMatrix 1 * Matrix 2:\n");
    printMatrix(3, 3, product);

    return 0;
}