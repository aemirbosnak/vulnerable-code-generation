//FormAI DATASET v1.0 Category: Matrix operations ; Style: interoperable
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

void add_matrices(int **matrix1, int **matrix2, int **result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtract_matrices(int **matrix1, int **matrix2, int **result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

int main() {
    int rows, cols;
    printf("Enter the number of rows in the matrix: ");
    scanf("%d", &rows);
    printf("Enter the number of columns in the matrix: ");
    scanf("%d", &cols);

    int **matrix1 = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix1[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            printf("Enter the element at row %d column %d: ", i+1, j+1);
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Matrix 1:\n");
    print_matrix(matrix1, rows, cols);

    int **matrix2 = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix2[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            printf("Enter the element at row %d column %d: ", i+1, j+1);
            scanf("%d", &matrix2[i][j]);
        }
    }

    printf("Matrix 2:\n");
    print_matrix(matrix2, rows, cols);

    int **addition_result = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        addition_result[i] = (int *)malloc(cols * sizeof(int));
    }

    add_matrices(matrix1, matrix2, addition_result, rows, cols);

    printf("Addition Result:\n");
    print_matrix(addition_result, rows, cols);

    int **subtraction_result = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        subtraction_result[i] = (int *)malloc(cols * sizeof(int));
    }

    subtract_matrices(matrix1, matrix2, subtraction_result, rows, cols);

    printf("Subtraction Result:\n");
    print_matrix(subtraction_result, rows, cols);

    for (int i = 0; i < rows; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(addition_result[i]);
        free(subtraction_result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(addition_result);
    free(subtraction_result);

    return 0;
}