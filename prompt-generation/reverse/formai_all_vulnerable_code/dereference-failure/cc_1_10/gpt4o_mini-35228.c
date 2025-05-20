//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printMatrix(double **matrix, int n);
void gaussianElimination(double **matrix, double *solution, int n);
double** allocateMatrix(int n);
void freeMatrix(double **matrix, int n);
void readMatrixFromFile(const char *filename, double **matrix, int n);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file_with_coefficients> <number_of_equations>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int n = atoi(argv[2]);
    double **matrix = allocateMatrix(n);
    double *solution = (double *)malloc(n * sizeof(double));

    readMatrixFromFile(argv[1], matrix, n);
    printf("Matrix representation:\n");
    printMatrix(matrix, n);
    
    gaussianElimination(matrix, solution, n);

    printf("The solutions are:\n");
    for (int i = 0; i < n; i++) {
        printf("x_%d = %.4f\n", i + 1, solution[i]);
    }

    freeMatrix(matrix, n);
    free(solution);
    return EXIT_SUCCESS;
}

void readMatrixFromFile(const char *filename, double **matrix, int n) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            if (fscanf(file, "%lf", &matrix[i][j]) != 1) {
                fprintf(stderr, "Error reading matrix data from file.\n");
                fclose(file);
                exit(EXIT_FAILURE);
            }
        }
    }
    fclose(file);
}

double** allocateMatrix(int n) {
    double **matrix = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (double *)malloc((n + 1) * sizeof(double));
    }
    return matrix;
}

void freeMatrix(double **matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void gaussianElimination(double **matrix, double *solution, int n) {
    for (int i = 0; i < n; i++) {
        // Pivoting
        for (int j = i + 1; j < n; j++) {
            if (fabs(matrix[j][i]) > fabs(matrix[i][i])) {
                // Swapping rows
                double *temp = matrix[i];
                matrix[i] = matrix[j];
                matrix[j] = temp;
            }
        }

        // Elimination
        for (int j = i + 1; j < n; j++) {
            double factor = matrix[j][i] / matrix[i][i];
            for (int k = i; k < n + 1; k++) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }

    // Back substitution
    for (int i = n - 1; i >= 0; i--) {
        solution[i] = matrix[i][n] / matrix[i][i];
        for (int j = i + 1; j < n; j++) {
            solution[i] -= (matrix[i][j] / matrix[i][i]) * solution[j];
        }
    }
}

void printMatrix(double **matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            printf("%8.4f ", matrix[i][j]);
        }
        printf("\n");
    }
}