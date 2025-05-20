//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MATRIX_ROWS 10
#define MATRIX_COLS 15

typedef struct matrix {
    int rows;
    int cols;
    int **data;
} matrix_t;

matrix_t *create_matrix(void) {
    matrix_t *matrix = (matrix_t *)malloc(sizeof(matrix_t));
    matrix->rows = MATRIX_ROWS;
    matrix->cols = MATRIX_COLS;
    matrix->data = (int **)malloc(matrix->rows * sizeof(int *));
    for (int i = 0; i < matrix->rows; i++) {
        matrix->data[i] = (int *)malloc(matrix->cols * sizeof(int));
        for (int j = 0; j < matrix->cols; j++) {
            matrix->data[i][j] = (i + j) % 2 == 0 ? 1 : 0;
        }
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
    matrix_t *result = create_matrix();
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix2->cols; j++) {
            result->data[i][j] = matrix1->data[i][j] + matrix2->data[i][j];
        }
    }
    return result;
}

matrix_t *multiply_matrices(matrix_t *matrix1, matrix_t *matrix2) {
    matrix_t *result = create_matrix();
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix2->cols; j++) {
            int sum = 0;
            for (int k = 0; k < matrix2->rows; k++) {
                sum += matrix1->data[i][k] * matrix2->data[k][j];
            }
            result->data[i][j] = sum;
        }
    }
    return result;
}

int main() {
    srand(time(NULL));
    matrix_t *matrix1 = create_matrix();
    matrix_t *matrix2 = create_matrix();
    matrix_t *result1 = add_matrices(matrix1, matrix2);
    matrix_t *result2 = multiply_matrices(matrix1, matrix2);
    print_matrix(result1);
    print_matrix(result2);
    free(result1->data);
    free(result2->data);
    free(matrix1->data);
    free(matrix2->data);
    free(matrix1);
    free(matrix2);
    return 0;
}