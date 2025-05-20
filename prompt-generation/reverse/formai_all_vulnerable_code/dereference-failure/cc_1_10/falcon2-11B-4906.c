//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Matrix dimensions
#define ROWS 3
#define COLS 3

// Function to create a new matrix
int **create_matrix(int **mat, int rows, int cols) {
    int i, j;

    // Allocate memory for the matrix
    mat = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        mat[i] = (int *)malloc(cols * sizeof(int));
    }

    // Initialize all elements of the matrix to 0
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            mat[i][j] = 0;
        }
    }

    return mat;
}

// Function to perform matrix multiplication using recursion
int **matrix_multiply(int **a, int **b, int rows, int cols) {
    int i, j, k;

    // Allocate memory for the resulting matrix
    int **c = create_matrix(NULL, rows, cols);

    // Perform the multiplication
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            int sum = 0;
            for (k = 0; k < rows; k++) {
                sum += a[i][k] * b[k][j];
            }
            c[i][j] = sum;
        }
    }

    return c;
}

int main() {
    int i, j, k;

    // Create matrices A and B
    int **A = create_matrix(NULL, ROWS, COLS);
    int **B = create_matrix(NULL, ROWS, COLS);
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            A[i][j] = (i + j) % 10;
            B[i][j] = (i + j) % 10;
        }
    }

    // Multiply matrices A and B
    int **C = matrix_multiply(A, B, ROWS, COLS);

    // Print the resulting matrix
    printf("Matrix C:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}