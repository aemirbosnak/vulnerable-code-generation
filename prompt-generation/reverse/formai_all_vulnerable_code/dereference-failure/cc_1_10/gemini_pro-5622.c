//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Constants representing Holmes and Watson
#define HOLMES 1
#define WATSON 2

// Function prototypes
void printMatrix(int **matrix, int rows, int cols);
int **createMatrix(int rows, int cols);
void freeMatrix(int **matrix, int rows);
int **addMatrices(int **matrix1, int **matrix2, int rows, int cols);
int **subtractMatrices(int **matrix1, int **matrix2, int rows, int cols);
int **multiplyMatrices(int **matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2);

int main() {
    // Create matrices to represent two clues
    int **clue1 = createMatrix(3, 3);
    int **clue2 = createMatrix(3, 3);

    // Initialize the matrices with values
    clue1[0][0] = 1; clue1[0][1] = 2; clue1[0][2] = 3;
    clue1[1][0] = 4; clue1[1][1] = 5; clue1[1][2] = 6;
    clue1[2][0] = 7; clue1[2][1] = 8; clue1[2][2] = 9;

    clue2[0][0] = 10; clue2[0][1] = 11; clue2[0][2] = 12;
    clue2[1][0] = 13; clue2[1][1] = 14; clue2[1][2] = 15;
    clue2[2][0] = 16; clue2[2][1] = 17; clue2[2][2] = 18;

    // Print the original matrices
    printf("Clue 1:\n");
    printMatrix(clue1, 3, 3);

    printf("Clue 2:\n");
    printMatrix(clue2, 3, 3);

    // Add the matrices (representing the combination of clues)
    int **combinedClues = addMatrices(clue1, clue2, 3, 3);

    // Print the combined matrix
    printf("Combined Clues:\n");
    printMatrix(combinedClues, 3, 3);

    // Subtract the matrices (representing the difference between clues)
    int **differenceClues = subtractMatrices(clue1, clue2, 3, 3);

    // Print the difference matrix
    printf("Difference Clues:\n");
    printMatrix(differenceClues, 3, 3);

    // Multiply the matrices (representing the correlation between clues)
    int **correlationClues = multiplyMatrices(clue1, clue2, 3, 3, 3, 3);

    // Print the correlation matrix
    printf("Correlation Clues:\n");
    printMatrix(correlationClues, 3, 3);

    // Free the allocated memory
    freeMatrix(clue1, 3);
    freeMatrix(clue2, 3);
    freeMatrix(combinedClues, 3);
    freeMatrix(differenceClues, 3);
    freeMatrix(correlationClues, 3);

    return 0;
}

// Function to print a matrix
void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to create a matrix
int **createMatrix(int rows, int cols) {
    int **matrix = (int **)malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * cols);
    }
    return matrix;
}

// Function to free a matrix
void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to add two matrices
int **addMatrices(int **matrix1, int **matrix2, int rows, int cols) {
    int **result = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

// Function to subtract two matrices
int **subtractMatrices(int **matrix1, int **matrix2, int rows, int cols) {
    int **result = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    return result;
}

// Function to multiply two matrices
int **multiplyMatrices(int **matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2) {
    int **result = createMatrix(rows1, cols2);
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