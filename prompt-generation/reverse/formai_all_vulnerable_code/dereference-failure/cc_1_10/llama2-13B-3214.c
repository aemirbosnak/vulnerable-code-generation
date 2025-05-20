//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 4 // size of the matrix
#define N 3 // number of elements in each row

// function to print a matrix
void print_matrix(int matrix[M][N]) {
    int i, j;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// function to multiply two matrices
int matrix_multiply(int matrix1[M][N], int matrix2[M][N], int result[M][N]) {
    int i, j, k;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            int sum = 0;
            for (k = 0; k < M; k++) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = sum;
        }
    }
    return 0;
}

int main() {
    int matrix1[M][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int matrix2[M][N] = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}
    };

    int result[M][N] = {0};

    matrix_multiply(matrix1, matrix2, result);

    print_matrix(result);

    return 0;
}