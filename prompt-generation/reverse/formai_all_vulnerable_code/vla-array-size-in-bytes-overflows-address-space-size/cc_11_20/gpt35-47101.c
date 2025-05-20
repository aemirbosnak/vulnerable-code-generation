//FormAI DATASET v1.0 Category: Matrix operations ; Style: mathematical
#include <stdio.h>

int main() {
    printf("\n\t---- Matrix Operations in C ----\n");
    int row1, col1, row2, col2, i, j, k;

    printf("\nEnter the number of rows for Matrix 1: ");
    scanf("%d", &row1);
    printf("Enter the number of columns for Matrix 1: ");
    scanf("%d", &col1);

    printf("Enter the number of rows for Matrix 2: ");
    scanf("%d", &row2);
    printf("Enter the number of columns for Matrix 2: ");
    scanf("%d", &col2);

    // matrix dimensions must be valid for multiplication
    if (col1 != row2) {
        printf("\nError: Invalid Matrix Dimensions.\n");
        return 0;
    }

    int mat1[row1][col1], mat2[row2][col2], result[row1][col2];

    // take Matrix 1 input from user
    printf("\nEnter the values for Matrix 1:\n");
    for (i = 0; i < row1; i++) {
        for (j = 0; j < col1; j++) {
            printf("Enter value for mat1[%d][%d]: ", i, j);
            scanf("%d", &mat1[i][j]);
        }
    }

    // take Matrix 2 input from user
    printf("\nEnter the values for Matrix 2:\n");
    for (i = 0; i < row2; i++) {
        for (j = 0; j < col2; j++) {
            printf("Enter value for mat2[%d][%d]: ", i, j);
            scanf("%d", &mat2[i][j]);
        }
    }

    // perform matrix multiplication operation
    for (i = 0; i < row1; i++) {
        for (j = 0; j < col2; j++) {
            result[i][j] = 0;
            for (k = 0; k < col1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    // print Matrix 1
    printf("\nMatrix 1:\n");
    for (i = 0; i < row1; i++) {
        for (j = 0; j < col1; j++) {
            printf("%d ", mat1[i][j]);
        }
        printf("\n");
    }

    // print Matrix 2
    printf("\nMatrix 2:\n");
    for (i = 0; i < row2; i++) {
        for (j = 0; j < col2; j++) {
            printf("%d ", mat2[i][j]);
        }
        printf("\n");
    }

    // print the result of matrix multiplication
    printf("\nResult of Matrix Multiplication:\n");
    for (i = 0; i < row1; i++) {
        for (j = 0; j < col2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}