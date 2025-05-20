//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **data;
} matrix_t;

// Function to create a new matrix
matrix_t* new_matrix(int rows, int cols) {
    matrix_t* mat = (matrix_t*)calloc(1, sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (int**)calloc(rows, sizeof(int*));
    for (int i = 0; i < rows; i++) {
        mat->data[i] = (int*)calloc(cols, sizeof(int));
    }
    return mat;
}

// Function to print a matrix
void print_matrix(matrix_t* mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
matrix_t* add_matrices(matrix_t* mat1, matrix_t* mat2) {
    int rows1 = mat1->rows;
    int cols1 = mat1->cols;
    int rows2 = mat2->rows;
    int cols2 = mat2->cols;
    matrix_t* result = new_matrix(rows1 + rows2, cols1 + cols2);
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            result->data[i][j] = mat1->data[i][j] + mat2->data[i][j];
        }
    }
    for (int i = rows1; i < rows1 + rows2; i++) {
        for (int j = 0; j < cols1 + cols2; j++) {
            result->data[i][j] = mat2->data[i - rows1][j];
        }
    }
    return result;
}

// Function to multiply a matrix by a scalar
matrix_t* scale_matrix(matrix_t* mat, int scalar) {
    matrix_t* result = new_matrix(mat->rows, mat->cols);
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            result->data[i][j] = scalar * mat->data[i][j];
        }
    }
    return result;
}

int main() {
    matrix_t* mat1 = new_matrix(3, 3);
    matrix_t* mat2 = new_matrix(3, 3);
    matrix_t* result = add_matrices(mat1, mat2);
    print_matrix(result);

    matrix_t* scaled_mat = scale_matrix(mat1, 2);
    print_matrix(scaled_mat);

    return 0;
}