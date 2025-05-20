//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Custom Matrix Structure
typedef struct {
    int rows;
    int cols;
    int **data;
} Matrix;

// Function to create a new matrix with specified dimensions
Matrix* createMatrix(int rows, int cols) {
    Matrix *matrix = (Matrix*) malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (int**) malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = (int*) malloc(cols * sizeof(int));
    }
    return matrix;
}

// Function to free the memory allocated for a matrix
void freeMatrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
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

// Function to add two matrices
Matrix* addMatrices(Matrix *matrix1, Matrix *matrix2) {
    if (matrix1->rows != matrix2->rows || matrix1->cols != matrix2->cols) {
        printf("Matrices cannot be added as they have different dimensions.\n");
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

// Function to subtract two matrices
Matrix* subtractMatrices(Matrix *matrix1, Matrix *matrix2) {
    if (matrix1->rows != matrix2->rows || matrix1->cols != matrix2->cols) {
        printf("Matrices cannot be subtracted as they have different dimensions.\n");
        return NULL;
    }

    Matrix *result = createMatrix(matrix1->rows, matrix1->cols);
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix1->cols; j++) {
            result->data[i][j] = matrix1->data[i][j] - matrix2->data[i][j];
        }
    }
    return result;
}

// Function to multiply two matrices
Matrix* multiplyMatrices(Matrix *matrix1, Matrix *matrix2) {
    if (matrix1->cols != matrix2->rows) {
        printf("Matrices cannot be multiplied as the number of columns in the first matrix does not match the number of rows in the second matrix.\n");
        return NULL;
    }

    Matrix *result = createMatrix(matrix1->rows, matrix2->cols);
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix2->cols; j++) {
            result->data[i][j] = 0;
            for (int k = 0; k < matrix1->cols; k++) {
                result->data[i][j] += matrix1->data[i][k] * matrix2->data[k][j];
            }
        }
    }
    return result;
}

int main() {
    // Create two matrices
    Matrix *matrix1 = createMatrix(3, 3);
    Matrix *matrix2 = createMatrix(3, 3);

    // Initialize the matrices with values
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix1->cols; j++) {
            matrix1->data[i][j] = i + j;
        }
    }

    for (int i = 0; i < matrix2->rows; i++) {
        for (int j = 0; j < matrix2->cols; j++) {
            matrix2->data[i][j] = j - i;
        }
    }

    // Print the original matrices
    printf("Matrix 1:\n");
    printMatrix(matrix1);

    printf("Matrix 2:\n");
    printMatrix(matrix2);

    // Add the two matrices
    Matrix *matrixSum = addMatrices(matrix1, matrix2);
    printf("Sum of the two matrices:\n");
    printMatrix(matrixSum);

    // Subtract the second matrix from the first matrix
    Matrix *matrixDifference = subtractMatrices(matrix1, matrix2);
    printf("Difference of the two matrices:\n");
    printMatrix(matrixDifference);

    // Multiply the two matrices
    Matrix *matrixProduct = multiplyMatrices(matrix1, matrix2);
    printf("Product of the two matrices:\n");
    printMatrix(matrixProduct);

    // Free the memory allocated for the matrices
    freeMatrix(matrix1);
    freeMatrix(matrix2);
    freeMatrix(matrixSum);
    freeMatrix(matrixDifference);
    freeMatrix(matrixProduct);

    return 0;
}