//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW_MAX 100
#define COL_MAX 100

typedef struct {
    int rows;
    int cols;
    int **matrix;
} matrix_t;

void init_matrix(matrix_t *mat, int rows, int cols) {
    mat->rows = rows;
    mat->cols = cols;
    mat->matrix = (int **)calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat->matrix[i] = (int *)calloc(cols, sizeof(int));
    }
}

void print_matrix(matrix_t *mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->matrix[i][j]);
        }
        printf("\n");
    }
}

void add_matrix(matrix_t *mat1, matrix_t *mat2) {
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            mat1->matrix[i][j] += mat2->matrix[i][j];
        }
    }
}

void multiply_matrix(matrix_t *mat1, matrix_t *mat2) {
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            int sum = 0;
            for (int k = 0; k < mat1->cols; k++) {
                sum += mat1->matrix[i][k] * mat2->matrix[k][j];
            }
            mat1->matrix[i][j] = sum;
        }
    }
}

int main() {
    matrix_t mat1, mat2, res;

    // Initialize matrices
    init_matrix(&mat1, 3, 4);
    init_matrix(&mat2, 4, 3);

    // Set matrix values
    mat1.matrix[0][0] = 1;
    mat1.matrix[0][1] = 2;
    mat1.matrix[0][2] = 3;
    mat1.matrix[1][0] = 4;
    mat1.matrix[1][1] = 5;
    mat1.matrix[1][2] = 6;
    mat1.matrix[2][0] = 7;
    mat1.matrix[2][1] = 8;
    mat1.matrix[2][2] = 9;

    mat2.matrix[0][0] = 10;
    mat2.matrix[0][1] = 11;
    mat2.matrix[0][2] = 12;
    mat2.matrix[1][0] = 13;
    mat2.matrix[1][1] = 14;
    mat2.matrix[1][2] = 15;
    mat2.matrix[2][0] = 16;
    mat2.matrix[2][1] = 17;
    mat2.matrix[2][2] = 18;

    // Add matrices
    add_matrix(&mat1, &mat2);

    // Print result
    print_matrix(&res);

    // Multiply matrices
    multiply_matrix(&mat1, &mat2);

    // Print result
    print_matrix(&res);

    return 0;
}