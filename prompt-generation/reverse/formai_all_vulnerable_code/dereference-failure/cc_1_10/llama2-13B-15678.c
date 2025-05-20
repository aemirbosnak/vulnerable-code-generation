//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 7

typedef struct {
    int rows;
    int cols;
    int *data;
} Matrix;

void print_matrix(Matrix *mat) {
    int i, j;
    for (i = 0; i < mat->rows; i++) {
        for (j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i * mat->cols + j]);
        }
        printf("\n");
    }
}

Matrix create_identity_matrix(int size) {
    Matrix mat = (Matrix) {
        .rows = size,
        .cols = size,
        .data = (int *)calloc(size * size, sizeof(int))
    };
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (i == j) {
                mat.data[i * size + j] = 1;
            } else {
                mat.data[i * size + j] = 0;
            }
        }
    }
    return mat;
}

Matrix multiply_matrices(Matrix *a, Matrix *b) {
    int i, j, k;
    Matrix c = (Matrix) {
        .rows = a->rows,
        .cols = b->cols,
        .data = (int *)calloc(a->rows * b->cols, sizeof(int))
    };
    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < b->cols; j++) {
            int sum = 0;
            for (k = 0; k < a->cols; k++) {
                sum += a->data[i * a->cols + k] * b->data[k * b->cols + j];
            }
            c.data[i * c.cols + j] = sum;
        }
    }
    return c;
}

int main() {
    Matrix a = create_identity_matrix(ROWS);
    Matrix b = create_identity_matrix(COLS);
    Matrix c = multiply_matrices(&a, &b);
    print_matrix(&c);
    return 0;
}