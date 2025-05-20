//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

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
    int i, j, k;
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols1; j++) {
            for (k = 0; k < rows2; k++) {
                matrix1[i][j] += matrix2[k][j];
            }
        }
    }
}

void multiply_matrices(int **matrix1, int rows1, int cols1, int **matrix2, int rows2, int cols2) {
    int i, j, k;
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols1; j++) {
            int sum = 0;
            for (k = 0; k < rows2; k++) {
                sum += matrix1[i][j] * matrix2[k][j];
            }
            matrix1[i][j] = sum;
        }
    }
}

void transpose_matrix(int **matrix, int rows, int cols) {
    int i, j, k;
    int temp[rows][cols];
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            temp[i][j] = matrix[j][i];
        }
    }
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix[i][j] = temp[i][j];
        }
    }
}

int main() {
    int rows1 = 3, cols1 = 3, rows2 = 2, cols2 = 2;
    int **matrix1 = (int **)malloc(rows1 * sizeof(int *));
    int **matrix2 = (int **)malloc(rows2 * sizeof(int *));

    // Initialize matrices
    for (int i = 0; i < rows1; i++) {
        matrix1[i] = (int *)malloc(cols1 * sizeof(int));
        for (int j = 0; j < cols1; j++) {
            matrix1[i][j] = i * j;
        }
    }

    for (int i = 0; i < rows2; i++) {
        matrix2[i] = (int *)malloc(cols2 * sizeof(int));
        for (int j = 0; j < cols2; j++) {
            matrix2[i][j] = i * j;
        }
    }

    // Perform matrix operations
    add_matrices(matrix1, rows1, cols1, matrix2, rows2, cols2);
    multiply_matrices(matrix1, rows1, cols1, matrix2, rows2, cols2);
    transpose_matrix(matrix1, rows1, cols1);

    // Print matrices
    print_matrix(matrix1, rows1, cols1);
    print_matrix(matrix2, rows2, cols2);

    return 0;
}