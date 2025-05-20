//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int *data;
} matrix_t;

// Function to create a matrix
matrix_t *create_matrix(int rows, int cols) {
    matrix_t *mat = (matrix_t *)malloc(sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (int *)malloc(rows * cols * sizeof(int));
    return mat;
}

// Function to print a matrix
void print_matrix(matrix_t *mat) {
    int i, j;
    for (i = 0; i < mat->rows; i++) {
        for (j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i * mat->cols + j]);
        }
        printf("\n");
    }
}

// Function to perform matrix multiplication
matrix_t *multiply_matrices(matrix_t *mat1, matrix_t *mat2) {
    int i, j, k;
    matrix_t *result = create_matrix(mat1->rows, mat2->cols);

    for (i = 0; i < mat1->rows; i++) {
        for (j = 0; j < mat2->cols; j++) {
            int sum = 0;
            for (k = 0; k < mat1->cols; k++) {
                sum += mat1->data[i * mat1->cols + k] * mat2->data[k * mat2->cols + j];
            }
            result->data[i * result->cols + j] = sum;
        }
    }

    return result;
}

// Function to perform matrix addition
matrix_t *add_matrices(matrix_t *mat1, matrix_t *mat2) {
    int i, j;
    matrix_t *result = create_matrix(mat1->rows, mat2->cols);

    for (i = 0; i < mat1->rows; i++) {
        for (j = 0; j < mat2->cols; j++) {
            result->data[i * result->cols + j] = mat1->data[i * mat1->cols + j] + mat2->data[j * mat2->cols + i];
        }
    }

    return result;
}

int main() {
    matrix_t *mat1 = create_matrix(3, 4);
    matrix_t *mat2 = create_matrix(3, 3);
    matrix_t *result;

    // Initialize matrix elements
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            mat1->data[i * 4 + j] = i * j;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mat2->data[i * 3 + j] = i * j;
        }
    }

    // Perform matrix multiplication
    result = multiply_matrices(mat1, mat2);

    // Print result
    print_matrix(result);

    // Perform matrix addition
    result = add_matrices(mat1, mat2);

    // Print result
    print_matrix(result);

    return 0;
}