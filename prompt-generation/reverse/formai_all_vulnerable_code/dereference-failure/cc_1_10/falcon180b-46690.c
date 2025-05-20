//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int rows;
    int cols;
    int **matrix;
} Matrix;

Matrix* create_matrix(int num_rows, int num_cols) {
    Matrix* new_matrix = malloc(sizeof(Matrix));
    new_matrix->rows = num_rows;
    new_matrix->cols = num_cols;
    new_matrix->matrix = malloc(sizeof(int*) * num_rows);
    for (int i = 0; i < num_rows; i++) {
        new_matrix->matrix[i] = malloc(sizeof(int) * num_cols);
    }
    return new_matrix;
}

void print_matrix(Matrix* matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->matrix[i][j]);
        }
        printf("\n");
    }
}

void transpose_matrix(Matrix* matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            int temp = matrix->matrix[i][j];
            matrix->matrix[i][j] = matrix->matrix[j][i];
            matrix->matrix[j][i] = temp;
        }
    }
}

void multiply_matrices(Matrix* matrix1, Matrix* matrix2, Matrix* result) {
    int sum = 0;
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix2->cols; j++) {
            for (int k = 0; k < matrix1->cols; k++) {
                sum += matrix1->matrix[i][k] * matrix2->matrix[k][j];
            }
            result->matrix[i][j] = sum;
            sum = 0;
        }
    }
}

int main() {
    Matrix* matrix1 = create_matrix(3, 3);
    Matrix* matrix2 = create_matrix(3, 3);
    Matrix* result = create_matrix(3, 3);

    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix1->cols; j++) {
            matrix1->matrix[i][j] = i + j;
        }
    }

    for (int i = 0; i < matrix2->rows; i++) {
        for (int j = 0; j < matrix2->cols; j++) {
            matrix2->matrix[i][j] = i - j;
        }
    }

    print_matrix(matrix1);
    print_matrix(matrix2);

    multiply_matrices(matrix1, matrix2, result);

    print_matrix(result);

    free(matrix1->matrix);
    free(matrix1);
    free(matrix2->matrix);
    free(matrix2);
    free(result->matrix);
    free(result);

    return 0;
}