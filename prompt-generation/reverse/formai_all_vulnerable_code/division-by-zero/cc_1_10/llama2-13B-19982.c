//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 5
#define N 3

int main() {
    int i, j, k;
    char matrix[M][N];

    // Initialize matrices
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            matrix[i][j] = i * j;
        }
    }

    // Matrix addition
    matrix[0][1] = 0;
    matrix[1][0] = 0;
    matrix[1][2] = 1;
    matrix[2][1] = 1;
    matrix[2][2] = 2;
    matrix[3][1] = 2;
    matrix[3][2] = 3;

    // Matrix multiplication
    matrix[0][1] = matrix[0][0] * matrix[1][0] + matrix[0][1] * matrix[1][1];
    matrix[0][2] = matrix[0][0] * matrix[1][2] + matrix[0][1] * matrix[1][0];
    matrix[1][0] = matrix[0][0] * matrix[1][0] + matrix[0][1] * matrix[1][1];
    matrix[1][1] = matrix[0][0] * matrix[1][1] + matrix[0][1] * matrix[1][0];
    matrix[1][2] = matrix[0][0] * matrix[1][2] + matrix[0][1] * matrix[1][0];

    // Matrix transpose
    for (j = 0; j < N; j++) {
        for (i = 0; i < M; i++) {
            matrix[i][j] = matrix[j][i];
        }
    }

    // Matrix inversion
    matrix[0][0] = 1 / (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
    matrix[1][0] = -matrix[0][1] * matrix[1][0];
    matrix[1][1] = -matrix[0][0] * matrix[1][1];

    // Print matrices
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}