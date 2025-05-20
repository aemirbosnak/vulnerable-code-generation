//FormAI DATASET v1.0 Category: Matrix operations ; Style: complex
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double real;
    double imag;
} Complex;

typedef struct {
    Complex **data;
    size_t rows;
    size_t cols;
} Matrix;

Matrix *create_matrix(size_t rows, size_t cols)
{
    Matrix *matrix = malloc(sizeof(Matrix));

    matrix->rows = rows;
    matrix->cols = cols;

    matrix->data = malloc(sizeof(Complex *) * rows);

    for (size_t i = 0; i < rows; ++i) {
        matrix->data[i] = malloc(sizeof(Complex) * cols);
    }

    return matrix;
}

Matrix *matrix_add(Matrix *a, Matrix *b)
{
    Matrix *result = create_matrix(a->rows, a->cols);

    for (size_t i = 0; i < a->rows; ++i) {
        for (size_t j = 0; j < a->cols; ++j) {
            Complex sum = {
                .real = a->data[i][j].real + b->data[i][j].real,
                .imag = a->data[i][j].imag + b->data[i][j].imag,
            };

            result->data[i][j] = sum;
        }
    }

    return result;
}

Matrix *matrix_multiply(Matrix *a, Matrix *b)
{
    if (a->cols != b->rows) {
        return NULL;
    }

    Matrix *result = create_matrix(a->rows, b->cols);

    for (size_t i = 0; i < a->rows; ++i) {
        for (size_t j = 0; j < b->cols; ++j) {
            Complex sum = {0};

            for (size_t k = 0; k < a->cols; ++k) {
                sum.real += a->data[i][k].real * b->data[k][j].real -
                            a->data[i][k].imag * b->data[k][j].imag;

                sum.imag += a->data[i][k].real * b->data[k][j].imag +
                            a->data[i][k].imag * b->data[k][j].real;
            }

            result->data[i][j] = sum;
        }
    }

    return result;
}

void print_matrix(Matrix *matrix)
{
    for (size_t i = 0; i < matrix->rows; ++i) {
        for (size_t j = 0; j < matrix->cols; ++j) {
            printf("%g + %gi\t", matrix->data[i][j].real,
                   matrix->data[i][j].imag);
        }

        printf("\n");
    }
}

int main()
{
    Matrix *a = create_matrix(2, 2);
    a->data[0][0] = (Complex) {1, 2};
    a->data[0][1] = (Complex) {3, 4};
    a->data[1][0] = (Complex) {5, 6};
    a->data[1][1] = (Complex) {7, 8};

    Matrix *b = create_matrix(2, 2);
    b->data[0][0] = (Complex) {8, 7};
    b->data[0][1] = (Complex) {6, 5};
    b->data[1][0] = (Complex) {4, 3};
    b->data[1][1] = (Complex) {2, 1};

    Matrix *c = matrix_add(a, b);
    printf("a + b:\n");
    print_matrix(c);
    printf("\n");

    Matrix *d = matrix_multiply(a, b);
    printf("a * b:\n");
    print_matrix(d);
    printf("\n");

    return 0;
}