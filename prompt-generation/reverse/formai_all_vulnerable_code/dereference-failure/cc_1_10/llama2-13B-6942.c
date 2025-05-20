//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATRIX_ROWS 4
#define MATRIX_COLS 4

typedef struct {
    int rows;
    int cols;
    int **data;
} matrix_t;

// Function to initialize a matrix
matrix_t *init_matrix(int rows, int cols) {
    matrix_t *mat = (matrix_t *) malloc(sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (int **) malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat->data[i] = (int *) malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            mat->data[i][j] = rand() % 10;
        }
    }
    return mat;
}

// Function to perform matrix multiplication
matrix_t *mult_matrices(matrix_t *mat1, matrix_t *mat2) {
    matrix_t *result = (matrix_t *) malloc(mat1->rows * mat2->cols * sizeof(int));
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            int sum = 0;
            for (int k = 0; k < mat1->cols; k++) {
                sum += mat1->data[i][k] * mat2->data[k][j];
            }
            result->data[i * mat2->cols + j] = sum;
        }
    }
    return result;
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

int main() {
    matrix_t *mat1 = init_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *mat2 = init_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *result = mult_matrices(mat1, mat2);
    print_matrix(result);
    free(result);
    free(mat1);
    free(mat2);
    return 0;
}