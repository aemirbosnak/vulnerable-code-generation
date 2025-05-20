//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

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

void free_matrix(Matrix *matrix) {
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
        printf("Error: matrices must have the same dimensions.\n");
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
        printf("Error: matrices must have the same dimensions.\n");
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
        printf("Error: number of columns in matrix1 must equal number of rows in matrix2.\n");
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
    srand(time(NULL));

    // Create two random matrices
    Matrix *matrix1 = create_matrix(MAX_SIZE, MAX_SIZE);
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix1->cols; j++) {
            matrix1->data[i][j] = rand() % 100;
        }
    }

    Matrix *matrix2 = create_matrix(MAX_SIZE, MAX_SIZE);
    for (int i = 0; i < matrix2->rows; i++) {
        for (int j = 0; j < matrix2->cols; j++) {
            matrix2->data[i][j] = rand() % 100;
        }
    }

    // Print the original matrices
    printf("Matrix 1:\n");
    print_matrix(matrix1);

    printf("Matrix 2:\n");
    print_matrix(matrix2);

    // Add the matrices
    Matrix *sum = add_matrices(matrix1, matrix2);
    printf("Sum of matrices:\n");
    print_matrix(sum);

    // Subtract the matrices
    Matrix *difference = subtract_matrices(matrix1, matrix2);
    printf("Difference of matrices:\n");
    print_matrix(difference);

    // Multiply the matrices
    Matrix *product = multiply_matrices(matrix1, matrix2);
    printf("Product of matrices:\n");
    print_matrix(product);

    // Free the allocated memory
    free_matrix(matrix1);
    free_matrix(matrix2);
    free_matrix(sum);
    free_matrix(difference);
    free_matrix(product);

    return 0;
}