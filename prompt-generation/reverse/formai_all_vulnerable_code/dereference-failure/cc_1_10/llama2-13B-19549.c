//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

// Matrix operations

// Matrix multiplication
void mat_mult(double **A, double **B, double **C) {
    int i, j, k;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Matrix addition
void mat_add(double **A, double **B, double **C) {
    int i, j, k;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                C[i][j] = A[i][k] + B[i][k];
            }
        }
    }
}

// Matrix transpose
void mat_transpose(double **A, double **B) {
    int i, j, k;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                B[j][k] = A[i][k];
            }
        }
    }
}

int main() {
    double A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    double B[3][3] = {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}};
    double C[3][3];

    // Matrix multiplication
    mat_mult(A, B, C);

    // Matrix addition
    mat_add(A, B, C);

    // Matrix transpose
    mat_transpose(A, C);

    // Print the results
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%.2f ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}