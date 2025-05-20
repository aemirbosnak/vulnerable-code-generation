//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void fillMatrix(int **mat, int rows, int cols, int r, int c);
void printMatrix(int **mat, int rows, int cols);
void addMatrices(int **mat1, int **mat2, int **result, int rows, int cols, int r, int c);
void multiplyMatrices(int **mat1, int **mat2, int **result, int rows1, int cols1, int cols2, int r, int c);

int main() {
    int rows1, cols1, rows2, cols2;

    // Input dimensions for first matrix
    printf("Enter number of rows and columns for first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    
    // Input dimensions for second matrix
    printf("Enter number of rows and columns for second matrix: ");
    scanf("%d %d", &rows2, &cols2);
    
    // Check if matrices can be added/multiplied
    if (cols1 != cols2) {
        printf("Matrix addition is not possible, columns of first must match rows of second.\n");
        return 1;
    }
    
    // Allocate memory for matrices
    int **mat1 = (int **)malloc(rows1 * sizeof(int *));
    int **mat2 = (int **)malloc(rows2 * sizeof(int *));
    int **resultAdd = (int **)malloc(rows1 * sizeof(int *));
    int **resultMul = (int **)malloc(rows1 * sizeof(int *));

    for (int i = 0; i < rows1; i++) {
        mat1[i] = (int *)malloc(cols1 * sizeof(int));
        resultAdd[i] = (int *)malloc(cols1 * sizeof(int));
        resultMul[i] = (int *)malloc(cols2 * sizeof(int));
    }
    for (int i = 0; i < rows2; i++) {
        mat2[i] = (int *)malloc(cols2 * sizeof(int));
    }

    // Fill matrices
    printf("\nFill the first matrix:\n");
    fillMatrix(mat1, rows1, cols1, 0, 0);
    
    printf("\nFill the second matrix:\n");
    fillMatrix(mat2, rows2, cols2, 0, 0);

    // Matrix addition
    addMatrices(mat1, mat2, resultAdd, rows1, cols1, 0, 0);
    printf("\nResult of matrix addition:\n");
    printMatrix(resultAdd, rows1, cols1);

    // Matrix multiplication
    if (cols1 == rows2) {
        multiplyMatrices(mat1, mat2, resultMul, rows1, cols1, cols2, 0, 0);
        printf("\nResult of matrix multiplication:\n");
        printMatrix(resultMul, rows1, cols2);
    } else {
        printf("Matrix multiplication is not possible, columns of first must match rows of second.\n");
    }

    // Free allocated memory
    for (int i = 0; i < rows1; i++) {
        free(mat1[i]);
        free(resultAdd[i]);
        free(resultMul[i]);
    }
    for (int i = 0; i < rows2; i++) {
        free(mat2[i]);
    }
    free(mat1);
    free(mat2);
    free(resultAdd);
    free(resultMul);

    return 0;
}

void fillMatrix(int **mat, int rows, int cols, int r, int c) {
    if (r >= rows) return;
    if (c >= cols) {
        fillMatrix(mat, rows, cols, r + 1, 0);
        return;
    }
    printf("Element [%d][%d]: ", r, c);
    scanf("%d", &mat[r][c]);
    fillMatrix(mat, rows, cols, r, c + 1);
}

void printMatrix(int **mat, int rows, int cols) {
    if (rows <= 0) return;
    for (int i = 0; i < cols; i++) {
        printf("%d ", mat[0][i]);
    }
    printf("\n");
    printMatrix(mat + 1, rows - 1, cols);
}

void addMatrices(int **mat1, int **mat2, int **result, int rows, int cols, int r, int c) {
    if (r >= rows) return;
    if (c >= cols) {
        addMatrices(mat1, mat2, result, rows, cols, r + 1, 0);
        return;
    }
    result[r][c] = mat1[r][c] + mat2[r][c];
    addMatrices(mat1, mat2, result, rows, cols, r, c + 1);
}

void multiplyMatrices(int **mat1, int **mat2, int **result, int rows1, int cols1, int cols2, int r, int c) {
    if (r >= rows1) return;
    if (c >= cols2) {
        multiplyMatrices(mat1, mat2, result, rows1, cols1, cols2, r + 1, 0);
        return;
    }
    result[r][c] = 0;
    for (int k = 0; k < cols1; k++) {
        result[r][c] += mat1[r][k] * mat2[k][c];
    }
    multiplyMatrices(mat1, mat2, result, rows1, cols1, cols2, r, c + 1);
}