//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct matrix {
    int rows;
    int cols;
    int *data;
} matrix_t;

matrix_t *create_matrix(int rows, int cols) {
    matrix_t *mat = (matrix_t *)malloc(sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (int *)malloc(sizeof(int) * rows * cols);
    return mat;
}

void print_matrix(matrix_t *mat) {
    int i, j;
    for (i = 0; i < mat->rows; i++) {
        for (j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i * mat->cols + j]);
        }
        printf("\n");
    }
}

void add_matrix(matrix_t *mat1, matrix_t *mat2) {
    int i, j;
    for (i = 0; i < mat1->rows; i++) {
        for (j = 0; j < mat2->cols; j++) {
            mat1->data[i * mat1->cols + j] += mat2->data[j * mat2->rows + i];
        }
    }
}

void multiply_matrix(matrix_t *mat1, matrix_t *mat2) {
    int i, j, k;
    for (i = 0; i < mat1->rows; i++) {
        for (j = 0; j < mat2->cols; j++) {
            int sum = 0;
            for (k = 0; k < mat2->rows; k++) {
                sum += mat1->data[i * mat1->cols + k] * mat2->data[k * mat2->cols + j];
            }
            mat1->data[i * mat1->cols + j] = sum;
        }
    }
}

int main() {
    matrix_t *mat1 = create_matrix(5, 5);
    matrix_t *mat2 = create_matrix(3, 3);
    matrix_t *mat3 = create_matrix(5, 3);

    // Initialize matrix 1
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            mat1->data[i * 5 + j] = i * j;
        }
    }

    // Initialize matrix 2
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mat2->data[i * 3 + j] = i * j;
        }
    }

    // Initialize matrix 3
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            mat3->data[i * 3 + j] = i * j;
        }
    }

    // Add matrices
    add_matrix(mat1, mat2);

    // Multiply matrices
    multiply_matrix(mat1, mat3);

    // Print results
    print_matrix(mat1);

    return 0;
}