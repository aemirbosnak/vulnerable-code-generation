//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 5 // size of the matrix
#define N 3 // size of the vector

// function to print the matrix
void print_matrix(float *matrix, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%.2f ", matrix[i * cols + j]);
        }
        printf("\n");
    }
}

// function to multiply two matrices
float *multiply_matrices(float *matrix1, float *matrix2, int rows1, int cols1, int rows2, int cols2) {
    int i, j, k;
    float *result = (float *)malloc(rows1 * cols2 * sizeof(float));
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            for (k = 0; k < cols1; k++) {
                result[i * cols2 + j] += matrix1[i * cols1 + k] * matrix2[k * cols2 + j];
            }
        }
    }
    return result;
}

// function to add two vectors
float *add_vectors(float *vector1, float *vector2, int size) {
    int i;
    float *result = (float *)malloc(size * sizeof(float));
    for (i = 0; i < size; i++) {
        result[i] = vector1[i] + vector2[i];
    }
    return result;
}

int main() {
    // define the matrices
    float matrix1[M][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    float matrix2[M][N] = {{10, 20, 30}, {40, 50, 60}, {70, 80, 90}};
    float matrix3[M][N] = {{100, 200, 300}, {400, 500, 600}, {700, 800, 900}};

    // define the vectors
    float vector1[N] = {1, 2, 3};
    float vector2[N] = {4, 5, 6};

    // perform matrix operations
    float *result1 = multiply_matrices(matrix1, matrix2, M, N, M, N);
    print_matrix(result1, M, N);

    float *result2 = add_vectors(vector1, vector2, N);
    print_matrix(result2, N, 1);

    // free the memory
    free(result1);
    free(result2);

    return 0;
}