//FormAI DATASET v1.0 Category: Matrix operations ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Function to display the matrix
void displayMatrix(double **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
double** addMatrices(double **matrix1, double **matrix2, int rows, int cols) {
    double **result = malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
        result[i] = malloc(cols * sizeof(double));
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

// Function to subtract two matrices
double** subtractMatrices(double **matrix1, double **matrix2, int rows, int cols) {
    double **result = malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
        result[i] = malloc(cols * sizeof(double));
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    return result;
}

// Function to multiply two matrices
double** multiplyMatrices(double **matrix1, double **matrix2, int rows1, int cols1, int rows2, int cols2) {
    if (cols1 != rows2) {
        printf("Error: Matrices cannot be multiplied!\n");
        return NULL;
    }
    double **result = calloc(rows1, sizeof(double *));
    for (int i = 0; i < rows1; i++) {
        result[i] = calloc(cols2, sizeof(double));
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}

int main() {
    int rows1, cols1, rows2, cols2;

    // Take input for matrix 1
    printf("Enter number of rows for matrix 1: ");
    scanf("%d", &rows1);
    printf("Enter number of columns for matrix 1: ");
    scanf("%d", &cols1);
    double **matrix1 = malloc(rows1 * sizeof(double *));
    for (int i = 0; i < rows1; i++) {
        matrix1[i] = malloc(cols1 * sizeof(double));
        for (int j = 0; j < cols1; j++) {
            printf("Enter value for matrix1[%d][%d]: ", i, j);
            scanf("%lf", &matrix1[i][j]);
        }
    }

    // Take input for matrix 2
    printf("\nEnter number of rows for matrix 2: ");
    scanf("%d", &rows2);
    printf("Enter number of columns for matrix 2: ");
    scanf("%d", &cols2);
    double **matrix2 = malloc(rows2 * sizeof(double *));
    for (int i = 0; i < rows2; i++) {
        matrix2[i] = malloc(cols2 * sizeof(double));
        for (int j = 0; j < cols2; j++) {
            printf("Enter value for matrix2[%d][%d]: ", i, j);
            scanf("%lf", &matrix2[i][j]);
        }
    }

    printf("\nMatrix 1:");
    displayMatrix(matrix1, rows1, cols1);

    printf("\nMatrix 2:");
    displayMatrix(matrix2, rows2, cols2);

    if (rows1 != rows2 || cols1 != cols2) {
        printf("\nMatrices cannot be added or subtracted!\n");
    } else {
        printf("\nAddition of matrices:");
        double **addition = addMatrices(matrix1, matrix2, rows1, cols1);
        displayMatrix(addition, rows1, cols1);

        printf("\nSubtraction of matrices:");
        double **subtraction = subtractMatrices(matrix1, matrix2, rows1, cols1);
        displayMatrix(subtraction, rows1, cols1);

        // Free memory allocated for addition and subtraction matrices
        for (int i = 0; i < rows1; i++) {
            free(addition[i]);
            free(subtraction[i]);
        }
        free(addition);
        free(subtraction);
    }

    printf("\nMultiplication of matrices:");
    double **multiplication = multiplyMatrices(matrix1, matrix2, rows1, cols1, rows2, cols2);
    if (multiplication != NULL) {
        displayMatrix(multiplication, rows1, cols2);

        // Free memory allocated for multiplication matrix
        for (int i = 0; i < rows1; i++) {
            free(multiplication[i]);
        }
        free(multiplication);
    }

    // Free memory allocated for matrix1 and matrix2
    for (int i = 0; i < rows1; i++) {
        free(matrix1[i]);
    }
    for (int i = 0; i < rows2; i++) {
        free(matrix2[i]);
    }
    free(matrix1);
    free(matrix2);

    return 0;
}