//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **data;
} matrix_t;

// Function to create a new matrix
matrix_t *new_matrix(int rows, int cols) {
    matrix_t *mat = (matrix_t *)calloc(1, sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (int **)calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat->data[i] = (int *)calloc(cols, sizeof(int));
    }
    return mat;
}

// Function to free a matrix
void free_matrix(matrix_t *mat) {
    for (int i = 0; i < mat->rows; i++) {
        free(mat->data[i]);
    }
    free(mat->data);
    free(mat);
}

// Function to perform matrix multiplication
matrix_t *multiply_matrices(matrix_t *a, matrix_t *b) {
    int rows_a = a->rows;
    int cols_a = a->cols;
    int rows_b = b->rows;
    int cols_b = b->cols;
    matrix_t *result = new_matrix(rows_a, cols_b);
    
    for (int i = 0; i < rows_a; i++) {
        for (int j = 0; j < cols_b; j++) {
            int sum = 0;
            for (int k = 0; k < cols_a; k++) {
                sum += a->data[i][k] * b->data[k][j];
            }
            result->data[i][j] = sum;
        }
    }
    
    return result;
}

int main() {
    matrix_t *a = new_matrix(3, 2);
    matrix_t *b = new_matrix(2, 3);
    matrix_t *result = multiply_matrices(a, b);
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", result->data[i][j]);
        }
        printf("\n");
    }
    
    free_matrix(a);
    free_matrix(b);
    free_matrix(result);
    return 0;
}