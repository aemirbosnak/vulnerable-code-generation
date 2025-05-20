//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MATRIX_ROWS 10
#define MATRIX_COLS 10

typedef struct {
    int rows;
    int cols;
    int **data;
} matrix_t;

matrix_t *create_matrix(void) {
    matrix_t *mat = (matrix_t *) malloc(sizeof(matrix_t));
    mat->rows = MATRIX_ROWS;
    mat->cols = MATRIX_COLS;
    mat->data = (int **) malloc(mat->rows * sizeof(int *));
    for (int i = 0; i < mat->rows; i++) {
        mat->data[i] = (int *) malloc(mat->cols * sizeof(int));
        for (int j = 0; j < mat->cols; j++) {
            mat->data[i][j] = rand() % 10;
        }
    }
    return mat;
}

void print_matrix(matrix_t *mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i][j]);
        }
        printf("\n");
    }
}

matrix_t *add_matrices(matrix_t *mat1, matrix_t *mat2) {
    matrix_t *result = create_matrix();
    for (int i = 0; i < mat1->rows; i++) {
        for (int j = 0; j < mat2->cols; j++) {
            result->data[i][j] = mat1->data[i][j] + mat2->data[i][j];
        }
    }
    return result;
}

int main(void) {
    srand(time(NULL));
    matrix_t *mat1 = create_matrix();
    matrix_t *mat2 = create_matrix();
    matrix_t *result = add_matrices(mat1, mat2);
    print_matrix(result);
    free(result);
    free(mat1);
    free(mat2);
    return 0;
}