//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Matrix Operations Extravaganza!

// Define some constants and function prototypes
#define MAGIC_NUMBER 42
#define MATRIX_ROWS 10
#define MATRIX_COLS 5
#define MATRIX_INIT_VAL 0

typedef struct {
    int rows;
    int cols;
    int* data;
} matrix_t;

matrix_t* create_matrix(int rows, int cols);
void print_matrix(matrix_t* matrix);
void add_matrices(matrix_t* matrix1, matrix_t* matrix2);
void multiply_matrices(matrix_t* matrix1, matrix_t* matrix2);

int main() {
    matrix_t* matrix1 = create_matrix(MATRIX_ROWS, MATRIX_COLS);
    matrix_t* matrix2 = create_matrix(MATRIX_ROWS, MATRIX_COLS);

    // Initialize matrix1 with some magic numbers
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLS; j++) {
            matrix1->data[i * MATRIX_COLS + j] = MAGIC_NUMBER;
        }
    }

    // Print matrix1
    print_matrix(matrix1);

    // Add matrix1 and matrix2 element-wise
    add_matrices(matrix1, matrix2);

    // Print matrix1 again
    print_matrix(matrix1);

    // Multiply matrix1 and matrix2 element-wise
    multiply_matrices(matrix1, matrix2);

    // Print matrix1 again
    print_matrix(matrix1);

    return 0;
}

// Functions

matrix_t* create_matrix(int rows, int cols) {
    matrix_t* matrix = (matrix_t*) malloc(sizeof(matrix_t));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (int*) malloc(sizeof(int) * rows * cols);
    return matrix;
}

void print_matrix(matrix_t* matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i * matrix->cols + j]);
        }
        printf("\n");
    }
}

void add_matrices(matrix_t* matrix1, matrix_t* matrix2) {
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix2->cols; j++) {
            matrix1->data[i * matrix1->cols + j] += matrix2->data[i * matrix2->cols + j];
        }
    }
}

void multiply_matrices(matrix_t* matrix1, matrix_t* matrix2) {
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix2->cols; j++) {
            int sum = 0;
            for (int k = 0; k < matrix2->rows; k++) {
                sum += matrix1->data[i * matrix1->cols + k] * matrix2->data[k * matrix2->cols + j];
            }
            matrix1->data[i * matrix1->cols + j] = sum;
        }
    }
}