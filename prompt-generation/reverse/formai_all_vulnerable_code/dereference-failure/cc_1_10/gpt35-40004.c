//FormAI DATASET v1.0 Category: Matrix operations ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Function to print a matrix
void print_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to multiply two matrices
int **multiply_matrices(int **matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2) {
    // Check if the matrices can be multiplied
    if (cols1 != rows2) {
        printf("Error: Cannot multiply matrices of sizes %dx%d and %dx%d.\n", rows1, cols1, rows2, cols2);
        exit(1);
    }
    
    // Allocate memory for the result matrix
    int **result = (int **)malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++) {
        result[i] = (int *)malloc(cols2 * sizeof(int));
    }
    
    // Perform matrix multiplication
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            int sum = 0;
            for (int k = 0; k < cols1; k++) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = sum;
        }
    }
    
    return result;
}

int main() {
    // Define the matrices
    int rows1 = 3, cols1 = 3;
    int **matrix1 = (int **)malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++) {
        matrix1[i] = (int *)malloc(cols1 * sizeof(int));
    }
    matrix1[0][0] = 1;
    matrix1[0][1] = 2;
    matrix1[0][2] = 3;
    matrix1[1][0] = 4;
    matrix1[1][1] = 5;
    matrix1[1][2] = 6;
    matrix1[2][0] = 7;
    matrix1[2][1] = 8;
    matrix1[2][2] = 9;
    
    int rows2 = 3, cols2 = 2;
    int **matrix2 = (int **)malloc(rows2 * sizeof(int *));
    for (int i = 0; i < rows2; i++) {
        matrix2[i] = (int *)malloc(cols2 * sizeof(int));
    }
    matrix2[0][0] = 1;
    matrix2[0][1] = 2;
    matrix2[1][0] = 3;
    matrix2[1][1] = 4;
    matrix2[2][0] = 5;
    matrix2[2][1] = 6;
    
    // Print the matrices
    printf("Matrix 1:\n");
    print_matrix(matrix1, rows1, cols1);
    printf("Matrix 2:\n");
    print_matrix(matrix2, rows2, cols2);
    
    // Multiply the matrices
    int **result = multiply_matrices(matrix1, matrix2, rows1, cols1, rows2, cols2);
    
    // Print the result
    printf("Result:\n");
    print_matrix(result, rows1, cols2);
    
    // Free memory
    for (int i = 0; i < rows1; i++) {
        free(matrix1[i]);
    }
    for (int i = 0; i < rows2; i++) {
        free(matrix2[i]);
    }
    for (int i = 0; i < rows1; i++) {
        free(result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);
    
    return 0;
}