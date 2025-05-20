//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MATRIX_NAME "safe_matrix"

// Structure to store a matrix
typedef struct {
    int rows;
    int cols;
    int **matrix;
} matrix_t;

// Function to create a new matrix
matrix_t* new_matrix(int rows, int cols) {
    matrix_t* mat = malloc(sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->matrix = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        mat->matrix[i] = malloc(cols * sizeof(int));
    }
    return mat;
}

// Function to print a matrix
void print_matrix(matrix_t* mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->matrix[i][j]);
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
            result->matrix[i][j] = mat1->matrix[i][j] + mat2->matrix[i][j];
        }
    }
    for (int i = rows1; i < rows1 + rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            result->matrix[i][j] = mat1->matrix[i][j] + mat2->matrix[i][j];
        }
    }
    return result;
}

// Function to multiply a matrix by a scalar
matrix_t* scale_matrix(matrix_t* mat, int scale) {
    int rows = mat->rows;
    int cols = mat->cols;
    matrix_t* result = new_matrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result->matrix[i][j] = scale * mat->matrix[i][j];
        }
    }
    return result;
}

int main() {
    srand(time(NULL));
    matrix_t* mat1 = new_matrix(5, 5);
    matrix_t* mat2 = new_matrix(5, 5);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            mat1->matrix[i][j] = rand() % 10;
            mat2->matrix[i][j] = rand() % 10;
        }
    }
    matrix_t* result = add_matrices(mat1, mat2);
    print_matrix(result);
    matrix_t* scaled_result = scale_matrix(result, 2);
    print_matrix(scaled_result);
    free(mat1);
    free(mat2);
    free(result);
    free(scaled_result);
    return 0;
}