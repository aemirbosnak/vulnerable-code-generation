//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: satisfied
#include <stdio.h>

// Function to multiply two matrices
int** matrix_multiply(int** matrix1, int** matrix2, int rows1, int cols1, int rows2, int cols2) {
    int** result = (int**)malloc(rows1 * sizeof(int*));
    for (int i = 0; i < rows1; i++) {
        result[i] = (int*)malloc(cols2 * sizeof(int));
        for (int j = 0; j < cols2; j++) {
            int sum = 0;
            for (int k = 0; k < cols1; k++) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = sum;
        }
    }
    return result;
}

// Function to print a matrix
void print_matrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows1 = 2;
    int cols1 = 3;
    int rows2 = 3;
    int cols2 = 2;

    // Create first matrix
    int** matrix1 = (int**)malloc(rows1 * sizeof(int*));
    for (int i = 0; i < rows1; i++) {
        matrix1[i] = (int*)malloc(cols1 * sizeof(int));
        for (int j = 0; j < cols1; j++) {
            matrix1[i][j] = i * cols1 + j;
        }
    }

    // Create second matrix
    int** matrix2 = (int**)malloc(rows2 * sizeof(int*));
    for (int i = 0; i < rows2; i++) {
        matrix2[i] = (int*)malloc(cols2 * sizeof(int));
        for (int j = 0; j < cols2; j++) {
            matrix2[i][j] = i * cols2 + j;
        }
    }

    // Multiply matrices
    int** result = matrix_multiply(matrix1, matrix2, rows1, cols1, rows2, cols2);

    // Print result
    print_matrix(result, rows1, cols2);

    // Free memory
    for (int i = 0; i < rows1; i++) {
        free(matrix1[i]);
    }
    free(matrix1);

    for (int i = 0; i < rows2; i++) {
        free(matrix2[i]);
    }
    free(matrix2);

    return 0;
}