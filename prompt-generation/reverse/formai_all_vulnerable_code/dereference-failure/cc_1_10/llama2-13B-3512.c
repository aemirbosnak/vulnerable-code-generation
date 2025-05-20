//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: recursive
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

// Function to free the memory of a matrix
void free_matrix(matrix_t *mat) {
    for (int i = 0; i < mat->rows; i++) {
        free(mat->data[i]);
    }
    free(mat->data);
    free(mat);
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

// Function to perform matrix multiplication
matrix_t *multiply_matrices(matrix_t *mat1, matrix_t *mat2) {
    int rows1 = mat1->rows;
    int cols1 = mat1->cols;
    int rows2 = mat2->rows;
    int cols2 = mat2->cols;
    matrix_t *result = new_matrix(rows1, cols2);

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            int sum = 0;
            for (int k = 0; k < cols1; k++) {
                sum += mat1->data[i][k] * mat2->data[k][j];
            }
            result->data[i][j] = sum;
        }
    }

    return result;
}

// Function to perform matrix addition
matrix_t *add_matrices(matrix_t *mat1, matrix_t *mat2) {
    int rows1 = mat1->rows;
    int cols1 = mat1->cols;
    int rows2 = mat2->rows;
    int cols2 = mat2->cols;
    matrix_t *result = new_matrix(rows1, cols2);

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result->data[i][j] = mat1->data[i][j] + mat2->data[i][j];
        }
    }

    return result;
}

int main() {
    matrix_t *mat1 = new_matrix(3, 3);
    matrix_t *mat2 = new_matrix(3, 3);
    matrix_t *result;

    // Initialize the matrices
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mat1->data[i][j] = i * j;
            mat2->data[i][j] = i * j + 1;
        }
    }

    // Perform matrix multiplication
    result = multiply_matrices(mat1, mat2);
    print_matrix(result);

    // Perform matrix addition
    result = add_matrices(mat1, mat2);
    print_matrix(result);

    free_matrix(mat1);
    free_matrix(mat2);
    free_matrix(result);

    return 0;
}