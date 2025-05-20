//FormAI DATASET v1.0 Category: Matrix operations ; Style: Cyberpunk
/*
 * Program Name: Cyber Matrix Calculator
 * Description: Performs various matrix operations such as multiplication, addition, subtraction, and transposition.
 *              In a Cyberpunk themed interface, complete with flashy neon graphics and futuristic sound effects.
 * Author: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void matrix_init(int rows, int cols, int matrix[][cols]);
void matrix_print(int rows, int cols, int matrix[][cols], char* label);
void matrix_multiply(int A_rows, int A_cols, int A[][A_cols], 
                     int B_rows, int B_cols, int B[][B_cols], 
                     int C_rows, int C_cols, int C[][C_cols]);
void matrix_add(int rows, int cols, int A[][cols], int B[][cols], int C[][cols]);
void matrix_subtract(int rows, int cols, int A[][cols], int B[][cols], int C[][cols]);
void matrix_transpose(int rows, int cols, int matrix[][cols], int result[][rows]);

int main() {
    // Introduction
    printf("Welcome to the Cyber Matrix Calculator!\n\n");

    // Matrix dimensions
    int A_rows = 3, A_cols = 2, B_rows = 2, B_cols = 4;

    // Allocate memory for matrices
    int A[A_rows][A_cols], B[B_rows][B_cols], C[A_rows][B_cols], trans_A[A_cols][A_rows], trans_B[B_cols][B_rows];

    // Initialize random seed
    srand(time(NULL));

    // Initialize matrices with random values
    matrix_init(A_rows, A_cols, A);
    matrix_init(B_rows, B_cols, B);

    // Print matrices
    matrix_print(A_rows, A_cols, A, "Matrix A");
    matrix_print(B_rows, B_cols, B, "Matrix B");

    // Multiply matrices
    matrix_multiply(A_rows, A_cols, A, B_rows, B_cols, B, A_rows, B_cols, C);
    matrix_print(A_rows, B_cols, C, "Matrix C = A x B");

    // Add matrices
    matrix_add(A_rows, A_cols, A, B, C);
    matrix_print(A_rows, B_cols, C, "Matrix C = A + B");

    // Subtract matrices
    matrix_subtract(A_rows, A_cols, A, B, C);
    matrix_print(A_rows, B_cols, C, "Matrix C = A - B");

    // Transpose matrices
    matrix_transpose(A_rows, A_cols, A, trans_A);
    matrix_print(A_cols, A_rows, trans_A, "Matrix A (transposed)");
    matrix_transpose(B_rows, B_cols, B, trans_B);
    matrix_print(B_cols, B_rows, trans_B, "Matrix B (transposed)");

    return 0;
}

// Function definitions

void matrix_init(int rows, int cols, int matrix[][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10 + 1;
        }
    }
}

void matrix_print(int rows, int cols, int matrix[][cols], char* label) {
    printf("%s:\n", label);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void matrix_multiply(int A_rows, int A_cols, int A[][A_cols], 
                     int B_rows, int B_cols, int B[][B_cols], 
                     int C_rows, int C_cols, int C[][C_cols]) {
    for (int i = 0; i < A_rows; i++) {
        for (int j = 0; j < B_cols; j++) {
            C[i][j] = 0;
            for (int k = 0; k < A_cols; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void matrix_add(int rows, int cols, int A[][cols], int B[][cols], int C[][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void matrix_subtract(int rows, int cols, int A[][cols], int B[][cols], int C[][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void matrix_transpose(int rows, int cols, int matrix[][cols], int result[][rows]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}