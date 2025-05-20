//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **data;
} matrix_t;

// Function to create a new matrix
matrix_t* new_matrix(int rows, int cols) {
    matrix_t* mat = malloc(sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = malloc(sizeof(int*) * rows);
    for (int i = 0; i < rows; i++) {
        mat->data[i] = malloc(sizeof(int) * cols);
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
    matrix_t* result = new_matrix(mat1->rows, mat2->cols);
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            result->data[i][j] = mat1->data[i][j] + mat2->data[i][j];
        }
    }
    return result;
}

int main() {
    matrix_t* mat1 = new_matrix(5, 4);
    matrix_t* mat2 = new_matrix(4, 6);
    matrix_t* result = add_matrices(mat1, mat2);
    print_matrix(result);
    free(result);
    free(mat1);
    free(mat2);
    return 0;
}