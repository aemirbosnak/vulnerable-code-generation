//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 4
#define COLS 4

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int *data;
} Matrix;

// Function to create a new matrix
Matrix* newMatrix(int rows, int cols) {
    Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (int*)malloc(sizeof(int) * rows * cols);
    return matrix;
}

// Function to print a matrix
void printMatrix(Matrix* matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i * matrix->cols + j]);
        }
        printf("\n");
    }
}

// Function to perform matrix addition
Matrix* addMatrix(Matrix* matrix1, Matrix* matrix2) {
    Matrix* result = newMatrix(matrix1->rows, matrix2->cols);
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix2->cols; j++) {
            result->data[i * result->cols + j] = matrix1->data[i * matrix1->cols + j] + matrix2->data[i * matrix2->cols + j];
        }
    }
    return result;
}

// Function to perform matrix multiplication
Matrix* multiplyMatrix(Matrix* matrix1, Matrix* matrix2) {
    Matrix* result = newMatrix(matrix1->rows, matrix2->cols * matrix1->cols);
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix2->cols; j++) {
            for (int k = 0; k < matrix1->cols; k++) {
                result->data[i * result->cols + j * matrix1->cols + k] =
                    matrix1->data[i * matrix1->cols + k] * matrix2->data[j * matrix2->cols + k];
            }
        }
    }
    return result;
}

int main() {
    Matrix* matrix1 = newMatrix(ROWS, COLS);
    Matrix* matrix2 = newMatrix(ROWS, COLS);
    Matrix* result = addMatrix(matrix1, matrix2);
    printMatrix(result);
    Matrix* result2 = multiplyMatrix(matrix1, matrix2);
    printMatrix(result2);
    return 0;
}