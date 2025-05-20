//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define ROW_SIZE 5
#define COL_SIZE 3

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **matrix;
} matrix_t;

// Function to initialize a matrix
matrix_t *init_matrix(int rows, int cols) {
    matrix_t *matrix = (matrix_t *)malloc(sizeof(matrix_t));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->matrix = (int **)malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; i++) {
        matrix->matrix[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            matrix->matrix[i][j] = i * j;
        }
    }

    return matrix;
}

// Function to perform matrix multiplication
matrix_t *multiply_matrices(matrix_t *a, matrix_t *b) {
    int rows = a->rows;
    int cols = b->cols;
    matrix_t *result = (matrix_t *)malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; i++) {
        result->matrix[i] = (int *)malloc(cols * sizeof(int));

        for (int j = 0; j < cols; j++) {
            int sum = 0;
            for (int k = 0; k < a->cols; k++) {
                sum += a->matrix[i][k] * b->matrix[k][j];
            }
            result->matrix[i][j] = sum;
        }
    }

    return result;
}

int main() {
    matrix_t *a = init_matrix(ROW_SIZE, COL_SIZE);
    matrix_t *b = init_matrix(ROW_SIZE, COL_SIZE);
    matrix_t *result = multiply_matrices(a, b);

    // Print the result matrix
    for (int i = 0; i < ROW_SIZE; i++) {
        for (int j = 0; j < COL_SIZE; j++) {
            printf("%d ", result->matrix[i][j]);
        }
        printf("\n");
    }

    free(a->matrix);
    free(b->matrix);
    free(result->matrix);
    free(result);

    return 0;
}