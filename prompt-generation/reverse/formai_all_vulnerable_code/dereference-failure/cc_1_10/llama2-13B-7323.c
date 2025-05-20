//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 5 // number of rows in the matrices
#define N 6 // number of columns in the matrices

// function to print a matrix
void print_matrix(float *matrix, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%.2f ", matrix[i * cols + j]);
        }
        printf("\n");
    }
}

// function to add two matrices
float *add_matrices(float *matrix1, float *matrix2, int rows, int cols) {
    int i, j;
    float *result = (float *)malloc(rows * cols * sizeof(float));
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[i * cols + j] = matrix1[i * cols + j] + matrix2[i * cols + j];
        }
    }
    return result;
}

// function to multiply a matrix by a scalar
float *scale_matrix(float *matrix, int rows, int cols, float scale) {
    int i, j;
    float *result = (float *)malloc(rows * cols * sizeof(float));
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[i * cols + j] = matrix[i * cols + j] * scale;
        }
    }
    return result;
}

// function to transpose a matrix
float *transpose_matrix(float *matrix, int rows, int cols) {
    int i, j;
    float *result = (float *)malloc(rows * cols * sizeof(float));
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[i * cols + j] = matrix[j * rows + i];
        }
    }
    return result;
}

int main() {
    float matrix1[M][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    float matrix2[M][N] = {{10, 20, 30}, {40, 50, 60}, {70, 80, 90}};
    float matrix3[M][N] = {{100, 200, 300}, {400, 500, 600}, {700, 800, 900}};
    float scale = 2;

    // add two matrices
    float *result = add_matrices(matrix1, matrix2, M, N);
    print_matrix(result, M, N);

    // scale a matrix
    result = scale_matrix(matrix1, M, N, scale);
    print_matrix(result, M, N);

    // transpose a matrix
    result = transpose_matrix(matrix1, M, N);
    print_matrix(result, N, M);

    // free memory
    free(result);

    return 0;
}