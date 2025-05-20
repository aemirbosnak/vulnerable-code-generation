//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Function to transpose a matrix
int **transpose(int **matrix, int rows, int cols) {
    int i, j, k;
    int **transposed_matrix = (int **)calloc(rows, sizeof(int *));
    for (i = 0; i < rows; i++) {
        transposed_matrix[i] = (int *)calloc(cols, sizeof(int));
        for (j = 0; j < cols; j++) {
            for (k = 0; k < rows; k++) {
                transposed_matrix[i][j] += matrix[k][j] * matrix[i][k];
            }
        }
    }
    return transposed_matrix;
}

// Function to compute the determinant of a matrix
int determinant(int **matrix, int rows) {
    int i, j, k;
    if (rows == 1) {
        return matrix[0][0];
    }
    int sign = 1;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < rows; j++) {
            if (i != j) {
                sign *= matrix[i][j];
            }
        }
    }
    return sign;
}

int main() {
    int rows, cols;
    printf("Enter the number of rows and columns: ");
    scanf("%dx%d", &rows, &cols);
    int **matrix = (int **)calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)calloc(cols, sizeof(int));
        for (int j = 0; j < cols; j++) {
            printf("Enter element %d, %d: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Transpose the matrix
    int **transposed_matrix = transpose(matrix, rows, cols);

    // Print the transposed matrix
    print_matrix(transposed_matrix, rows, cols);

    // Compute the determinant of the matrix
    int determinant_value = determinant(matrix, rows);
    printf("The determinant of the matrix is %d\n", determinant_value);

    // Free the memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}