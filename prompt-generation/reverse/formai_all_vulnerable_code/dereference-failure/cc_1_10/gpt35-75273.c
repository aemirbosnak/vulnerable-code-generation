//FormAI DATASET v1.0 Category: Matrix operations ; Style: retro
/* Retro-style C Matrix Operations Example Program */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 0 and 9
int rand_num() {
    return rand() % 10;
}

// Function to print a matrix
void print_matrix(int **matrix, int rows, int cols) {
    printf("\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to multiply two matrices
int **multiply_matrices(int **matrix1, int **matrix2, int rows1, int cols1, int cols2) {
    int **result = (int **)malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++) {
        result[i] = (int *)malloc(cols2 * sizeof(int));
    }

    // Initialize result matrix with zeroes
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
        }
    }

    // Multiply matrices
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Create and initialize matrices
    int rows1 = 3, cols1 = 2, rows2 = 2, cols2 = 4;
    int **matrix1 = (int **)malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++) {
        matrix1[i] = (int *)malloc(cols1 * sizeof(int));
        for (int j = 0; j < cols1; j++) {
            matrix1[i][j] = rand_num();
        }
    }

    int **matrix2 = (int **)malloc(rows2 * sizeof(int *));
    for (int i = 0; i < rows2; i++) {
        matrix2[i] = (int *)malloc(cols2 * sizeof(int));
        for (int j = 0; j < cols2; j++) {
            matrix2[i][j] = rand_num();
        }
    }

    // Print matrices
    printf("Matrix 1:\n");
    print_matrix(matrix1, rows1, cols1);
    printf("Matrix 2:\n");
    print_matrix(matrix2, rows2, cols2);

    // Multiply matrices and print result
    int **result = multiply_matrices(matrix1, matrix2, rows1, cols1, cols2);
    printf("Result:\n");
    print_matrix(result, rows1, cols2);

    // Free memory
    for (int i = 0; i < rows1; i++) {
        free(matrix1[i]);
        free(result[i]);
    }
    for (int i = 0; i < rows2; i++) {
        free(matrix2[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}