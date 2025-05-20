//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Function to print a matrix
void print_matrix(int** matrix, int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to perform matrix addition
int** matrix_add(int** matrix1, int** matrix2, int rows1, int rows2, int cols) {
    int i, j;
    int** result = malloc(rows1 * sizeof(int*));

    for (i = 0; i < rows1; i++) {
        result[i] = malloc(cols * sizeof(int));
        for (j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return result;
}

// Function to perform matrix multiplication
int** matrix_multiply(int** matrix1, int** matrix2, int rows1, int rows2, int cols) {
    int i, j, k;
    int** result = malloc(rows1 * rows2 * sizeof(int*));

    for (i = 0; i < rows1; i++) {
        for (j = 0; j < rows2; j++) {
            for (k = 0; k < cols; k++) {
                int sum = 0;
                for (int l = 0; l < cols; l++) {
                    sum += matrix1[i][l] * matrix2[l][j];
                }
                result[i][j] = sum;
            }
        }
    }

    return result;
}

int main() {
    int rows1 = 3;
    int rows2 = 4;
    int cols = 2;

    int** matrix1 = malloc(rows1 * sizeof(int*));
    int** matrix2 = malloc(rows2 * sizeof(int*));
    int** result = NULL;

    for (int i = 0; i < rows1; i++) {
        matrix1[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            matrix1[i][j] = i * j;
        }
    }

    for (int i = 0; i < rows2; i++) {
        matrix2[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            matrix2[i][j] = i * j + 1;
        }
    }

    result = matrix_add(matrix1, matrix2, rows1, rows2, cols);
    print_matrix(result, rows1, cols);

    result = matrix_multiply(matrix1, matrix2, rows1, rows2, cols);
    print_matrix(result, rows1 * rows2, cols);

    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}