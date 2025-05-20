//FormAI DATASET v1.0 Category: Matrix operations ; Style: careful
#include <stdio.h>

void matrix_addition(int rows, int cols, int mat1[rows][cols], int mat2[rows][cols]) {
    printf("\nAddition of matrices:\n\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%d ", mat1[i][j] + mat2[i][j]);
        }
        printf("\n");
    }
}

void matrix_multiplication(int rows1, int cols1, int rows2, int cols2, int mat1[rows1][cols1], int mat2[rows2][cols2]) {
    int prod_mat[rows1][cols2];
    for(int i=0; i<rows1; i++) {
        for(int j=0; j<cols2; j++) {
            prod_mat[i][j] = 0;
            for(int k=0; k<cols1; k++) {
                prod_mat[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    printf("\nMultiplication of matrices:\n\n");
    for(int i=0; i<rows1; i++) {
        for(int j=0; j<cols2; j++) {
            printf("%d ", prod_mat[i][j]);
        }
        printf("\n");
    }
}

void matrix_transpose(int rows, int cols, int mat[rows][cols]) {
    printf("\nTranspose of matrix:\n\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%d ", mat[j][i]);
        }
        printf("\n");
    }
}

int main() {
    int mat1[2][2] = {{1, 2}, {3, 4}};
    int mat2[2][2] = {{5, 6}, {7, 8}};

    printf("Matrix 1:\n");
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            printf("%d ", mat1[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix 2:\n");
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            printf("%d ", mat2[i][j]);
        }
        printf("\n");
    }

    matrix_addition(2, 2, mat1, mat2);
    matrix_multiplication(2, 2, 2, 2, mat1, mat2);
    matrix_transpose(2, 2, mat1);

    return 0;
}