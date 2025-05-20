//FormAI DATASET v1.0 Category: Matrix operations ; Style: intelligent
#include <stdio.h>

void add_matrices(int row, int col, int matrix1[row][col], int matrix2[row][col]) {
    int result[row][col];
    printf("\n***Addition of Matrices***\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

void multiply_matrices(int row1, int col1, int row2, int col2, int matrix1[row1][col1], int matrix2[row2][col2]) {
    if (col1 != row2) {
        printf("\n***Error: Matrices cannot be multiplied due to incompatible sizes***\n");
        return;
    }
    printf("\n***Multiplication of Matrices***\n");
    int result[row1][col2];
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < col1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

void transpose_matrix(int row, int col, int matrix[row][col]) {
    printf("\n***Transpose of Matrix***\n");
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            printf("%d ", matrix[j][i]);
        }
        printf("\n");
    }
}

int main() {
    int row1, col1, row2, col2;

    printf("Enter the dimensions of matrix 1 (row col): ");
    scanf("%d %d", &row1, &col1);

    int matrix1[row1][col1];
    printf("\nEnter the elements of matrix 1:\n");
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("\nEnter the dimensions of matrix 2 (row col): ");
    scanf("%d %d", &row2, &col2);

    int matrix2[row2][col2];
    printf("\nEnter the elements of matrix 2:\n");
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Perform addition of matrices
    add_matrices(row1, col1, matrix1, matrix2);

    // Perform multiplication of matrices
    multiply_matrices(row1, col1, row2, col2, matrix1, matrix2);

    // Perform transpose of matrix 1
    transpose_matrix(row1, col1, matrix1);

    return 0;
}