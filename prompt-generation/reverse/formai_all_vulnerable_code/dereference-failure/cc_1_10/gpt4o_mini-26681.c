//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory for a matrix
double** create_matrix(int rows, int cols) {
    double** matrix = (double**)malloc(rows * sizeof(double*));
    if (!matrix) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < rows; i++) {
        matrix[i] = (double*)malloc(cols * sizeof(double));
        if (!matrix[i]) {
            fprintf(stderr, "Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
    }
    return matrix;
}

// Function to free memory of a matrix
void free_matrix(double** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to generate a random matrix
void random_matrix(double** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = (double)(rand() % 100) / 10.0; // Random double between 0.0 and 10.0
        }
    }
}

// Function to print a matrix
void print_matrix(double** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
double** add_matrices(double** matrix1, double** matrix2, int rows, int cols) {
    double** result = create_matrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

// Function to multiply two matrices
double** multiply_matrices(double** matrix1, double** matrix2, int rows1, int cols1, int cols2) {
    double** result = create_matrix(rows1, cols2);
    for (int i = 0; i < rows1; i++) {
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
    int rows1 = 3, cols1 = 3; // Dimensions of the first matrix
    int rows2 = 3, cols2 = 3; // Dimensions of the second matrix

    // Create matrices
    double** matrix1 = create_matrix(rows1, cols1);
    double** matrix2 = create_matrix(rows2, cols2);

    // Fill matrices with random values
    random_matrix(matrix1, rows1, cols1);
    random_matrix(matrix2, rows2, cols2);

    // Print original matrices
    printf("Matrix 1:\n");
    print_matrix(matrix1, rows1, cols1);
    printf("\nMatrix 2:\n");
    print_matrix(matrix2, rows2, cols2);

    // Add matrices
    double** sum = add_matrices(matrix1, matrix2, rows1, cols1);
    printf("\nSum of matrices:\n");
    print_matrix(sum, rows1, cols1);

    // Multiply matrices
    double** product = multiply_matrices(matrix1, matrix2, rows1, cols1, cols2);
    printf("\nProduct of matrices:\n");
    print_matrix(product, rows1, cols2);

    // Free allocated memory
    free_matrix(matrix1, rows1);
    free_matrix(matrix2, rows2);
    free_matrix(sum, rows1);
    free_matrix(product, rows1);

    return 0;
}