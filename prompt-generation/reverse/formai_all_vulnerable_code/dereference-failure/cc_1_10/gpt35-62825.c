//FormAI DATASET v1.0 Category: Matrix operations ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Function to display a matrix
void displayMatrix(int **matrix, int rows, int columns) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
int **addMatrices(int **matrix1, int **matrix2, int rows, int columns) {
    int **result = (int **)malloc(rows * sizeof(int *));
    for(int i=0; i<rows; i++) {
        result[i] = (int *)malloc(columns * sizeof(int));
        for(int j=0; j<columns; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

// Function to subtract two matrices
int **subtractMatrices(int **matrix1, int **matrix2, int rows, int columns) {
    int **result = (int **)malloc(rows * sizeof(int *));
    for(int i=0; i<rows; i++) {
        result[i] = (int *)malloc(columns * sizeof(int));
        for(int j=0; j<columns; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    return result;
}

// Function to multiply two matrices
int **multiplyMatrices(int **matrix1, int **matrix2, int rows1, int columns1, int columns2) {
    int **result = (int **)malloc(rows1 * sizeof(int *));
    for(int i=0; i<rows1; i++) {
        result[i] = (int *)malloc(columns2 * sizeof(int));
        for(int j=0; j<columns2; j++) {
            result[i][j] = 0;
            for(int k=0; k<columns1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}

int main() {
    int rows1, columns1, rows2, columns2;

    printf("Enter the number of rows in matrix 1: ");
    scanf("%d", &rows1);

    printf("Enter the number of columns in matrix 1: ");
    scanf("%d", &columns1);

    int **matrix1 = (int **)malloc(rows1 * sizeof(int *));
    for(int i=0; i<rows1; i++) {
        matrix1[i] = (int *)malloc(columns1 * sizeof(int));
        for(int j=0; j<columns1; j++) {
            printf("Enter the element at row %d column %d: ", i+1, j+1);
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter the number of rows in matrix 2: ");
    scanf("%d", &rows2);

    printf("Enter the number of columns in matrix 2: ");
    scanf("%d", &columns2);

    int **matrix2 = (int **)malloc(rows2 * sizeof(int *));
    for(int i=0; i<rows2; i++) {
        matrix2[i] = (int *)malloc(columns2 * sizeof(int));
        for(int j=0; j<columns2; j++) {
            printf("Enter the element at row %d column %d: ", i+1, j+1);
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Addition of two matrices
    if(rows1 == rows2 && columns1 == columns2) {
        printf("\nAddition of two matrices:\n");
        int **addition = addMatrices(matrix1, matrix2, rows1, columns1);
        displayMatrix(addition, rows1, columns1);
    } else {
        printf("\nMatrices cannot be added\n");
    }

    // Subtraction of two matrices
    if(rows1 == rows2 && columns1 == columns2) {
        printf("\nSubtraction of two matrices:\n");
        int **subtraction = subtractMatrices(matrix1, matrix2, rows1, columns1);
        displayMatrix(subtraction, rows1, columns1);
    } else {
        printf("\nMatrices cannot be subtracted\n");
    }

    // Multiplication of two matrices
    if(columns1 == rows2) {
        printf("\nMultiplication of two matrices:\n");
        int **multiplication = multiplyMatrices(matrix1, matrix2, rows1, columns1, columns2);
        displayMatrix(multiplication, rows1, columns2);
    } else {
        printf("\nMatrices cannot be multiplied\n");
    }

    return 0;
}