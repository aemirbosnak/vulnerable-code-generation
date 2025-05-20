//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 10
#define MAX_COLS 10

typedef struct {
    int rows;
    int cols;
    int *data;
} Matrix;

Matrix *create_matrix(int rows, int cols) {
    Matrix *matrix = malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = malloc(sizeof(int) * rows * cols);
    return matrix;
}

void print_matrix(Matrix *matrix) {
    int i, j;
    for (i = 0; i < matrix->rows; i++) {
        for (j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i * matrix->cols + j]);
        }
        printf("\n");
    }
}

void multiply_matrices(Matrix *a, Matrix *b, Matrix *result) {
    int i, j, k;
    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < b->cols; j++) {
            int sum = 0;
            for (k = 0; k < a->cols; k++) {
                sum += a->data[i * a->cols + k] * b->data[k * b->cols + j];
            }
            result->data[i * result->cols + j] = sum;
        }
    }
}

int main() {
    Matrix *a = create_matrix(3, 4);
    Matrix *b = create_matrix(4, 3);
    Matrix *result = create_matrix(3, 3);

    // Initialize matrices
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            a->data[i * a->cols + j] = i * j;
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            b->data[i * b->cols + j] = i * j;
        }
    }

    // Multiply matrices
    multiply_matrices(a, b, result);

    // Print result
    print_matrix(result);

    return 0;
}