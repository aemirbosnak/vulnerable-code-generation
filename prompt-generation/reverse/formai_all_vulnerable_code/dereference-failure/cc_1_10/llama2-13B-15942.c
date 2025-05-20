//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Function to print a matrix
void print_matrix(int **matrix, int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to perform matrix multiplication
int** matrix_multiply(int **a, int **b, int rows_a, int cols_a, int rows_b, int cols_b) {
    int i, j, k;
    int **c;

    // Allocate memory for the result matrix
    c = (int**)malloc(rows_a * sizeof(int*));
    for (i = 0; i < rows_a; i++) {
        c[i] = (int*)malloc(cols_b * sizeof(int));
    }

    // Perform matrix multiplication
    for (i = 0; i < rows_a; i++) {
        for (j = 0; j < cols_b; j++) {
            int sum = 0;
            for (k = 0; k < cols_a; k++) {
                sum += a[i][k] * b[k][j];
            }
            c[i][j] = sum;
        }
    }

    return c;
}

int main() {
    int rows_a = 3, cols_a = 2, rows_b = 2, cols_b = 3;
    int **a, **b, **c;

    // Initialize the matrices
    a = (int**)malloc(rows_a * sizeof(int*));
    for (int i = 0; i < rows_a; i++) {
        a[i] = (int*)malloc(cols_a * sizeof(int));
        for (int j = 0; j < cols_a; j++) {
            a[i][j] = i * j;
        }
    }

    b = (int**)malloc(rows_b * sizeof(int*));
    for (int i = 0; i < rows_b; i++) {
        b[i] = (int*)malloc(cols_b * sizeof(int));
        for (int j = 0; j < cols_b; j++) {
            b[i][j] = i * j + 1;
        }
    }

    // Perform matrix multiplication
    c = matrix_multiply(a, b, rows_a, cols_a, rows_b, cols_b);

    // Print the result matrix
    print_matrix(c, rows_a, cols_b);

    // Free the memory
    for (int i = 0; i < rows_a; i++) {
        free(c[i]);
    }
    free(c);

    return 0;
}