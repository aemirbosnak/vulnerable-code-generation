//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define MATRIX_ROWS 5
#define MATRIX_COLS 7

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **data;
} matrix_t;

// Function to create a new matrix
matrix_t *new_matrix(int rows, int cols) {
    matrix_t *mat = malloc(sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++) {
        mat->data[i] = malloc(sizeof(int) * cols);
    }
    return mat;
}

// Function to print a matrix
void print_matrix(matrix_t *mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
matrix_t *add_matrices(matrix_t *mat1, matrix_t *mat2) {
    matrix_t *result = new_matrix(mat1->rows, mat2->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            int sum = mat1->data[i][j] + mat2->data[i][j];
            result->data[i][j] = sum % 10;
        }
    }
    return result;
}

// Function to multiply a matrix by a scalar
matrix_t *multiply_matrix_by_scalar(matrix_t *mat, int scalar) {
    matrix_t *result = new_matrix(mat->rows, mat->cols);
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            result->data[i][j] = mat->data[i][j] * scalar;
        }
    }
    return result;
}

int main() {
    matrix_t *mat1 = new_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *mat2 = new_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *result;

    // Initialize the matrices
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            mat1->data[i][j] = i * j % 10;
            mat2->data[i][j] = i * j % 10 + 1;
        }
    }

    // Add the matrices
    result = add_matrices(mat1, mat2);

    // Print the result
    print_matrix(result);

    // Multiply the result by 2
    result = multiply_matrix_by_scalar(result, 2);

    // Print the result again
    print_matrix(result);

    return 0;
}