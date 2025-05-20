//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MATRIX_ROWS 10
#define MATRIX_COLS 10

typedef struct matrix {
    int rows;
    int cols;
    int **data;
} matrix_t;

matrix_t *create_matrix(int rows, int cols) {
    matrix_t *matrix = (matrix_t *) malloc(sizeof(matrix_t));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (int **) malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = (int *) malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            matrix->data[i][j] = i * j;
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
    matrix_t *result = create_matrix(matrix1->rows, matrix2->cols);
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix2->cols; j++) {
            for (int k = 0; k < matrix1->cols; k++) {
                result->data[i][j] += matrix1->data[i][k] * matrix2->data[k][j];
            }
        }
    }
    return result;
}

int main() {
    matrix_t *matrix1 = create_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *matrix2 = create_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *result = add_matrices(matrix1, matrix2);
    print_matrix(result);
    return 0;
}