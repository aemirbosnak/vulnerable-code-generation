//FormAI DATASET v1.0 Category: Matrix operations ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Function to display the matrix in proper format
void display(int **matrix, int row, int col) {
    printf("Matrix:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void add(int **a, int **b, int **result, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Function to multiply two matrices
void multiply(int **a, int **b, int **result, int rowA, int colA, int colB) {
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colA; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// Main function
int main() {
    printf("Mr. Watson, I see that you are interested in matrix operations. Let us get to work!\n");

    int rowA, colA, rowB, colB;
    printf("Enter the dimensions of the first matrix (row column): ");
    scanf("%d %d", &rowA, &colA);

    printf("Enter the dimensions of the second matrix (row column): ");
    scanf("%d %d", &rowB, &colB);

    if (colA != rowB) {
        printf("Sorry Mr. Watson, the two matrices are not compatible for multiplication.");
        return 0;
    }

    int **a = (int **)malloc(rowA * sizeof(int *));
    for (int i = 0; i < rowA; i++) {
        a[i] = (int *)malloc(colA * sizeof(int));
    }

    int **b = (int **)malloc(rowB * sizeof(int *));
    for (int i = 0; i < rowB; i++) {
        b[i] = (int *)malloc(colB * sizeof(int));
    }

    int **c = (int **)malloc(rowA * sizeof(int *));
    for (int i = 0; i < rowA; i++) {
        c[i] = (int *)malloc(colB * sizeof(int));
    }

    printf("Enter elements of the first matrix:\n");
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colA; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter elements of the second matrix:\n");
    for (int i = 0; i < rowB; i++) {
        for (int j = 0; j < colB; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    display(a, rowA, colA);
    printf("\n");
    display(b, rowB, colB);
    printf("\n");

    add(a, b, c, rowA, colA);
    printf("Addition:\n");
    display(c, rowA, colA);
    printf("\n");

    multiply(a, b, c, rowA, colA, colB);
    printf("Multiplication:\n");
    display(c, rowA, colB);

    printf("\nThat's it Mr. Watson. The job is done!\n");

    return 0;
}