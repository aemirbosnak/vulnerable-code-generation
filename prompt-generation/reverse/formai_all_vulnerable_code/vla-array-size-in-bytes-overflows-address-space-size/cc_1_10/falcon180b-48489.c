//Falcon-180B DATASET v1.0 Category: Educational ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void generateMatrix(int rows, int cols, int matrix[rows][cols]);
void printMatrix(int rows, int cols, int matrix[rows][cols]);
void transposeMatrix(int rows, int cols, int matrix[rows][cols]);

int main() {
    int rows, cols;

    // Get user input for number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Initialize the matrix with random values
    int matrix[rows][cols];
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }

    // Print the original matrix
    printf("\nOriginal Matrix:\n");
    printMatrix(rows, cols, matrix);

    // Transpose the matrix
    transposeMatrix(rows, cols, matrix);

    // Print the transposed matrix
    printf("\nTransposed Matrix:\n");
    printMatrix(cols, rows, matrix);

    return 0;
}

// Function to generate a matrix with given number of rows and columns
void generateMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

// Function to print a matrix
void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to transpose a matrix
void transposeMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[j][i] = matrix[i][j];
        }
    }
}