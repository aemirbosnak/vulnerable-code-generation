//FormAI DATASET v1.0 Category: Matrix operations ; Style: invasive
#include <stdio.h>

int main() {

    int n, m;
    printf("Enter the number of rows of the matrix: ");
    scanf("%d", &n);
    printf("Enter the number of columns of the matrix: ");
    scanf("%d", &m);

    int matrix[n][m], transpose[m][n];
    printf("Enter elements of the matrix:\n");

    // Reading the matrix from user input
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nThe Matrix is:\n");

    // Displaying the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Finding the transpose of the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    printf("\nThe Transpose of the Matrix is:\n");

    // Displaying the transpose of the matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    int sum = 0;

    // Finding the sum of diagonal elements of the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == j) {
                sum += matrix[i][j];
            }
        }
    }

    printf("\nThe Sum of Diagonal Elements of the Matrix is: %d\n", sum);

    int max_row_sum = 0, max_column_sum = 0;
    int row_sum, column_sum;

    // Finding the row with maximum sum
    for (int i = 0; i < n; i++) {
        row_sum = 0;
        for (int j = 0; j < m; j++) {
            row_sum += matrix[i][j];
        }
        if (row_sum > max_row_sum) {
            max_row_sum = row_sum;
        }
    }

    printf("\nThe Row with Maximum Sum is: %d\n", max_row_sum);

    // Finding the column with maximum sum
    for (int j = 0; j < m; j++) {
        column_sum = 0;
        for (int i = 0; i < n; i++) {
            column_sum += matrix[i][j];
        }
        if (column_sum > max_column_sum) {
            max_column_sum = column_sum;
        }
    }

    printf("\nThe Column with Maximum Sum is: %d\n", max_column_sum);
    
    return 0;
}