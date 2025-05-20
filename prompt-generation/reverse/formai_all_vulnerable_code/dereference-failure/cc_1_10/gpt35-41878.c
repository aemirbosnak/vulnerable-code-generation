//FormAI DATASET v1.0 Category: Matrix operations ; Style: active
#include <stdio.h>
#include <stdlib.h>

// function to print the matrix
void print_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// function to add two matrices
int **add_matrices(int **matrix1, int **matrix2, int rows, int cols) {
    int **result = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        result[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

// function to subtract two matrices
int **subtract_matrices(int **matrix1, int **matrix2, int rows, int cols) {
    int **result = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        result[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    return result;
}

// function to multiply two matrices
int **multiply_matrices(int **matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2) {
    if (cols1 != rows2) {
        printf("Cannot multiply matrices\n");
        exit(1);
    }
    int **result = (int **)malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++) {
        result[i] = (int *)malloc(cols2 * sizeof(int));
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}

int main() {
    // create the first matrix
    int rows1 = 2;
    int cols1 = 3;
    int **matrix1 = (int **)malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++) {
        matrix1[i] = (int *)malloc(cols1 * sizeof(int));
        for (int j = 0; j < cols1; j++) {
            matrix1[i][j] = (i + 1)*(j + 1);
        }
    }

    // create the second matrix
    int rows2 = 3;
    int cols2 = 2;
    int **matrix2 = (int **)malloc(rows2 * sizeof(int *));
    for (int i = 0; i < rows2; i++) {
        matrix2[i] = (int *)malloc(cols2 * sizeof(int));
        for (int j = 0; j < cols2; j++) {
            matrix2[i][j] = (i + 1) + (j + 1);
        }
    }

    // print the two matrices
    printf("Matrix 1:\n");
    print_matrix(matrix1, rows1, cols1);
    printf("\n");
    printf("Matrix 2:\n");
    print_matrix(matrix2, rows2, cols2);
    printf("\n");

    // add the two matrices
    int **added_matrix = add_matrices(matrix1, matrix2, rows1, cols1);
    printf("Added Matrix:\n");
    print_matrix(added_matrix, rows1, cols1);
    printf("\n");

    // subtract the two matrices
    int **subtracted_matrix = subtract_matrices(matrix1, matrix2, rows1, cols1);
    printf("Subtracted Matrix:\n");
    print_matrix(subtracted_matrix, rows1, cols1);
    printf("\n");

    // multiply the two matrices
    int **multiplied_matrix = multiply_matrices(matrix1, matrix2, rows1, cols1, rows2, cols2);
    printf("Multiplied Matrix:\n");
    print_matrix(multiplied_matrix, rows1, cols2);

    // free the memory
    for (int i = 0; i < rows1; i++) {
        free(matrix1[i]);
    }
    free(matrix1);

    for (int i = 0; i < rows2; i++) {
        free(matrix2[i]);
    }
    free(matrix2);

    for (int i = 0; i < rows1; i++) {
        free(added_matrix[i]);
        free(subtracted_matrix[i]);
        free(multiplied_matrix[i]);
    }
    free(added_matrix);
    free(subtracted_matrix);
    free(multiplied_matrix);

    return 0;
}