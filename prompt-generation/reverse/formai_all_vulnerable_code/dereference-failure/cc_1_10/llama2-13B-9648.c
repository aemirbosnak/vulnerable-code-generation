//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MATRIX_ROWS 10
#define MATRIX_COLS 10

typedef struct matrix {
    int rows;
    int cols;
    int **data;
} matrix_t;

void init_matrix(matrix_t *matrix) {
    matrix->rows = MATRIX_ROWS;
    matrix->cols = MATRIX_COLS;
    matrix->data = calloc(MATRIX_ROWS, sizeof(int *));
    for (int i = 0; i < MATRIX_ROWS; i++) {
        matrix->data[i] = calloc(MATRIX_COLS, sizeof(int));
    }
}

void free_matrix(matrix_t *matrix) {
    for (int i = 0; i < MATRIX_ROWS; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
}

void print_matrix(matrix_t *matrix) {
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

int add_matrices(matrix_t *matrix1, matrix_t *matrix2) {
    int result[MATRIX_ROWS][MATRIX_COLS];
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            result[i][j] = matrix1->data[i][j] + matrix2->data[i][j];
        }
    }
    return result;
}

int multiply_matrices(matrix_t *matrix1, matrix_t *matrix2) {
    int result[MATRIX_ROWS][MATRIX_COLS];
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            int sum = 0;
            for (int k = 0; k < MATRIX_COLS; k++) {
                sum += matrix1->data[i][k] * matrix2->data[k][j];
            }
            result[i][j] = sum;
        }
    }
    return result;
}

int main() {
    srand(time(NULL));

    matrix_t matrix1, matrix2, result;
    init_matrix(&matrix1);
    init_matrix(&matrix2);

    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            matrix1.data[i][j] = rand() % 10;
            matrix2.data[i][j] = rand() % 10;
        }
    }

    matrix_t *matrix_ptr1 = &matrix1;
    matrix_t *matrix_ptr2 = &matrix2;
    matrix_t *result_ptr = &result;

    // Add matrices
    matrix_t *sum = add_matrices(matrix_ptr1, matrix_ptr2);
    print_matrix(sum);

    // Multiply matrices
    matrix_t *product = multiply_matrices(matrix_ptr1, matrix_ptr2);
    print_matrix(product);

    free_matrix(sum);
    free_matrix(product);

    return 0;
}