//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATRIX_ROWS 10
#define MATRIX_COLS 10

typedef struct {
    int rows;
    int cols;
    int **matrix;
} matrix_t;

matrix_t *create_matrix(int rows, int cols) {
    matrix_t *matrix = malloc(sizeof(matrix_t));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->matrix = malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++) {
        matrix->matrix[i] = malloc(sizeof(int) * cols);
        for (int j = 0; j < cols; j++) {
            matrix->matrix[i][j] = rand() % 10;
        }
    }
    return matrix;
}

void print_matrix(matrix_t *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->matrix[i][j]);
        }
        printf("\n");
    }
}

void invert_matrix(matrix_t *matrix) {
    int **temp = malloc(sizeof(int *) * matrix->rows);
    for (int i = 0; i < matrix->rows; i++) {
        temp[i] = malloc(sizeof(int) * matrix->cols);
        for (int j = 0; j < matrix->cols; j++) {
            temp[i][j] = matrix->matrix[j][i];
        }
    }
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            matrix->matrix[i][j] = temp[i][j];
        }
    }
    free(temp);
}

int main() {
    matrix_t *matrix = create_matrix(MATRIX_ROWS, MATRIX_COLS);
    print_matrix(matrix);
    invert_matrix(matrix);
    print_matrix(matrix);
    free(matrix->matrix);
    free(matrix);
    return 0;
}