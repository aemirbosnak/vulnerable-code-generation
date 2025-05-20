//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

#define MATRIX_SIZE 3

typedef struct Matrix {
    int **data;
    int rows;
    int cols;
} Matrix;

void createMatrix(Matrix *matrix, int rows, int cols) {
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (int **)malloc(sizeof(int *) * rows);
    for (int i = 0; i < matrix->rows; i++) {
        matrix->data[i] = (int *)malloc(sizeof(int) * cols);
    }
}

void printMatrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Matrix *matrix = NULL;
    createMatrix(matrix, MATRIX_SIZE, MATRIX_SIZE);

    matrix->data[0][0] = 1;
    matrix->data[0][1] = 2;
    matrix->data[0][2] = 3;
    matrix->data[1][0] = 4;
    matrix->data[1][1] = 5;
    matrix->data[1][2] = 6;
    matrix->data[2][0] = 7;
    matrix->data[2][1] = 8;
    matrix->data[2][2] = 9;

    printMatrix(matrix);

    free(matrix->data);
    free(matrix);

    return 0;
}