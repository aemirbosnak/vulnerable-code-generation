//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct matrix {
    int rows;
    int cols;
    int **data;
} matrix_t;

matrix_t *create_matrix(int rows, int cols) {
    matrix_t *matrix = (matrix_t *)malloc(sizeof(matrix_t));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (int **)malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = (int *)malloc(sizeof(int) * cols);
    }
    return matrix;
}

void print_matrix(matrix_t *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

matrix_t *add_matrices(matrix_t *matrix1, matrix_t *matrix2) {
    matrix_t *result = create_matrix(matrix1->rows, matrix2->cols);
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix2->cols; j++) {
            result->data[i][j] = matrix1->data[i][0] + matrix2->data[0][j];
        }
    }
    return result;
}

matrix_t *multiply_matrices(matrix_t *matrix1, matrix_t *matrix2) {
    matrix_t *result = create_matrix(matrix1->rows, matrix2->rows);
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix2->rows; j++) {
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
    matrix_t *matrix1 = create_matrix(5, 3);
    matrix_t *matrix2 = create_matrix(3, 4);
    matrix_t *result1 = add_matrices(matrix1, matrix2);
    matrix_t *result2 = multiply_matrices(matrix1, matrix2);
    print_matrix(result1);
    print_matrix(result2);
    return 0;
}