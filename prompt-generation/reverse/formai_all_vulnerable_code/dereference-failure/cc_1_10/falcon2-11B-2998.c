//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random matrix
void generateRandomMatrix(int rows, int cols, int size, double **matrix) {
    for (int i = 0; i < rows; i++) {
        matrix[i] = (double *)malloc(cols * sizeof(double));
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = (double)(rand() % size);
        }
    }
}

// Function to print a matrix
void printMatrix(int rows, int cols, double **matrix) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to calculate the sum of a matrix
double calculateSum(int rows, int cols, double **matrix) {
    double sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

int main() {
    int rows = 3, cols = 3;
    int size = 10;
    double **matrix = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (double *)malloc(cols * sizeof(double));
    }
    srand(time(NULL));
    generateRandomMatrix(rows, cols, size, matrix);
    printf("Generated random matrix:\n");
    printMatrix(rows, cols, matrix);
    double sum = calculateSum(rows, cols, matrix);
    printf("Sum of the matrix: %lf\n", sum);
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}