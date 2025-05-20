//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** initialize_matrix(int rows, int cols, int min, int max) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = min + rand() % (max - min + 1);
        }
    }
    return matrix;
}

void print_matrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int** multiply_matrices(int** A, int** B, int rowsA, int colsA, int rowsB, int colsB) {
    int** C = (int**)malloc(rowsA * sizeof(int*));
    for (int i = 0; i < rowsA; i++) {
        C[i] = (int*)malloc(colsB * sizeof(int));
        for (int j = 0; j < colsB; j++) {
            int sum = 0;
            for (int k = 0; k < colsA; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
    return C;
}

int main() {
    int rows = 3, cols = 3;
    srand(time(0));

    int** matrixA = initialize_matrix(rows, cols, 0, 9);
    print_matrix(matrixA, rows, cols);

    int** matrixB = initialize_matrix(rows, cols, 0, 9);
    print_matrix(matrixB, rows, cols);

    int** result = multiply_matrices(matrixA, matrixB, rows, cols, rows, cols);
    print_matrix(result, rows, cols);

    free(matrixA);
    free(matrixB);
    free(result);

    return 0;
}