//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Function to create a matrix
int** createMatrix(int rows, int cols) {
    // Allocate memory for the matrix
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }

    // Initialize the matrix with zeros
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 0;
        }
    }

    return matrix;
}

// Function to print a matrix
void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
int** addMatrices(int** matrix1, int** matrix2, int rows, int cols) {
    // Create a new matrix to store the result
    int** resultMatrix = createMatrix(rows, cols);

    // Add the corresponding elements of the two matrices
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            resultMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return resultMatrix;
}

// Function to subtract two matrices
int** subtractMatrices(int** matrix1, int** matrix2, int rows, int cols) {
    // Create a new matrix to store the result
    int** resultMatrix = createMatrix(rows, cols);

    // Subtract the corresponding elements of the two matrices
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            resultMatrix[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    return resultMatrix;
}

// Function to multiply two matrices
int** multiplyMatrices(int** matrix1, int** matrix2, int rows1, int cols1, int rows2, int cols2) {
    // Check if the number of columns of the first matrix is equal to the number of rows of the second matrix
    if (cols1 != rows2) {
        printf("Matrix multiplication is not possible.");
        return NULL;
    }

    // Create a new matrix to store the result
    int** resultMatrix = createMatrix(rows1, cols2);

    // Multiply the corresponding elements of the two matrices
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return resultMatrix;
}

// Function to find the transpose of a matrix
int** transposeMatrix(int** matrix, int rows, int cols) {
    // Create a new matrix to store the transpose
    int** transpose = createMatrix(cols, rows);

    // Transpose the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    return transpose;
}

int main() {
    // Create two matrices
    int** matrix1 = createMatrix(3, 3);
    int** matrix2 = createMatrix(3, 3);

    // Initialize the matrices
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix1[i][j] = i + j;
            matrix2[i][j] = i * j;
        }
    }

    // Print the matrices
    printf("Matrix 1:\n");
    printMatrix(matrix1, 3, 3);
    printf("\nMatrix 2:\n");
    printMatrix(matrix2, 3, 3);

    // Add the matrices
    int** additionResult = addMatrices(matrix1, matrix2, 3, 3);

    // Print the addition result
    printf("\nAddition Result:\n");
    printMatrix(additionResult, 3, 3);

    // Subtract the matrices
    int** subtractionResult = subtractMatrices(matrix1, matrix2, 3, 3);

    // Print the subtraction result
    printf("\nSubtraction Result:\n");
    printMatrix(subtractionResult, 3, 3);

    // Multiply the matrices
    int** multiplicationResult = multiplyMatrices(matrix1, matrix2, 3, 3, 3, 3);

    // Print the multiplication result
    printf("\nMultiplication Result:\n");
    printMatrix(multiplicationResult, 3, 3);

    // Find the transpose of matrix1
    int** transposeResult = transposeMatrix(matrix1, 3, 3);

    // Print the transpose result
    printf("\nTranspose Result of Matrix 1:\n");
    printMatrix(transposeResult, 3, 3);

    // Free the memory allocated for the matrices
    for (int i = 0; i < 3; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(additionResult[i]);
        free(subtractionResult[i]);
        free(multiplicationResult[i]);
        free(transposeResult[i]);
    }
    free(matrix1);
    free(matrix2);
    free(additionResult);
    free(subtractionResult);
    free(multiplicationResult);
    free(transposeResult);

    return 0;
}