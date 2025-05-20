//FormAI DATASET v1.0 Category: Matrix operations ; Style: portable
#include <stdio.h>
#include <stdlib.h>

void print_matrix(int **matrix, int rows, int cols);
void add_matrices(int **matrix1, int **matrix2, int rows, int cols, int **result);
void scalar_multiply(int **matrix, int rows, int cols, int scalar);
void transpose(int **matrix, int rows, int cols, int **result);

int main(void) {
    int rows1, cols1, rows2, cols2;

    printf("Enter the number of rows and columns for matrix 1: ");
    scanf("%d %d", &rows1, &cols1);

    printf("Enter the number of rows and columns for matrix 2: ");
    scanf("%d %d", &rows2, &cols2);

    if (rows1 != rows2 || cols1 != cols2) {
        printf("Matrix dimensions do not match.\n");
        exit(1);
    }

    int **matrix1 = malloc(rows1 * sizeof(int *));
    int **matrix2 = malloc(rows2 * sizeof(int *));
    int **result = malloc(rows1 * sizeof(int *));

    for (int i = 0; i < rows1; i++) {
        matrix1[i] = malloc(cols1 * sizeof(int));
        matrix2[i] = malloc(cols2 * sizeof(int));
        result[i] = malloc(cols1 * sizeof(int));
    }

    printf("Enter the values for matrix 1:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter the values for matrix 2:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    printf("\nMatrix 1:\n");
    print_matrix(matrix1, rows1, cols1);

    printf("\nMatrix 2:\n");
    print_matrix(matrix2, rows2, cols2);

    printf("\nAdding matrices...\n");
    add_matrices(matrix1, matrix2, rows1, cols1, result);

    printf("\nResult:\n");
    print_matrix(result, rows1, cols1);

    printf("\nMultiplying matrix 1 by scalar 5...\n");
    scalar_multiply(matrix1, rows1, cols1, 5);

    printf("\nMatrix 1 after scalar multiplication:\n");
    print_matrix(matrix1, rows1, cols1);

    printf("\nTransposing matrix 2...\n");
    int **transposed = malloc(cols2 * sizeof(int *));
    for (int i = 0; i < cols2; i++) {
        transposed[i] = malloc(rows2 * sizeof(int));
    }
    transpose(matrix2, rows2, cols2, transposed);

    printf("\nTranspose of matrix 2:\n");
    print_matrix(transposed, cols2, rows2);

    for (int i = 0; i < rows1; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    for (int i = 0; i < cols2; i++) {
        free(transposed[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);
    free(transposed);

    return 0;
}

void print_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void add_matrices(int **matrix1, int **matrix2, int rows, int cols, int **result) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void scalar_multiply(int **matrix, int rows, int cols, int scalar) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] *= scalar;
        }
    }
}

void transpose(int **matrix, int rows, int cols, int **result) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}