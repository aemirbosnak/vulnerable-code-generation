//FormAI DATASET v1.0 Category: Matrix operations ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

void printMatrix(int **mat, int m, int n) {
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int **mat1, int **mat2, int **result, int m, int n) {
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void subtractMatrices(int **mat1, int **mat2, int **result, int m, int n) {
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

int main() {
    int m, n;
    printf("Enter the number of rows and columns of the matrices: ");
    scanf("%d %d", &m, &n);

    // Allocate memory for matrices
    int **mat1 = (int **)malloc(m * sizeof(int *));
    int **mat2 = (int **)malloc(m * sizeof(int *));
    int **sum = (int **)malloc(m * sizeof(int *));
    int **difference = (int **)malloc(m * sizeof(int *));
    for (int i=0; i<m; i++) {
        mat1[i] = (int *)malloc(n * sizeof(int));
        mat2[i] = (int *)malloc(n * sizeof(int));
        sum[i] = (int *)malloc(n * sizeof(int));
        difference[i] = (int *)malloc(n * sizeof(int));
    }

    // Populate matrices
    printf("Enter the elements of the first matrix:\n");
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("Enter the elements of the second matrix:\n");
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    // Add and subtract matrices
    addMatrices(mat1, mat2, sum, m, n);
    subtractMatrices(mat1, mat2, difference, m, n);

    // Print matrices and results
    printf("First matrix:\n");
    printMatrix(mat1, m, n);
    printf("Second matrix:\n");
    printMatrix(mat2, m, n);
    printf("Sum of matrices:\n");
    printMatrix(sum, m, n);
    printf("Difference of matrices:\n");
    printMatrix(difference, m, n);

    // Free memory
    for (int i=0; i<m; i++) {
        free(mat1[i]);
        free(mat2[i]);
        free(sum[i]);
        free(difference[i]);
    }
    free(mat1);
    free(mat2);
    free(sum);
    free(difference);

    return 0;
}