//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: lively
#include <stdio.h>
#include <stdlib.h>

void displayMenu();
void createMatrix(int rows, int cols, int matrix[rows][cols]);
void addMatrices(int rows, int cols, int matrixA[rows][cols], int matrixB[rows][cols], int result[rows][cols]);
void subtractMatrices(int rows, int cols, int matrixA[rows][cols], int matrixB[rows][cols], int result[rows][cols]);
void multiplyMatrices(int rowsA, int colsA, int rowsB, int colsB, int matrixA[rowsA][colsA], int matrixB[rowsB][colsB], int result[rowsA][colsB]);
void printMatrix(int rows, int cols, int matrix[rows][cols]);

int main() {
    int rows, cols, choice;

    printf("Welcome to the Matrix Operation Adventure!\n");
    printf("Let's begin by defining the size of our matrices:\n");
    printf("Enter rows and columns for square matrices (e.g. 3 3 for 3x3): ");
    scanf("%d %d", &rows, &cols);

    int matrixA[rows][cols], matrixB[rows][cols], result[rows][cols];

    createMatrix(rows, cols, matrixA);
    createMatrix(rows, cols, matrixB);
    
    do {
        displayMenu();
        printf("Please select an operation (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMatrices(rows, cols, matrixA, matrixB, result);
                printf("The result of addition is:\n");
                printMatrix(rows, cols, result);
                break;
            case 2:
                subtractMatrices(rows, cols, matrixA, matrixB, result);
                printf("The result of subtraction is:\n");
                printMatrix(rows, cols, result);
                break;
            case 3:
                multiplyMatrices(rows, cols, rows, cols, matrixA, matrixB, result);
                printf("The result of multiplication is:\n");
                printMatrix(rows, cols, result);
                break;
            case 4:
                printf("Let’s display the first matrix:\n");
                printMatrix(rows, cols, matrixA);
                break;
            case 5:
                printf("Let’s display the second matrix:\n");
                printMatrix(rows, cols, matrixB);
                break;
            case 0:
                printf("Thank you for using the Matrix Operation Adventure! Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void displayMenu() {
    printf("\nMatrix Operations Menu:\n");
    printf("1. Add Two Matrices\n");
    printf("2. Subtract Two Matrices\n");
    printf("3. Multiply Two Matrices\n");
    printf("4. Display First Matrix\n");
    printf("5. Display Second Matrix\n");
    printf("0. Exit\n");
}

void createMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Enter the elements of the matrix (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void addMatrices(int rows, int cols, int matrixA[rows][cols], int matrixB[rows][cols], int result[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void subtractMatrices(int rows, int cols, int matrixA[rows][cols], int matrixB[rows][cols], int result[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

void multiplyMatrices(int rowsA, int colsA, int rowsB, int colsB, int matrixA[rowsA][colsA], int matrixB[rowsB][colsB], int result[rowsA][colsB]) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
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