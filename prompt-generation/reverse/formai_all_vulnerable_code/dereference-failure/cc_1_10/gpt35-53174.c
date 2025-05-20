//FormAI DATASET v1.0 Category: Matrix operations ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function to print matrix A
void printMatrix(int **A, int row, int col) {
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

// Function to create a matrix of given rows and columns
int** createMatrix(int row, int col) {
    int **A = (int **)malloc(row * sizeof(int *));
    for(int i=0; i<row; i++) {
        A[i] = (int *)malloc(col * sizeof(int));
    }
    return A;
}

// Function to free dynamically allocated matrix
void freeMatrix(int **A, int row, int col) {
    for(int i=0; i<row; i++) {
        free(A[i]);
    }
    free(A);
}

// Function to multiply two matrices
int** multiplyMatrix(int **A, int **B, int rowA, int colA, int rowB, int colB) {
    if(colA != rowB) {
        printf("Error: Matrices cannot be multiplied.\n");
        exit(0);
    }
    int **C = createMatrix(rowA, colB);
    for(int i=0; i<rowA; i++) {
        for(int j=0; j<colB; j++) {
            C[i][j] = 0;
            for(int k=0; k<colA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

int main() {
    int rowA = 3, colA = 2;
    int rowB = 2, colB = 4;
    
    // Initialize matrix A
    int **A = createMatrix(rowA, colA);
    A[0][0] = 1; A[0][1] = 2;
    A[1][0] = 3; A[1][1] = 4;
    A[2][0] = 5; A[2][1] = 6;

    // Initialize matrix B
    int **B = createMatrix(rowB, colB);
    B[0][0] = 7; B[0][1] = 8; B[0][2] = 9; B[0][3] = 10;
    B[1][0] = 11; B[1][1] = 12; B[1][2] = 13; B[1][3] = 14;

    // Multiply matrix A and B
    int **C = multiplyMatrix(A, B, rowA, colA, rowB, colB);

    // Print matrices
    printf("Matrix A:\n");
    printMatrix(A, rowA, colA);

    printf("\nMatrix B:\n");
    printMatrix(B, rowB, colB);

    printf("\nMatrix C = A x B:\n");
    printMatrix(C, rowA, colB);

    // Free matrices
    freeMatrix(A, rowA, colA);
    freeMatrix(B, rowB, colB);
    freeMatrix(C, rowA, colB);

    return 0;
}