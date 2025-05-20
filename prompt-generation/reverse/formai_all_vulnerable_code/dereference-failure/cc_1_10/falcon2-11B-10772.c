//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function to multiply two matrices
void matrixMultiplication(float **A, float **B, float **C) {
    int rowsA = A[0][0];
    int colsA = A[0][1];
    int rowsB = B[0][0];
    int colsB = B[0][1];
    int rowsC = C[0][0];
    int colsC = C[0][1];
    
    // Check if matrix dimensions are compatible
    if (colsA!= rowsB) {
        printf("Error: Matrices cannot be multiplied!\n");
        return;
    }
    
    // Perform matrix multiplication
    for (int i = 0; i < rowsC; i++) {
        for (int j = 0; j < colsC; j++) {
            float sum = 0;
            for (int k = 0; k < colsA; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
}

// Function to transpose a matrix
void matrixTranspose(float **A, float **B) {
    int rows = A[0][0];
    int cols = A[0][1];
    
    // Create transposed matrix
    B[0][0] = cols;
    B[0][1] = rows;
    
    // Copy elements from original matrix to transposed matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            B[i][j] = A[j][i];
        }
    }
}

// Function to calculate the determinant of a matrix
float matrixDeterminant(float **A, int rows) {
    float determinant = 1;
    for (int i = 0; i < rows; i++) {
        float temp = 0;
        for (int j = 0; j < rows; j++) {
            temp += A[j][i] * matrixDeterminant(A, rows - 1);
        }
        determinant *= temp;
    }
    return determinant;
}

// Function to calculate the inverse of a matrix
float **matrixInverse(float **A, int rows) {
    float determinant = matrixDeterminant(A, rows);
    float invDet = 1 / determinant;
    float **invA = (float **)malloc(rows * sizeof(float *));
    for (int i = 0; i < rows; i++) {
        invA[i] = (float *)malloc(rows * sizeof(float));
    }
    
    // Calculate inverse matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            float temp = 0;
            for (int k = 0; k < rows; k++) {
                temp += A[i][k] * invDet * A[j][k];
            }
            invA[i][j] = temp;
        }
    }
    
    return invA;
}

int main() {
    // Generate random matrices
    srand(time(NULL));
    int rowsA = 3;
    int colsA = 3;
    int rowsB = 3;
    int colsB = 4;
    int rowsC = 3;
    int colsC = 3;
    
    float **A = (float **)malloc(rowsA * sizeof(float *));
    float **B = (float **)malloc(rowsB * sizeof(float *));
    float **C = (float **)malloc(rowsC * sizeof(float *));
    
    for (int i = 0; i < rowsA; i++) {
        A[i] = (float *)malloc(colsA * sizeof(float));
        for (int j = 0; j < colsA; j++) {
            A[i][j] = (float)rand() / RAND_MAX;
        }
    }
    
    for (int i = 0; i < rowsB; i++) {
        B[i] = (float *)malloc(colsB * sizeof(float));
        for (int j = 0; j < colsB; j++) {
            B[i][j] = (float)rand() / RAND_MAX;
        }
    }
    
    for (int i = 0; i < rowsC; i++) {
        C[i] = (float *)malloc(colsC * sizeof(float));
        for (int j = 0; j < colsC; j++) {
            C[i][j] = 0;
        }
    }
    
    // Multiply matrices
    matrixMultiplication(A, B, C);
    
    // Transpose matrix
    matrixTranspose(C, A);
    
    // Calculate determinant
    float determinant = matrixDeterminant(A, rowsA);
    
    // Calculate inverse
    float **invA = matrixInverse(A, rowsA);
    
    printf("Original Matrix:\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            printf("%f ", A[i][j]);
        }
        printf("\n");
    }
    
    printf("Transposed Matrix:\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            printf("%f ", A[j][i]);
        }
        printf("\n");
    }
    
    printf("Determinant: %f\n", determinant);
    
    printf("Inverse Matrix:\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            printf("%f ", invA[i][j]);
        }
        printf("\n");
    }
    
    // Free memory
    for (int i = 0; i < rowsA; i++) {
        free(A[i]);
    }
    free(A);
    
    for (int i = 0; i < rowsB; i++) {
        free(B[i]);
    }
    free(B);
    
    for (int i = 0; i < rowsC; i++) {
        free(C[i]);
    }
    free(C);
    
    return 0;
}