//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a matrix
typedef struct Matrix {
    int rows;
    int cols;
    int **data;
} Matrix;

// Function to create a new matrix
Matrix *create_matrix(int rows, int cols) {
    Matrix *matrix = malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = malloc(cols * sizeof(int));
    }
    return matrix;
}

// Function to print a matrix
void print_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
Matrix *add_matrices(Matrix *matrix1, Matrix *matrix2) {
    if (matrix1->rows != matrix2->rows || matrix1->cols != matrix2->cols) {
        printf("Matrices must have the same dimensions to be added.\n");
        return NULL;
    }
    Matrix *result = create_matrix(matrix1->rows, matrix1->cols);
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix1->cols; j++) {
            result->data[i][j] = matrix1->data[i][j] + matrix2->data[i][j];
        }
    }
    return result;
}

// Function to subtract two matrices
Matrix *subtract_matrices(Matrix *matrix1, Matrix *matrix2) {
    if (matrix1->rows != matrix2->rows || matrix1->cols != matrix2->cols) {
        printf("Matrices must have the same dimensions to be subtracted.\n");
        return NULL;
    }
    Matrix *result = create_matrix(matrix1->rows, matrix1->cols);
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix1->cols; j++) {
            result->data[i][j] = matrix1->data[i][j] - matrix2->data[i][j];
        }
    }
    return result;
}

// Function to multiply two matrices
Matrix *multiply_matrices(Matrix *matrix1, Matrix *matrix2) {
    if (matrix1->cols != matrix2->rows) {
        printf("The number of columns in the first matrix must be equal to the number of rows in the second matrix to be multiplied.\n");
        return NULL;
    }
    Matrix *result = create_matrix(matrix1->rows, matrix2->cols);
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

// Function to free the memory allocated for a matrix
void free_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}

int main() {
    // Create two matrices
    Matrix *matrix1 = create_matrix(2, 3);
    matrix1->data[0][0] = 1;
    matrix1->data[0][1] = 2;
    matrix1->data[0][2] = 3;
    matrix1->data[1][0] = 4;
    matrix1->data[1][1] = 5;
    matrix1->data[1][2] = 6;

    Matrix *matrix2 = create_matrix(3, 2);
    matrix2->data[0][0] = 7;
    matrix2->data[0][1] = 8;
    matrix2->data[1][0] = 9;
    matrix2->data[1][1] = 10;
    matrix2->data[2][0] = 11;
    matrix2->data[2][1] = 12;

    // Print the matrices
    printf("Matrix 1:\n");
    print_matrix(matrix1);
    printf("Matrix 2:\n");
    print_matrix(matrix2);

    // Add the matrices
    Matrix *result1 = add_matrices(matrix1, matrix2);
    if (result1 != NULL) {
        printf("Result of addition:\n");
        print_matrix(result1);
    }

    // Subtract the matrices
    Matrix *result2 = subtract_matrices(matrix1, matrix2);
    if (result2 != NULL) {
        printf("Result of subtraction:\n");
        print_matrix(result2);
    }

    // Multiply the matrices
    Matrix *result3 = multiply_matrices(matrix1, matrix2);
    if (result3 != NULL) {
        printf("Result of multiplication:\n");
        print_matrix(result3);
    }

    // Free the memory allocated for the matrices
    free_matrix(result1);
    free_matrix(result2);
    free_matrix(result3);
    free_matrix(matrix1);
    free_matrix(matrix2);

    return 0;
}