//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Generate a random matrix of size n x m */
double **generate_matrix(int n, int m) {
    double **matrix = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (double *)malloc(m * sizeof(double));
        for (int j = 0; j < m; j++) {
            matrix[i][j] = (double)rand() / RAND_MAX;
        }
    }
    return matrix;
}

/* Print a matrix of size n x m */
void print_matrix(double **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/* Add two matrices of size n x m */
double **add_matrices(double **matrix1, double **matrix2, int n, int m) {
    double **matrix = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (double *)malloc(m * sizeof(double));
        for (int j = 0; j < m; j++) {
            matrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return matrix;
}

/* Multiply two matrices of size n x m and p x q */
double **multiply_matrices(double **matrix1, int n, int m, double **matrix2, int p, int q) {
    double **matrix = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (double *)malloc(q * sizeof(double));
        for (int j = 0; j < q; j++) {
            matrix[i][j] = 0;
            for (int k = 0; k < m; k++) {
                matrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return matrix;
}

int main() {
    // Set the random seed
    srand(time(NULL));

    // Generate two random matrices of size n x m
    int n = 3;
    int m = 4;
    double **matrix1 = generate_matrix(n, m);
    double **matrix2 = generate_matrix(n, m);

    // Print the two matrices
    printf("Matrix 1:\n");
    print_matrix(matrix1, n, m);
    printf("Matrix 2:\n");
    print_matrix(matrix2, n, m);

    // Add the two matrices
    double **matrix3 = add_matrices(matrix1, matrix2, n, m);

    // Print the resulting matrix
    printf("Resulting matrix:\n");
    print_matrix(matrix3, n, m);

    // Multiply the two matrices
    double **matrix4 = multiply_matrices(matrix1, n, m, matrix2, n, m);

    // Print the resulting matrix
    printf("Resulting matrix:\n");
    print_matrix(matrix4, n, m);

    return 0;
}