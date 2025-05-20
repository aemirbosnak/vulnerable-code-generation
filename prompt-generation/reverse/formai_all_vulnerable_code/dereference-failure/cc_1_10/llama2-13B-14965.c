//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    int rows;
    int cols;
    int **matrix;
} matrix_t;

void init_matrix(matrix_t *matrix) {
    matrix->rows = 0;
    matrix->cols = 0;
    matrix->matrix = NULL;
}

void print_matrix(matrix_t *matrix) {
    int i, j;
    for (i = 0; i < matrix->rows; i++) {
        for (j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->matrix[i][j]);
        }
        printf("\n");
    }
}

void add_matrix(matrix_t *matrix1, matrix_t *matrix2) {
    int i, j;
    for (i = 0; i < matrix1->rows; i++) {
        for (j = 0; j < matrix2->cols; j++) {
            matrix1->matrix[i][j] = matrix1->matrix[i][j] + matrix2->matrix[i][j];
        }
    }
}

void multiply_matrix(matrix_t *matrix1, matrix_t *matrix2) {
    int i, j, k;
    for (i = 0; i < matrix1->rows; i++) {
        for (j = 0; j < matrix2->cols; j++) {
            for (k = 0; k < matrix2->rows; k++) {
                matrix1->matrix[i][j] += matrix1->matrix[i][k] * matrix2->matrix[k][j];
            }
        }
    }
}

int main() {
    matrix_t matrix1, matrix2, result;
    init_matrix(&matrix1);
    init_matrix(&matrix2);
    init_matrix(&result);

    matrix1.rows = 3;
    matrix1.cols = 4;
    matrix1.matrix = malloc(matrix1.rows * matrix1.cols * sizeof(int));
    for (int i = 0; i < matrix1.rows; i++) {
        for (int j = 0; j < matrix1.cols; j++) {
            matrix1.matrix[i][j] = i * j;
        }
    }

    matrix2.rows = 4;
    matrix2.cols = 3;
    matrix2.matrix = malloc(matrix2.rows * matrix2.cols * sizeof(int));
    for (int i = 0; i < matrix2.rows; i++) {
        for (int j = 0; j < matrix2.cols; j++) {
            matrix2.matrix[i][j] = i * j + 1;
        }
    }

    add_matrix(&matrix1, &matrix2);
    print_matrix(&result);

    matrix2.rows = 3;
    matrix2.cols = 4;
    matrix2.matrix = realloc(matrix2.matrix, matrix2.rows * matrix2.cols * sizeof(int));
    for (int i = 0; i < matrix2.rows; i++) {
        for (int j = 0; j < matrix2.cols; j++) {
            matrix2.matrix[i][j] = i * j;
        }
    }

    multiply_matrix(&matrix1, &matrix2);
    print_matrix(&result);

    free(matrix1.matrix);
    free(matrix2.matrix);
    free(result.matrix);

    return 0;
}