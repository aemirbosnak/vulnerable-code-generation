//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 100

// Matrix operations
void matrix_add(int** mat1, int** mat2, int* size1, int* size2) {
    int i, j;
    for (i = 0; i < *size1; i++) {
        for (j = 0; j < *size2; j++) {
            mat1[i][j] += mat2[i][j];
        }
    }
}

void matrix_subtract(int** mat1, int** mat2, int* size1, int* size2) {
    int i, j;
    for (i = 0; i < *size1; i++) {
        for (j = 0; j < *size2; j++) {
            mat1[i][j] -= mat2[i][j];
        }
    }
}

void matrix_multiply(int** mat1, int** mat2, int* size1, int* size2) {
    int i, j, k;
    for (i = 0; i < *size1; i++) {
        for (j = 0; j < *size2; j++) {
            for (k = 0; k < *size1; k++) {
                mat1[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void matrix_transpose(int** mat, int* size) {
    int i, j;
    for (i = 0; i < *size; i++) {
        for (j = 0; j < *size; j++) {
            mat[j][i] = mat[i][j];
        }
    }
}

void print_matrix(int** mat, int* size) {
    int i, j;
    for (i = 0; i < *size; i++) {
        for (j = 0; j < *size; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int size1 = M, size2 = M;
    int** mat1 = malloc(size1 * sizeof(int*)), **mat2 = malloc(size2 * sizeof(int*)), **mat3 = malloc(size1 * sizeof(int*));
    for (int i = 0; i < size1; i++) {
        mat1[i] = malloc(size2 * sizeof(int));
        for (int j = 0; j < size2; j++) {
            mat1[i][j] = i * j;
        }
    }

    matrix_add(mat1, mat2, &size1, &size2);
    matrix_subtract(mat1, mat2, &size1, &size2);
    matrix_multiply(mat1, mat2, &size1, &size2);
    matrix_transpose(mat1, &size1);
    print_matrix(mat1, &size1);

    free(mat1);
    free(mat2);
    free(mat3);
    return 0;
}