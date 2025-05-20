//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 10

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **matrix;
} CMatrix;

// Function to create a new matrix
CMatrix* newMatrix(int r, int c) {
    CMatrix* mat = (CMatrix*) malloc(sizeof(CMatrix));
    mat->rows = r;
    mat->cols = c;
    mat->matrix = (int**) malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++) {
        mat->matrix[i] = (int*) malloc(c * sizeof(int));
    }
    return mat;
}

// Function to print a matrix
void printMatrix(CMatrix* mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
CMatrix* addMatrices(CMatrix* mat1, CMatrix* mat2) {
    CMatrix* result = newMatrix(mat1->rows, mat2->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            int sum = mat1->matrix[i][j] + mat2->matrix[j][i];
            result->matrix[i][j] = sum % 10;
        }
    }
    return result;
}

// Function to multiply a matrix by a scalar
CMatrix* scalarMultiply(CMatrix* mat, int scalar) {
    CMatrix* result = newMatrix(mat->rows, mat->cols);
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            result->matrix[i][j] = mat->matrix[i][j] * scalar;
        }
    }
    return result;
}

int main() {
    srand(time(NULL));

    // Create two random matrices
    CMatrix* mat1 = newMatrix(5, 3);
    CMatrix* mat2 = newMatrix(3, 5);

    // Initialize matrix elements with random values
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat1->cols; j++) {
            mat1->matrix[i][j] = rand() % 10;
        }
    }
    for (int i = 0; i < mat2->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            mat2->matrix[i][j] = rand() % 10;
        }
    }

    // Add the matrices
    CMatrix* result = addMatrices(mat1, mat2);

    // Print the result
    printMatrix(result);

    // Multiply the result by a scalar
    CMatrix* scaledResult = scalarMultiply(result, 2);

    // Print the scaled result
    printMatrix(scaledResult);

    return 0;
}