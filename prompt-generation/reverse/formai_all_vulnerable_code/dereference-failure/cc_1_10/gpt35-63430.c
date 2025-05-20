//FormAI DATASET v1.0 Category: Matrix operations ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void initMatrix(int rows, int cols, int matrix[rows][cols]);
void printMatrix(int rows, int cols, int matrix[rows][cols]);
void multiplyMatrix(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols2]);

int main() {

    // Seed the random number generator
    srand(time(0));

    // Define the matrix dimensions
    const int ROWS1 = 2, COLS1 = 3, ROWS2 = 3, COLS2 = 2;

    // Declare the matrices
    int matrix1[ROWS1][COLS1];
    int matrix2[ROWS2][COLS2];
    int result[ROWS1][COLS2];

    // Initialize the matrices with random numbers
    printf("Initializing matrices with random numbers...\n");
    initMatrix(ROWS1, COLS1, matrix1);
    initMatrix(ROWS2, COLS2, matrix2);

    // Print the matrices
    printf("Matrix 1:\n");
    printMatrix(ROWS1, COLS1, matrix1);
    printf("Matrix 2:\n");
    printMatrix(ROWS2, COLS2, matrix2);

    // Multiply the matrices
    printf("Multiplying matrices...\n");
    multiplyMatrix(ROWS1, COLS1, matrix1, ROWS2, COLS2, matrix2, result);

    // Print the result
    printf("Result:\n");
    printMatrix(ROWS1, COLS2, result);

    return 0;
}

void initMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrix(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols2]) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}