//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Function to initialize a matrix with random values
void initializeMatrix(int matrix[][3], int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int matrix1[][3], int matrix2[][3], int matrix3[][3], int size) {
    int i, j, k;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            matrix3[i][j] = 0;
            for (k = 0; k < size; k++) {
                matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Main function
int main() {
    int matrix1[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int matrix3[][3] = {0};
    int size = 3;
    initializeMatrix(matrix1, size);
    initializeMatrix(matrix2, size);
    multiplyMatrices(matrix1, matrix2, matrix3, size);

    printf("Matrix 1:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }
    printf("Matrix 2:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }
    printf("Matrix 3 = Matrix 1 * Matrix 2:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix3[i][j]);
        }
        printf("\n");
    }

    return 0;
}