//FormAI DATASET v1.0 Category: Matrix operations ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function signatures
void printMatrix(int **matrix, int rows, int cols);
void shapeShift(int **matrix, int rows, int cols);
void swapRows(int **matrix, int row1, int row2, int cols);
void swapCols(int **matrix, int col1, int col2, int rows);

int main() {
    // Random number generator initialization
    srand(time(NULL));

    // Matrix size initialization
    int rows = 5;
    int cols = 5;

    // Matrix allocation and initialization
    int **matrix = (int **) malloc(rows * sizeof(int *));
    for(int i = 0; i < rows; i++) {
        matrix[i] = (int *) malloc(cols * sizeof(int));
        for(int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 20;
        }
    }

    // Print initial matrix
    printf("Initial Matrix:\n");
    printMatrix(matrix, rows, cols);

    // Shape shift matrix
    shapeShift(matrix, rows, cols);

    // Print shape shifted matrix
    printf("Shape Shifted Matrix:\n");
    printMatrix(matrix, rows, cols);

    // Matrix deallocation
    for(int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

// Prints a matrix
void printMatrix(int **matrix, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Shape shifts a matrix
void shapeShift(int **matrix, int rows, int cols) {
    // Random shape shift operations initialization
    int numOfOperations = 10;
    int operations[numOfOperations];
    for(int i = 0; i < numOfOperations; i++) {
        operations[i] = rand() % 4;
    }

    // Shape shift operations
    for(int i = 0; i < numOfOperations; i++) {
        switch(operations[i]) {
            case 0: // Swap Rows
                swapRows(matrix, rand() % rows, rand() % rows, cols);
                break;
            case 1: // Swap Columns
                swapCols(matrix, rand() % cols, rand() % cols, rows);
                break;
            case 2: // Flip Matrix Horizontally
                for(int j = 0; j < rows; j++) {
                    for(int k = 0; k < cols / 2; k++) {
                        int temp = matrix[j][k];
                        matrix[j][k] = matrix[j][cols - k - 1];
                        matrix[j][cols - k - 1] = temp;
                    }
                }
                break;
            case 3: // Flip Matrix Vertically
                for(int j = 0; j < rows / 2; j++) {
                    for(int k = 0; k < cols; k++) {
                        int temp = matrix[j][k];
                        matrix[j][k] = matrix[rows - j - 1][k];
                        matrix[rows - j - 1][k] = temp;
                    }
                }
                break;
        }
    }
}

// Swaps two rows of a matrix
void swapRows(int **matrix, int row1, int row2, int cols) {
    for(int i = 0; i < cols; i++) {
        int temp = matrix[row1][i];
        matrix[row1][i] = matrix[row2][i];
        matrix[row2][i] = temp;
    }
}

// Swaps two cols of a matrix
void swapCols(int **matrix, int col1, int col2, int rows) {
    for(int i = 0; i < rows; i++) {
        int temp = matrix[i][col1];
        matrix[i][col1] = matrix[i][col2];
        matrix[i][col2] = temp;
    }
}