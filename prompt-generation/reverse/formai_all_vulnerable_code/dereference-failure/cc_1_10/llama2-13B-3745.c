//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define ROW_HEIGHT 5
#define COL_WIDTH 10

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **matrix;
} matrix_t;

// Function to initialize a matrix
matrix_t *init_matrix(int rows, int cols) {
    matrix_t *matrix = (matrix_t *)calloc(1, sizeof(matrix_t));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->matrix = (int **)calloc(matrix->rows, sizeof(int *));
    for (int i = 0; i < matrix->rows; i++) {
        matrix->matrix[i] = (int *)calloc(matrix->cols, sizeof(int));
    }
    return matrix;
}

// Function to perform matrix multiplication
matrix_t *mult_matrices(matrix_t *a, matrix_t *b) {
    matrix_t *result = (matrix_t *)calloc(1, sizeof(matrix_t));
    int i, j, k;
    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < b->cols; j++) {
            int sum = 0;
            for (k = 0; k < a->cols; k++) {
                sum += a->matrix[i][k] * b->matrix[k][j];
            }
            result->matrix[i][j] = sum;
        }
    }
    return result;
}

// Function to print a matrix
void print_matrix(matrix_t *matrix) {
    int i, j;
    for (i = 0; i < matrix->rows; i++) {
        for (j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    matrix_t *a = init_matrix(ROW_HEIGHT, COL_WIDTH);
    matrix_t *b = init_matrix(ROW_HEIGHT, COL_WIDTH);
    matrix_t *result = mult_matrices(a, b);
    print_matrix(result);
    free(result);
    free(a);
    free(b);
    return 0;
}