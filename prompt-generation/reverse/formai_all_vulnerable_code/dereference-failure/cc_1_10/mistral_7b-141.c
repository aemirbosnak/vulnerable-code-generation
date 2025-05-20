//MISTRAL-7B DATASET v1.0 Category: Matrix operations ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define PARANOID 1
#define MAX_MATRIX_SIZE 10
#define MATRIX_ELEM_TYPE int

typedef struct matrix_tag {
    size_t rows;
    size_t cols;
    MATRIX_ELEM_TYPE **data;
} Matrix;

// Check if given memory pointer is NULL
#ifdef PARANOID
#define CHECK_POINTER(ptr) if (ptr == NULL) { fprintf(stderr, "Fatal error: Invalid pointer\n"); exit(EXIT_FAILURE); }
#else
#define CHECK_POINTER(ptr)
#endif

Matrix *matrix_create(size_t rows, size_t cols) {
    Matrix *matrix;
    size_t i;

    CHECK_POINTER(matrix = malloc(sizeof(Matrix)));
    matrix->rows = rows;
    matrix->cols = cols;

    matrix->data = malloc(rows * sizeof(MATRIX_ELEM_TYPE *));
    for (i = 0; i < rows; ++i) {
        CHECK_POINTER(matrix->data[i] = calloc(cols, sizeof(MATRIX_ELEM_TYPE)));
    }

    return matrix;
}

void matrix_destroy(Matrix *matrix) {
    size_t i;

    for (i = 0; i < matrix->rows; ++i) {
        free(matrix->data[i]);
    }

    free(matrix->data);
    free(matrix);
}

MATRIX_ELEM_TYPE matrix_get(const Matrix *matrix, size_t row, size_t col) {
    CHECK_POINTER(matrix);
    CHECK_POINTER(matrix->data[row]);
    CHECK_POINTER(matrix->data[row] + col);

    return *(MATRIX_ELEM_TYPE *)(matrix->data[row] + col);
}

void matrix_set(Matrix *matrix, size_t row, size_t col, MATRIX_ELEM_TYPE value) {
    CHECK_POINTER(matrix);
    CHECK_POINTER(matrix->data[row]);
    CHECK_POINTER(matrix->data[row] + col);

    *(MATRIX_ELEM_TYPE *)(matrix->data[row] + col) = value;
}

Matrix *matrix_add(const Matrix *a, const Matrix *b) {
    Matrix *result;
    size_t rows = a->rows;
    size_t cols = a->cols;

    CHECK_POINTER(result = matrix_create(rows, cols));

    size_t i, j;
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            matrix_set(result, i, j, matrix_get(a, i, j) + matrix_get(b, i, j));
        }
    }

    return result;
}

void print_matrix(const Matrix *matrix) {
    size_t i, j;

    for (i = 0; i < matrix->rows; ++i) {
        for (j = 0; j < matrix->cols; ++j) {
            printf("%d ", matrix_get(matrix, i, j));
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    Matrix *a = matrix_create(3, 3);
    Matrix *b = matrix_create(3, 3);

    size_t i, j;

    // Initialize matrices
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            matrix_set(a, i, j, i + j);
            matrix_set(b, i, j, i - j);
        }
    }

    Matrix *sum = matrix_add(a, b);
    print_matrix(sum);

    // Free allocated memory
    matrix_destroy(a);
    matrix_destroy(b);
    matrix_destroy(sum);

    return EXIT_SUCCESS;
}