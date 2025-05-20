//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int generate_matrix(int rows, int cols, int matrix[rows][cols]) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
    return 0;
}

int multiply_matrices(int rows1, int cols1, int rows2, int cols2, int matrix1[rows1][cols1], int matrix2[rows2][cols2], int result[rows1][cols2]) {
    int i, j, k;
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return 0;
}

int main() {
    int rows1, cols1, rows2, cols2, i, j;
    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    if (cols1!= rows2) {
        printf("Matrix multiplication not possible.\n");
        return 1;
    }

    int matrix1[rows1][cols1], matrix2[rows2][cols2], result[rows1][cols2];

    generate_matrix(rows1, cols1, matrix1);
    generate_matrix(rows2, cols2, matrix2);

    multiply_matrices(rows1, cols1, rows2, cols2, matrix1, matrix2, result);

    printf("Result of matrix multiplication:\n");
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}