//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **data;
} matrix_t;

// Function to create a matrix
matrix_t* create_matrix(int rows, int cols) {
    matrix_t* mat = (matrix_t*)malloc(sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        mat->data[i] = (int*)malloc(cols * sizeof(int));
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
    matrix_t* result = create_matrix(rows1 + rows2, cols1 + cols2);
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            result->data[i][j] = mat1->data[i][j] + mat2->data[i][j];
        }
    }
    for (int i = rows1; i < rows1 + rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            result->data[i][j] = mat2->data[i][j];
        }
    }
    return result;
}

int main() {
    matrix_t* mat1 = create_matrix(3, 4);
    matrix_t* mat2 = create_matrix(2, 3);
    matrix_t* result = add_matrices(mat1, mat2);
    print_matrix(result);
    return 0;
}