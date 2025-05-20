//FormAI DATASET v1.0 Category: Matrix operations ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

void generate_matrix(int **mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mat[i][j] = rand() % 100;
        }
    }
}

void print_matrix(int **mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void scalar_multiplication(int **mat, int rows, int cols, int scalar) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mat[i][j] *= scalar;
        }
    }
}

void matrix_addition(int **mat1, int **mat2, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mat1[i][j] += mat2[i][j];
        }
    }
}

int main() {
    int rows = 3;
    int cols = 3;

    int **mat1 = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat1[i] = (int *)malloc(cols * sizeof(int));
    }
    generate_matrix(mat1, rows, cols);
    printf("Matrix 1:\n");
    print_matrix(mat1, rows, cols);
    printf("\n");

    int **mat2 = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat2[i] = (int *)malloc(cols * sizeof(int));
    }
    generate_matrix(mat2, rows, cols);
    printf("Matrix 2:\n");
    print_matrix(mat2, rows, cols);
    printf("\n");

    printf("Scalar multiplication of Matrix 1 by 2:\n");
    scalar_multiplication(mat1, rows, cols, 2);
    print_matrix(mat1, rows, cols);
    printf("\n");

    printf("Adding Matrix 2 to Matrix 1:\n");
    matrix_addition(mat1, mat2, rows, cols);
    print_matrix(mat1, rows, cols);
    printf("\n");

    for (int i = 0; i < rows; i++) {
        free(mat1[i]);
    }
    free(mat1);

    for (int i = 0; i < rows; i++) {
        free(mat2[i]);
    }
    free(mat2);

    return 0;
}