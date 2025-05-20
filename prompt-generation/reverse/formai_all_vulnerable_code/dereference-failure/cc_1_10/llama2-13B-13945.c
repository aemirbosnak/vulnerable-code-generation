//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Matrix operations
void matrix_print(int **mat, int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int matrix_sum(int **mat, int rows, int cols) {
    int i, j, sum = 0;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            sum += mat[i][j];
        }
    }

    return sum;
}

int matrix_prod(int **mat, int rows, int cols) {
    int i, j, prod = 1;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            prod *= mat[i][j];
        }
    }

    return prod;
}

int main() {
    int rows, cols;
    int **mat;

    // Matrix operations
    printf("Matrix operations example program:\n");

    // Create a matrix
    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &rows, &cols);
    mat = calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat[i] = calloc(cols, sizeof(int));
    }

    // Print the matrix
    matrix_print(mat, rows, cols);

    // Calculate the sum of the matrix
    int sum = matrix_sum(mat, rows, cols);
    printf("Sum of the matrix: %d\n", sum);

    // Calculate the product of the matrix
    int prod = matrix_prod(mat, rows, cols);
    printf("Product of the matrix: %d\n", prod);

    // Free the memory
    for (int i = 0; i < rows; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}