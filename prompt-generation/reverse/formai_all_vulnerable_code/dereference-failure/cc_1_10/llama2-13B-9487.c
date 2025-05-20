//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 5 // size of the matrix

// Function to print a matrix
void print_matrix(float *matrix, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%.2f ", matrix[i * cols + j]);
        }
        printf("\n");
    }
}

// Function to perform matrix multiplication
float *matrix_multiply(float *a, float *b, int rows, int cols) {
    int i, j, k;
    float *c;

    // allocate memory for the result matrix
    c = (float *)calloc(rows, cols * sizeof(float));
    if (!c) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            for (k = 0; k < cols; k++) {
                c[i * cols + j] += a[i * rows + k] * b[k * cols + j];
            }
        }
    }

    return c;
}

// Function to perform matrix addition
float *matrix_add(float *a, float *b, int rows, int cols) {
    int i, j;
    float *c;

    // allocate memory for the result matrix
    c = (float *)calloc(rows, cols * sizeof(float));
    if (!c) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            c[i * cols + j] = a[i * rows + j] + b[i * rows + j];
        }
    }

    return c;
}

int main() {
    int i, j, k;
    float *a, *b, *c;

    // create a matrix A
    a = (float *)calloc(M, M * sizeof(float));
    for (i = 0; i < M; i++) {
        for (j = 0; j < M; j++) {
            a[i * M + j] = (i + j) % 2 == 0 ? 1.0f : 0.5f;
        }
    }

    // create a matrix B
    b = (float *)calloc(M, M * sizeof(float));
    for (i = 0; i < M; i++) {
        for (j = 0; j < M; j++) {
            b[i * M + j] = (i + j) % 3 == 0 ? 2.0f : 0.0f;
        }
    }

    // perform matrix multiplication
    c = matrix_multiply(a, b, M, M);
    if (!c) {
        printf("Matrix multiplication failed\n");
        return 1;
    }

    // print the result matrix
    print_matrix(c, M, M);

    // perform matrix addition
    c = matrix_add(a, b, M, M);
    if (!c) {
        printf("Matrix addition failed\n");
        return 1;
    }

    // print the result matrix
    print_matrix(c, M, M);

    free(a);
    free(b);
    free(c);

    return 0;
}