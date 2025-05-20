//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Initialize the matrix with random values
void initialize_matrix(int rows, int cols, int matrix[rows][cols]) {
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100; // Values between 0 and 99
        }
    }
}

// Print the matrix
void print_matrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Add two matrices
void add_matrices(int rows, int cols, int A[rows][cols], int B[rows][cols], int C[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Multiply two matrices
void multiply_matrices(int rowsA, int colsA, int rowsB, int colsB, int A[rowsA][colsA], int B[rowsB][colsB], int C[rowsA][colsB]) {
    if (colsA != rowsB) {
        printf("Matrix multiplication not possible.\n");
        return;
    }
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            C[i][j] = 0; // Initialize C[i][j]
            for (int k = 0; k < colsA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Transpose of a matrix
void transpose_matrix(int rows, int cols, int A[rows][cols], int B[cols][rows]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            B[j][i] = A[i][j];
        }
    }
}

// Main function holding the puzzle of matrix operations
int main() {
    const int ROWS_A = 3, COLS_A = 3, ROWS_B = 3, COLS_B = 3;
    int A[ROWS_A][COLS_A], B[ROWS_B][COLS_B], C[ROWS_A][COLS_B], D[COLS_A][ROWS_A];

    // Step 1: Initialize matrices A and B
    initialize_matrix(ROWS_A, COLS_A, A);
    initialize_matrix(ROWS_B, COLS_B, B);

    // Step 2: Print the original matrices
    printf("Matrix A:\n");
    print_matrix(ROWS_A, COLS_A, A);

    printf("\nMatrix B:\n");
    print_matrix(ROWS_B, COLS_B, B);

    // Step 3: Add matrices A and B
    int E[ROWS_A][COLS_A]; // For addition matrix
    add_matrices(ROWS_A, COLS_A, A, B, E);
    printf("\nMatrix A + B:\n");
    print_matrix(ROWS_A, COLS_A, E);

    // Step 4: Multiply matrices A and B
    multiply_matrices(ROWS_A, COLS_A, ROWS_B, COLS_B, A, B, C);
    printf("\nMatrix A * B:\n");
    print_matrix(ROWS_A, COLS_B, C);

    // Step 5: Transpose matrix A
    transpose_matrix(ROWS_A, COLS_A, A, D);
    printf("\nTranspose of Matrix A:\n");
    print_matrix(COLS_A, ROWS_A, D);

    // Breathing new life into the operations
    printf("\nPuzzles continue with different dimensions!\n");
    const int ROWS_C = 2, COLS_C = 3;
    int F[ROWS_C][COLS_C];
    initialize_matrix(ROWS_C, COLS_C, F);

    printf("Matrix F (2x3):\n");
    print_matrix(ROWS_C, COLS_C, F);

    // Infinite possibilities with different operations
    printf("\nCalculating dimensions with F: A * F?\n");
    int G[ROWS_A][COLS_C];
    multiply_matrices(ROWS_A, COLS_A, ROWS_C, COLS_C, A, F, G);
    printf("\nResult of A * F:\n");
    print_matrix(ROWS_A, COLS_C, G);

    return 0;
}