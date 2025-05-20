//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATRIX_ROWS 4
#define MATRIX_COLS 4

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int **matrix;
} matrix_t;

// Function to initialize a matrix
matrix_t *init_matrix(int rows, int cols) {
    matrix_t *mat = (matrix_t *)malloc(sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->matrix = (int **)malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++) {
        mat->matrix[i] = (int *)malloc(sizeof(int) * cols);
        for (int j = 0; j < cols; j++) {
            mat->matrix[i][j] = rand() % 10;
        }
    }
    return mat;
}

// Function to perform a matrix multiplication
matrix_t *matrix_mult(matrix_t *a, matrix_t *b) {
    matrix_t *res = (matrix_t *)malloc(sizeof(matrix_t));
    res->rows = a->rows * b->cols;
    res->cols = a->cols * b->rows;
    res->matrix = (int **)malloc(sizeof(int *) * res->rows);
    for (int i = 0; i < res->rows; i++) {
        res->matrix[i] = (int *)malloc(sizeof(int) * res->cols);
        for (int j = 0; j < res->cols; j++) {
            int sum = 0;
            for (int k = 0; k < a->rows; k++) {
                for (int l = 0; l < b->cols; l++) {
                    sum += a->matrix[k][l] * b->matrix[l][j];
                }
            }
            res->matrix[i][j] = sum;
        }
    }
    return res;
}

// Function to perform a matrix addition
matrix_t *matrix_add(matrix_t *a, matrix_t *b) {
    matrix_t *res = (matrix_t *)malloc(sizeof(matrix_t));
    res->rows = a->rows;
    res->cols = a->cols;
    res->matrix = (int **)malloc(sizeof(int *) * res->rows);
    for (int i = 0; i < res->rows; i++) {
        res->matrix[i] = (int *)malloc(sizeof(int) * res->cols);
        for (int j = 0; j < res->cols; j++) {
            res->matrix[i][j] = a->matrix[i][j] + b->matrix[i][j];
        }
    }
    return res;
}

int main() {
    matrix_t *a = init_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *b = init_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t *c = matrix_mult(a, b);
    matrix_t *d = matrix_add(a, b);

    // Print the matrices
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            printf("%d ", c->matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            printf("%d ", d->matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}