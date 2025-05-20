//Falcon-180B DATASET v1.0 Category: Error handling ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int **data;
    int rows;
    int cols;
} Matrix;

Matrix *matrix_create(int rows, int cols) {
    Matrix *mat = malloc(sizeof(Matrix));
    mat->data = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat->data[i] = malloc(cols * sizeof(int));
    }
    mat->rows = rows;
    mat->cols = cols;
    return mat;
}

void matrix_destroy(Matrix *mat) {
    for (int i = 0; i < mat->rows; i++) {
        free(mat->data[i]);
    }
    free(mat->data);
    free(mat);
}

void matrix_print(Matrix *mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i][j]);
        }
        printf("\n");
    }
}

int matrix_add(Matrix *a, Matrix *b) {
    if (a->rows!= b->rows || a->cols!= b->cols) {
        fprintf(stderr, "Error: matrices have different dimensions.\n");
        return -1;
    }

    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            a->data[i][j] += b->data[i][j];
        }
    }

    return 0;
}

int matrix_multiply(Matrix *a, Matrix *b) {
    if (a->cols!= b->rows) {
        fprintf(stderr, "Error: matrices have incompatible dimensions.\n");
        return -1;
    }

    Matrix *c = matrix_create(a->rows, b->cols);

    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            for (int k = 0; k < a->cols; k++) {
                c->data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }

    matrix_destroy(a);
    matrix_destroy(b);

    return 0;
}

int main() {
    Matrix *a = matrix_create(2, 3);
    Matrix *b = matrix_create(3, 2);

    matrix_print(a);
    matrix_print(b);

    matrix_add(a, b);
    matrix_print(a);

    matrix_destroy(a);
    matrix_destroy(b);

    return 0;
}