//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Matrix operations
void print_matrix(int **matrix, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void add_matrices(int **matrix1, int rows1, int cols1, int **matrix2, int rows2, int cols2) {
    int i, j;
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            matrix1[i][j] += matrix2[i][j];
        }
    }
}

void multiply_matrices(int **matrix1, int rows1, int cols1, int **matrix2, int rows2, int cols2) {
    int i, j, k;
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            int sum = 0;
            for (k = 0; k < cols1; k++) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            matrix1[i][j] = sum;
        }
    }
}

int main() {
    int rows1 = 3, cols1 = 4, rows2 = 4, cols2 = 3;
    int **matrix1 = malloc(rows1 * sizeof(int *));
    int **matrix2 = malloc(rows2 * sizeof(int *));

    for (int i = 0; i < rows1; i++) {
        matrix1[i] = malloc(cols1 * sizeof(int));
        for (int j = 0; j < cols1; j++) {
            matrix1[i][j] = i * j;
        }
    }

    for (int i = 0; i < rows2; i++) {
        matrix2[i] = malloc(cols2 * sizeof(int));
        for (int j = 0; j < cols2; j++) {
            matrix2[i][j] = i * j + 1;
        }
    }

    // Add matrices
    add_matrices(matrix1, rows1, cols1, matrix2, rows2, cols2);

    // Print result
    print_matrix(matrix1, rows1, cols1);

    // Multiply matrices
    multiply_matrices(matrix1, rows1, cols1, matrix2, rows2, cols2);

    // Print result
    print_matrix(matrix1, rows1, cols1);

    return 0;
}