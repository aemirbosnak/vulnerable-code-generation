//MISTRAL-7B DATASET v1.0 Category: Bitwise operations ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct {
    size_t rows;
    size_t cols;
    uint8_t* data;
} matrix;

void init_matrix(matrix* mat, size_t rows, size_t cols) {
    mat->rows = rows;
    mat->cols = cols;
    mat->data = calloc(rows * cols, sizeof(uint8_t));
}

void free_matrix(matrix* mat) {
    free(mat->data);
}

bool is_valid_matrix(const matrix* mat) {
    return mat != NULL && mat->data != NULL;
}

void print_matrix(const matrix* mat) {
    if (!is_valid_matrix(mat)) {
        fprintf(stderr, "Invalid matrix\n");
        return;
    }

    size_t i, j;
    for (i = 0; i < mat->rows; i++) {
        for (j = 0; j < mat->cols; j++) {
            printf("%hhu ", mat->data[i * mat->cols + j]);
        }
        printf("\n");
    }
}

void bitwise_xor_matrix(const matrix* mat1, const matrix* mat2, matrix* result) {
    if (!is_valid_matrix(mat1) || !is_valid_matrix(mat2) || !result) {
        fprintf(stderr, "Invalid matrices or result\n");
        return;
    }

    if (mat1->rows != mat2->rows || mat1->cols != mat2->cols) {
        fprintf(stderr, "Matrices have different dimensions\n");
        return;
    }

    size_t i;
    result->rows = mat1->rows;
    result->cols = mat1->cols;
    result->data = calloc(result->rows * result->cols, sizeof(uint8_t));

    for (i = 0; i < result->rows * result->cols; i++) {
        result->data[i] = mat1->data[i] ^ mat2->data[i];
    }
}

int main() {
    size_t rows = 3, cols = 3;

    matrix mat1, mat2, result;
    init_matrix(&mat1, rows, cols);
    init_matrix(&mat2, rows, cols);

    // Fill matrices with data
    // ...

    print_matrix(&mat1);
    printf("Matrix 1:\n");
    print_matrix(&mat2);
    printf("Matrix 2:\n");

    bitwise_xor_matrix(&mat1, &mat2, &result);

    printf("Matrix 1 XOR Matrix 2:\n");
    print_matrix(&result);

    free_matrix(&mat1);
    free_matrix(&mat2);
    free_matrix(&result);

    return 0;
}