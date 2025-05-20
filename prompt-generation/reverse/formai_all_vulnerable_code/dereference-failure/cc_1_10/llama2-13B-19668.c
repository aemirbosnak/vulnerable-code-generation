//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    int rows;
    int cols;
    int *data;
} matrix_t;

matrix_t *create_matrix(int rows, int cols) {
    matrix_t *mat = malloc(sizeof(matrix_t));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = malloc(sizeof(int) * rows * cols);
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

void add_matrices(matrix_t *mat1, matrix_t *mat2, matrix_t *result) {
    int i, j;
    for (i = 0; i < mat1->rows; i++) {
        for (j = 0; j < mat2->cols; j++) {
            result->data[i * result->cols + j] = mat1->data[i * mat1->cols + j] + mat2->data[i * mat2->cols + j];
        }
    }
}

void multiply_matrices(matrix_t *mat1, matrix_t *mat2, matrix_t *result) {
    int i, j, k;
    for (i = 0; i < mat1->rows; i++) {
        for (j = 0; j < mat2->cols; j++) {
            int sum = 0;
            for (k = 0; k < mat1->cols; k++) {
                sum += mat1->data[i * mat1->cols + k] * mat2->data[k * mat2->cols + j];
            }
            result->data[i * result->cols + j] = sum;
        }
    }
}

int main() {
    matrix_t *mat1, *mat2, *result;

    // Create matrices
    mat1 = create_matrix(5, 3);
    mat2 = create_matrix(3, 4);
    result = create_matrix(5, 4);

    // Fill matrices with data
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            mat1->data[i * mat1->cols + j] = i * j;
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            mat2->data[i * mat2->cols + j] = i * j + 1;
        }
    }

    // Add matrices
    add_matrices(mat1, mat2, result);

    // Print result
    print_matrix(result);

    // Multiply matrices
    multiply_matrices(mat1, mat2, result);

    // Print result
    print_matrix(result);

    return 0;
}