//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATRIX_ROWS 5
#define MATRIX_COLS 3

typedef struct {
    int rows;
    int cols;
    int *data;
} matrix_t;

matrix_t *create_matrix(int rows, int cols) {
    matrix_t *matrix = (matrix_t *)calloc(1, sizeof(matrix_t));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (int *)calloc(rows * cols, sizeof(int));
    return matrix;
}

void print_matrix(matrix_t *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i * matrix->cols + j]);
        }
        printf("\n");
    }
}

void add_matrices(matrix_t *matrix1, matrix_t *matrix2) {
    int rows1 = matrix1->rows;
    int cols1 = matrix1->cols;
    int rows2 = matrix2->rows;
    int cols2 = matrix2->cols;
    int data[rows1 * cols2];
    
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            int sum = matrix1->data[i * matrix1->cols + j] + matrix2->data[i * matrix2->cols + j];
            data[i * cols2 + j] = sum;
        }
    }
    
    matrix_t *result = create_matrix(rows1, cols2);
    result->data = data;
}

void multiply_matrices(matrix_t *matrix1, matrix_t *matrix2) {
    int rows1 = matrix1->rows;
    int cols1 = matrix1->cols;
    int rows2 = matrix2->rows;
    int cols2 = matrix2->cols;
    int data[rows1 * rows2];
    
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < rows2; j++) {
            int sum = 0;
            for (int k = 0; k < cols1; k++) {
                sum += matrix1->data[i * matrix1->cols + k] * matrix2->data[k * matrix2->cols + j];
            }
            data[i * rows2 + j] = sum;
        }
    }
    
    matrix_t *result = create_matrix(rows1, rows2);
    result->data = data;
}

int main() {
    matrix_t *matrix1 = create_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *matrix2 = create_matrix(MATRIX_ROWS, MATRIX_COLS);
    
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            matrix1->data[i * matrix1->cols + j] = i * j;
            matrix2->data[i * matrix2->cols + j] = i * j + 1;
        }
    }
    
    add_matrices(matrix1, matrix2);
    print_matrix(matrix1);
    
    matrix1 = create_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix2 = create_matrix(MATRIX_ROWS, MATRIX_COLS);
    
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            matrix1->data[i * matrix1->cols + j] = i * j;
            matrix2->data[i * matrix2->cols + j] = i * j + 1;
        }
    }
    
    multiply_matrices(matrix1, matrix2);
    print_matrix(matrix1);
    
    return 0;
}