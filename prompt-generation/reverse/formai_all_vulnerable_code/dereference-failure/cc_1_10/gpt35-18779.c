//FormAI DATASET v1.0 Category: Matrix operations ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Function to create a matrix of given size and fill it with random values between 0 and 9
int** createMatrix(int rows, int cols) {
    int** matrix = (int**) malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*) malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10; // generate random number between 0 and 9
        }
    }
    return matrix;
}

// Function to multiply two matrices
int** multiplyMatrices(int** matrix1, int rows1, int cols1, int** matrix2, int rows2, int cols2) {
    // Check if the matrices are compatible for multiplication
    if (cols1 != rows2) {
        printf("Error: matrices cannot be multiplied!\n");
        return NULL;
    }
    // Create the result matrix and initialize it with zeros
    int** result = (int**) malloc(rows1 * sizeof(int*));
    for (int i = 0; i < rows1; i++) {
        result[i] = (int*) calloc(cols2, sizeof(int)); // use calloc to initialize with zeros
    }
    // Perform matrix multiplication
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
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

int main() {
    // Create two matrices and fill them with random values
    int** A = createMatrix(3, 4);
    int** B = createMatrix(4, 2);
    // Print the matrices
    printf("Matrix A:\n");
    printMatrix(A, 3, 4);
    printf("Matrix B:\n");
    printMatrix(B, 4, 2);
    // Multiply the matrices and print the result
    int** C = multiplyMatrices(A, 3, 4, B, 4, 2);
    if (C != NULL) {
        printf("Matrix C = A * B:\n");
        printMatrix(C, 3, 2);
    }
    // Free the matrices
    for (int i = 0; i < 3; i++) {
        free(A[i]);
    }
    free(A);
    for (int i = 0; i < 4; i++) {
        free(B[i]);
    }
    free(B);
    if (C != NULL) {
        for (int i = 0; i < 3; i++) {
            free(C[i]);
        }
        free(C);
    }
    return 0;
}