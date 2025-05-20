//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Recursive function to calculate the determinant of a matrix
double determinant(double **matrix, int n) {
    if (n == 1) {
        return matrix[0][0];
    } else {
        double det = 0;
        for (int i = 0; i < n; i++) {
            // Create a new matrix without the ith row and jth column
            double **submatrix = malloc((n - 1) * sizeof(double *));
            for (int j = 0; j < n - 1; j++) {
                submatrix[j] = malloc((n - 1) * sizeof(double));
            }
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (j < i) {
                        submatrix[j][k] = matrix[j][k];
                    } else if (j > i) {
                        submatrix[j - 1][k] = matrix[j][k];
                    }
                }
            }

            // Calculate the determinant of the submatrix
            double subdet = determinant(submatrix, n - 1);

            // Add the determinant of the submatrix to the total determinant
            det += matrix[i][0] * subdet * ((i % 2 == 0) ? 1 : -1);

            // Free the memory allocated for the submatrix
            for (int j = 0; j < n - 1; j++) {
                free(submatrix[j]);
            }
            free(submatrix);
        }
        return det;
    }
}

// Main function to test the determinant function
int main() {
    // Create a matrix
    double **matrix = malloc(3 * sizeof(double *));
    for (int i = 0; i < 3; i++) {
        matrix[i] = malloc(3 * sizeof(double));
    }
    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[0][2] = 3;
    matrix[1][0] = 4;
    matrix[1][1] = 5;
    matrix[1][2] = 6;
    matrix[2][0] = 7;
    matrix[2][1] = 8;
    matrix[2][2] = 9;

    // Calculate the determinant of the matrix
    double det = determinant(matrix, 3);

    // Print the determinant of the matrix
    printf("Determinant of the matrix: %lf\n", det);

    // Free the memory allocated for the matrix
    for (int i = 0; i < 3; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}