//FormAI DATASET v1.0 Category: Matrix operations ; Style: accurate
#include <stdio.h>

/* This program performs operations on matrices */

int main() {

    int row, column, i, j;

    // Get user inputs for row and column size of the matrices
    printf("Enter number of rows: ");
    scanf("%d", &row);
    printf("Enter number of columns: ");
    scanf("%d", &column);

    int matrix1[row][column], matrix2[row][column], sum[row][column], difference[row][column], product[row][column];
    
    // Initialize matrix1
    printf("\nEnter elements of matrix 1:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Initialize matrix2
    printf("\nEnter elements of matrix 2:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Sum of matrices
    printf("\nSum of the matrices:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
            printf("%d\t", sum[i][j]);
        }
        printf("\n");
    }

    // Difference of matrices
    printf("\nDifference of the matrices:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            difference[i][j] = matrix1[i][j] - matrix2[i][j];
            printf("%d\t", difference[i][j]);
        }
        printf("\n");
    }

    // Product of matrices
    printf("\nProduct of the matrices:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            product[i][j] = 0;
            for (int k = 0; k < column; k++) {
                product[i][j] += matrix1[i][k] * matrix2[k][j];
            }
            printf("%d\t", product[i][j]);
        }
        printf("\n");
    }

    return 0;
}