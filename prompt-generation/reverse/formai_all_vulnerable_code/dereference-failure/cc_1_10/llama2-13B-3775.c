//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    int rows;
    int cols;
    int **matrix;
} Matrix;

Matrix *create_matrix(int rows, int cols) {
    Matrix *matrix = (Matrix *)calloc(1, sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->matrix = (int **)calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix->matrix[i] = (int *)calloc(cols, sizeof(int));
    }
    return matrix;
}

void print_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->matrix[i][j]);
        }
        printf("\n");
    }
}

void add_matrix(Matrix *matrix1, Matrix *matrix2) {
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix2->cols; j++) {
            matrix1->matrix[i][j] = matrix1->matrix[i][j] + matrix2->matrix[i][j];
        }
    }
}

void multiply_matrix(Matrix *matrix1, Matrix *matrix2) {
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix2->cols; j++) {
            int sum = 0;
            for (int k = 0; k < matrix2->rows; k++) {
                sum += matrix1->matrix[i][k] * matrix2->matrix[k][j];
            }
            matrix1->matrix[i][j] = sum;
        }
    }
}

int main() {
    Matrix *matrix1 = create_matrix(5, 3);
    Matrix *matrix2 = create_matrix(3, 4);
    Matrix *result = NULL;

    // Initialize matrix1
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            matrix1->matrix[i][j] = i * j;
        }
    }

    // Initialize matrix2
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            matrix2->matrix[i][j] = i * j + 1;
        }
    }

    // Add matrices
    add_matrix(matrix1, matrix2);

    // Multiply matrices
    multiply_matrix(matrix1, matrix2);

    // Print result
    print_matrix(result);

    return 0;
}