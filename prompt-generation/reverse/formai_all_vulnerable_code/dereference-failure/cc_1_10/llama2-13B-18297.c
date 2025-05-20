//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

// Matrix operations
void print_matrix(int (*matrix)[MAX_COLS]);
void add_matrices(int (*matrix1)[MAX_COLS], int (*matrix2)[MAX_COLS], int (*result)[MAX_COLS]);
void multiply_matrices(int (*matrix1)[MAX_COLS], int (*matrix2)[MAX_COLS], int (*result)[MAX_COLS]);

int main() {
    int (*matrix1)[MAX_COLS] = malloc(MAX_ROWS * sizeof(int));
    int (*matrix2)[MAX_COLS] = malloc(MAX_ROWS * sizeof(int));
    int (*result)[MAX_COLS] = malloc(MAX_ROWS * sizeof(int));

    // Initialize matrices
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            matrix1[i][j] = i * j;
            matrix2[i][j] = i * j + 1;
            result[i][j] = 0;
        }
    }

    // Perform matrix operations
    print_matrix(matrix1);
    print_matrix(matrix2);
    add_matrices(matrix1, matrix2, result);
    print_matrix(result);

    multiply_matrices(matrix1, matrix2, result);
    print_matrix(result);

    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}

// Print a matrix
void print_matrix(int (*matrix)[MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Add two matrices
void add_matrices(int (*matrix1)[MAX_COLS], int (*matrix2)[MAX_COLS], int (*result)[MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Multiply two matrices
void multiply_matrices(int (*matrix1)[MAX_COLS], int (*matrix2)[MAX_COLS], int (*result)[MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_ROWS; j++) {
            int sum = 0;
            for (int k = 0; k < MAX_COLS; k++) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = sum;
        }
    }
}