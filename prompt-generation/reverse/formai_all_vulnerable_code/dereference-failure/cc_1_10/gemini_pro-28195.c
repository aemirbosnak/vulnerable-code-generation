//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int rows;
    int cols;
    int **data;
} Matrix;

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

void destroy_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}

void print_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

Matrix *add_matrices(Matrix *matrix1, Matrix *matrix2) {
    if (matrix1->rows != matrix2->rows || matrix1->cols != matrix2->cols) {
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

Matrix *subtract_matrices(Matrix *matrix1, Matrix *matrix2) {
    if (matrix1->rows != matrix2->rows || matrix1->cols != matrix2->cols) {
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

Matrix *multiply_matrices(Matrix *matrix1, Matrix *matrix2) {
    if (matrix1->cols != matrix2->rows) {
        return NULL;
    }

    Matrix *result = create_matrix(matrix1->rows, matrix2->cols);
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix2->cols; j++) {
            int sum = 0;
            for (int k = 0; k < matrix1->cols; k++) {
                sum += matrix1->data[i][k] * matrix2->data[k][j];
            }
            result->data[i][j] = sum;
        }
    }

    return result;
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

    // Add the matrices
    Matrix *result1 = add_matrices(matrix1, matrix2);

    // Subtract the matrices
    Matrix *result2 = subtract_matrices(matrix1, matrix2);

    // Multiply the matrices
    Matrix *result3 = multiply_matrices(matrix1, matrix2);

    // Print the results
    printf("Matrix 1:\n");
    print_matrix(matrix1);
    printf("\nMatrix 2:\n");
    print_matrix(matrix2);
    printf("\nResult of addition:\n");
    print_matrix(result1);
    printf("\nResult of subtraction:\n");
    print_matrix(result2);
    printf("\nResult of multiplication:\n");
    print_matrix(result3);

    // Destroy the matrices
    destroy_matrix(matrix1);
    destroy_matrix(matrix2);
    destroy_matrix(result1);
    destroy_matrix(result2);
    destroy_matrix(result3);

    return 0;
}