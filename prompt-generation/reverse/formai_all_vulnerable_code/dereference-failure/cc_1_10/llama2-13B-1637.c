//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 5
#define COLS 7

// Define a matrix structure
typedef struct {
    int rows;
    int cols;
    int **matrix;
} matrix_t;

// Initialize a matrix
matrix_t *init_matrix(int rows, int cols) {
    matrix_t *mat = malloc(sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->matrix = malloc(sizeof(int*) * rows);
    for (int i = 0; i < rows; i++) {
        mat->matrix[i] = malloc(sizeof(int) * cols);
        for (int j = 0; j < cols; j++) {
            mat->matrix[i][j] = rand() % 10;
        }
    }
    return mat;
}

// Perform matrix multiplication
matrix_t *multiply_matrices(matrix_t *a, matrix_t *b) {
    matrix_t *result = init_matrix(a->rows, b->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            int sum = 0;
            for (int k = 0; k < a->cols; k++) {
                sum += a->matrix[i][k] * b->matrix[k][j];
            }
            result->matrix[i][j] = sum;
        }
    }
    return result;
}

// Transpose a matrix
matrix_t *transpose_matrix(matrix_t *mat) {
    matrix_t *result = init_matrix(mat->rows, mat->cols);
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            result->matrix[i][j] = mat->matrix[j][i];
        }
    }
    return result;
}

// Print a matrix
void print_matrix(matrix_t *mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    matrix_t *a = init_matrix(ROWS, COLS);
    matrix_t *b = init_matrix(ROWS, COLS);
    matrix_t *result = multiply_matrices(a, b);
    print_matrix(result);
    matrix_t *transposed = transpose_matrix(result);
    print_matrix(transposed);
    free(transposed);
    free(result);
    free(a);
    free(b);
    return 0;
}