//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to add two matrices
void addMatrices(int m, int n, int* A, int* B, int* C) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            C[i * n + j] = A[i * n + j] + B[i * n + j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int m, int n, int p, int* A, int* B, int* C) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                C[i * p + j] += A[i * n + k] * B[k * p + j];
            }
        }
    }
}

int main() {
    int m = 3, n = 3, p = 2;
    int* A = (int*)malloc(m * n * sizeof(int));
    int* B = (int*)malloc(p * n * sizeof(int));
    int* C = (int*)malloc(m * p * sizeof(int));
    
    // Initialize matrices A and B with random values
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            A[i * n + j] = rand() % 100;
            B[i * n + j] = rand() % 100;
        }
    }
    
    // Add matrices A and B
    addMatrices(m, n, A, B, C);
    
    // Multiply matrices A and B
    multiplyMatrices(m, n, p, A, B, C);
    
    // Print the resulting matrix
    printf("Resulting matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            printf("%d ", C[i * p + j]);
        }
        printf("\n");
    }
    
    // Free memory
    free(A);
    free(B);
    free(C);
    
    return 0;
}