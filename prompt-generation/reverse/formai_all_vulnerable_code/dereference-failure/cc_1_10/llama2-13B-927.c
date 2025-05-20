//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define M 10 // number of matrices
#define N 5 // number of columns in each matrix
#define MATRIX_SIZE (M * N) // total number of elements in each matrix

typedef struct {
    int *data; // matrix data
    int rows; // number of rows
    int cols; // number of columns
} matrix_t;

matrix_t *create_matrix(int rows, int cols) {
    matrix_t *mat = (matrix_t *)malloc(sizeof(matrix_t));
    mat->data = (int *)malloc(cols * sizeof(int));
    mat->rows = rows;
    mat->cols = cols;
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

void add_matrices(matrix_t *a, matrix_t *b, matrix_t *res) {
    int i, j, k;
    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < a->cols; j++) {
            for (k = 0; k < b->cols; k++) {
                res->data[i * res->cols + j + k] = a->data[i * a->cols + j] + b->data[i * b->cols + k];
            }
        }
    }
}

int main() {
    srand(time(NULL)); // initialize random number generator

    // create two random matrices
    matrix_t *a = create_matrix(5, 3);
    matrix_t *b = create_matrix(4, 4);

    // fill matrices with random numbers
    int i, j;
    for (i = 0; i < a->rows; i++) {
        for (j = 0; j < a->cols; j++) {
            a->data[i * a->cols + j] = rand() % 10;
        }
    }
    for (i = 0; i < b->rows; i++) {
        for (j = 0; j < b->cols; j++) {
            b->data[i * b->cols + j] = rand() % 10;
        }
    }

    // add matrices
    matrix_t *res = create_matrix(a->rows, a->cols);
    add_matrices(a, b, res);

    // print result
    print_matrix(res);

    // free memory
    free(res->data);
    free(res);
    free(a->data);
    free(a);
    free(b->data);
    free(b);

    return 0;
}