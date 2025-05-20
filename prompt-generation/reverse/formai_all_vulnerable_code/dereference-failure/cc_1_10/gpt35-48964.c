//FormAI DATASET v1.0 Category: Matrix operations ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void matrix_multiplication(int **result, int **matrix1, int **matrix2, int i, int j, int k, int len1, int len2, int len3) {
    if (i == len1)
        return;
    if (j == len3) {
        matrix_multiplication(result, matrix1, matrix2, i+1, 0, 0, len1, len2, len3);
        return;
    }
    if (k == len2) {
        matrix_multiplication(result, matrix1, matrix2, i, j+1, 0, len1, len2, len3);
        return;
    }
    result[i][j] += matrix1[i][k] * matrix2[k][j];
    matrix_multiplication(result, matrix1, matrix2, i, j, k+1, len1, len2, len3);
}

void print_matrix(int **matrix, int len1, int len2) {
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int len1 = 3;
    int len2 = 3;
    int len3 = 3;

    int **matrix1 = (int **)malloc(len1 * sizeof(int *));
    int **matrix2 = (int **)malloc(len2 * sizeof(int *));
    int **result = (int **)malloc(len1 * sizeof(int *));
    for (int i = 0; i < len1; i++) {
        matrix1[i] = (int *)malloc(len2 * sizeof(int));
        result[i] = (int *)calloc(len3, sizeof(int));
    }
    for (int i = 0; i < len2; i++) {
        matrix2[i] = (int *)malloc(len3 * sizeof(int));
    }

    matrix1[0][0] = 1;
    matrix1[0][1] = 2;
    matrix1[0][2] = 3;
    matrix1[1][0] = 4;
    matrix1[1][1] = 5;
    matrix1[1][2] = 6;
    matrix1[2][0] = 7;
    matrix1[2][1] = 8;
    matrix1[2][2] = 9;

    matrix2[0][0] = 1;
    matrix2[0][1] = 2;
    matrix2[0][2] = 3;
    matrix2[1][0] = 4;
    matrix2[1][1] = 5;
    matrix2[1][2] = 6;
    matrix2[2][0] = 7;
    matrix2[2][1] = 8;
    matrix2[2][2] = 9;

    matrix_multiplication(result, matrix1, matrix2, 0, 0, 0, len1, len2, len3);
    print_matrix(result, len1, len3);

    for (int i = 0; i < len1; i++) {
        free(matrix1[i]);
        free(result[i]);
    }
    for (int i = 0; i < len2; i++) {
        free(matrix2[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}