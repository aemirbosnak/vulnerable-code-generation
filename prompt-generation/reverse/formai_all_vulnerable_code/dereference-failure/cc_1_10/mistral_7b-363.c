//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    size_t rows;
    size_t cols;
    double** elements;
} matrix_t;

void matrix_init(matrix_t* mat, size_t rows, size_t cols) {
    mat->rows = rows;
    mat->cols = cols;

    mat->elements = (double**) malloc(rows * sizeof(double*));
    for (size_t i = 0; i < rows; i++) {
        mat->elements[i] = (double*) calloc(cols, sizeof(double));
    }
}

void matrix_print(const matrix_t* mat) {
    for (size_t i = 0; i < mat->rows; i++) {
        for (size_t j = 0; j < mat->cols; j++) {
            printf("%.2f ", mat->elements[i][j]);
        }
        printf("\n");
    }
}

void matrix_fill(matrix_t* mat, double value) {
    for (size_t i = 0; i < mat->rows; i++) {
        for (size_t j = 0; j < mat->cols; j++) {
            mat->elements[i][j] = value;
        }
    }
}

void matrix_sum(const matrix_t* a, const matrix_t* b, matrix_t* result) {
    result->rows = a->rows;
    result->cols = a->cols;

    result->elements = (double**) malloc(a->rows * sizeof(double*));
    for (size_t i = 0; i < a->rows; i++) {
        result->elements[i] = (double*) malloc(a->cols * sizeof(double));
    }

    for (size_t i = 0; i < a->rows; i++) {
        for (size_t j = 0; j < a->cols; j++) {
            result->elements[i][j] = a->elements[i][j] + b->elements[i][j];
        }
    }
}

void matrix_free(matrix_t* mat) {
    for (size_t i = 0; i < mat->rows; i++) {
        free(mat->elements[i]);
    }
    free(mat->elements);
}

int main() {
    matrix_t a, b, c;

    matrix_init(&a, 10, 10);
    matrix_init(&b, 10, 10);

    matrix_fill(&a, 1.0);
    matrix_fill(&b, 2.0);

    matrix_sum(&a, &b, &c);
    matrix_print(&c);

    matrix_free(&a);
    matrix_free(&b);
    matrix_free(&c);

    return EXIT_SUCCESS;
}