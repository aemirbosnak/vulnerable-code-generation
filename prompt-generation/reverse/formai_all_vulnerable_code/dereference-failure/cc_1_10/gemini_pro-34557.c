//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Define a custom data structure to represent a matrix
typedef struct Matrix {
    int rows;
    int cols;
    int **data;
} Matrix;

// Function to create a new matrix with the given dimensions
Matrix *createMatrix(int rows, int cols) {
    Matrix *matrix = (Matrix *) malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (int **) malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = (int *) malloc(cols * sizeof(int));
    }
    return matrix;
}

// Function to free the memory allocated to a matrix
void freeMatrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}

// Function to add two matrices
Matrix *addMatrices(Matrix *matrix1, Matrix *matrix2) {
    if (matrix1->rows != matrix2->rows || matrix1->cols != matrix2->cols) {
        printf("Error: matrices must have the same dimensions\n");
        return NULL;
    }
    Matrix *result = createMatrix(matrix1->rows, matrix1->cols);
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix1->cols; j++) {
            result->data[i][j] = matrix1->data[i][j] + matrix2->data[i][j];
        }
    }
    return result;
}

// Function to print a matrix
void printMatrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Create two matrices
    Matrix *matrix1 = createMatrix(2, 3);
    matrix1->data[0][0] = 1;
    matrix1->data[0][1] = 2;
    matrix1->data[0][2] = 3;
    matrix1->data[1][0] = 4;
    matrix1->data[1][1] = 5;
    matrix1->data[1][2] = 6;
    Matrix *matrix2 = createMatrix(2, 3);
    matrix2->data[0][0] = 7;
    matrix2->data[0][1] = 8;
    matrix2->data[0][2] = 9;
    matrix2->data[1][0] = 10;
    matrix2->data[1][1] = 11;
    matrix2->data[1][2] = 12;

    // Add the two matrices
    Matrix *result = addMatrices(matrix1, matrix2);

    // Print the result
    printMatrix(result);

    // Free the memory allocated to the matrices
    freeMatrix(matrix1);
    freeMatrix(matrix2);
    freeMatrix(result);

    return 0;
}