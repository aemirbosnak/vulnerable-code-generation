//FormAI DATASET v1.0 Category: Sudoku solver ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Function to print the sudoku matrix
void printMatrix(int **matrix, int size) {
    printf("+-----------------------+\n");
    for (int i = 0; i < size; i++) {
        printf("|");
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] == 0) {
                printf("  ");
            } else {
                printf(" %d", matrix[i][j]);
            }
            if (j % 3 == 2) {
                printf(" |");
            }
        }
        printf("\n");
        if (i % 3 == 2) {
            printf("+-----------------------+\n");
        }
    }
}

// Function to check if a number is already present in a row
int checkRow(int **matrix, int row, int num, int size) {
    for (int col = 0; col < size; col++) {
        if (matrix[row][col] == num) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a number is already present in a column
int checkCol(int **matrix, int col, int num, int size) {
    for (int row = 0; row < size; row++) {
        if (matrix[row][col] == num) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a number is already present in a sub-matrix
int checkSubMatrix(int **matrix, int row, int col, int num, int size) {
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[startRow + i][startCol + j] == num) {
                return 1;
            }
        }
    }
    return 0;
}

// Function to solve the sudoku puzzle using recursive backtracking
int solveSudoku(int **matrix, int row, int col, int size) {
    // If we have reached the last cell, then the puzzle is solved
    if (row == size - 1 && col == size) {
        return 1;
    }

    // If we have reached the end of the current row, move to the next row
    if (col == size) {
        row++;
        col = 0;
    }

    // If the current cell is already filled, move to the next cell
    if (matrix[row][col] != 0) {
        return solveSudoku(matrix, row, col + 1, size);
    }

    // Try to fill the current cell with numbers from 1 to 9
    for (int num = 1; num <= 9; num++) {
        if (!checkRow(matrix, row, num, size) &&
            !checkCol(matrix, col, num, size) &&
            !checkSubMatrix(matrix, row, col, num, size)) {
            matrix[row][col] = num;
            if (solveSudoku(matrix, row, col + 1, size)) {
                return 1;
            }
            matrix[row][col] = 0; // Backtrack
        }
    }
    return 0;
}

int main() {
    // Initialize the sudoku matrix
    int size = 9;
    int **matrix = (int**)malloc(sizeof(int*) * size);
    for (int i = 0; i < size; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * size);
    }

    // Read input from user
    printf("Enter the sudoku puzzle:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Solve the sudoku puzzle
    if (solveSudoku(matrix, 0, 0, size)) {
        printf("\nThe solved sudoku puzzle is:\n");
        printMatrix(matrix, size);
    } else {
        printf("\nNo solution found!\n");
    }

    // Free memory
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}