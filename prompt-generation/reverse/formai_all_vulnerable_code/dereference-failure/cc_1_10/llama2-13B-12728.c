//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Function to perform matrix multiplication
void matrixMultiply(float *A, float *B, float *C, int m, int n) {
    int i, j, k;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                C[i * n + j] += A[i * m + k] * B[k * n + j];
            }
        }
    }
}

// Function to perform matrix inversion
float *matrixInvert(float *A, int m, int n) {
    int i, j;
    float *B = (float *)malloc(m * n * sizeof(float));
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            B[i * n + j] = A[i * m + j];
        }
    }
    return B;
}

int main() {
    float A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    float B[3][3] = {
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}
    };
    float C[3][3];

    // Perform matrix multiplication
    matrixMultiply(A, B, C, 3, 3);

    // Perform matrix inversion
    float *invA = matrixInvert(A, 3, 3);

    // Print the results
    printf("Matrix multiplication result:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%.2f ", C[i * 3 + j]);
        }
        printf("\n");
    }

    printf("Matrix inversion result:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%.2f ", invA[i * 3 + j]);
        }
        printf("\n");
    }

    free(C);
    free(invA);

    return 0;
}