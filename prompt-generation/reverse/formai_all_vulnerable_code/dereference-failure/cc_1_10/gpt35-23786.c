//FormAI DATASET v1.0 Category: Matrix operations ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

void print_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int** matrix_multiplication(int **matrix_a, int **matrix_b, int rows_a, int cols_a, int cols_b) {
    int **result_matrix = malloc(rows_a * sizeof(int *));

    for (int i = 0; i < rows_a; i++) {
        result_matrix[i] = malloc(cols_b * sizeof(int));
    }

    for (int i = 0; i < rows_a; i++) {
        for (int j = 0; j < cols_b; j++) {
            result_matrix[i][j] = 0;
            for (int k = 0; k < cols_a; k++) {
                result_matrix[i][j] += matrix_a[i][k] * matrix_b[k][j];
            }
        }
    }

    return result_matrix;
}

int main() {
    int rows_a = 3, cols_a = 2;
    int **matrix_a = malloc(rows_a * sizeof(int *));

    for (int i = 0; i < rows_a; i++) {
        matrix_a[i] = malloc(cols_a * sizeof(int));
    }

    printf("Enter matrix A (%d x %d):\n", rows_a, cols_a);
    for (int i = 0; i < rows_a; i++) {
        for (int j = 0; j < cols_a; j++) {
            scanf("%d", &matrix_a[i][j]);
        }
    }

    int rows_b = 2, cols_b = 4;
    int **matrix_b = malloc(rows_b * sizeof(int *));

    for (int i = 0; i < rows_b; i++) {
        matrix_b[i] = malloc(cols_b * sizeof(int));
    }

    printf("Enter matrix B (%d x %d):\n", rows_b, cols_b);
    for (int i = 0; i < rows_b; i++) {
        for (int j = 0; j < cols_b; j++) {
            scanf("%d", &matrix_b[i][j]);
        }
    }

    int **result_matrix = matrix_multiplication(matrix_a, matrix_b, rows_a, cols_a, cols_b);

    printf("Result:\n");
    print_matrix(result_matrix, rows_a, cols_b);

    // Free allocated memory
    for (int i = 0; i < rows_a; i++) {
        free(matrix_a[i]);
    }
    free(matrix_a);

    for (int i = 0; i < rows_b; i++) {
        free(matrix_b[i]);
    }
    free(matrix_b);

    for (int i = 0; i < rows_a; i++) {
        free(result_matrix[i]);
    }
    free(result_matrix);

    return 0;
}