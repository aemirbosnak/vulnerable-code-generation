//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

void main() {
    int a = 4, b = 3, c = 2, d = 5;
    int **matrixA = NULL, **matrixB = NULL, **matrixC = NULL;

    matrixA = (int**)malloc(a * sizeof(int*));
    for (int i = 0; i < a; i++) {
        matrixA[i] = (int*)malloc(b * sizeof(int));
    }

    matrixB = (int**)malloc(c * sizeof(int*));
    for (int i = 0; i < c; i++) {
        matrixB[i] = (int*)malloc(d * sizeof(int));
    }

    matrixC = (int**)malloc(a * sizeof(int*));
    for (int i = 0; i < a; i++) {
        matrixC[i] = (int*)malloc(b * sizeof(int));
    }

    // Matrix A elements
    matrixA[0][0] = 1;
    matrixA[0][1] = 2;
    matrixA[0][2] = 3;
    matrixA[1][0] = 4;
    matrixA[1][1] = 5;
    matrixA[1][2] = 6;

    // Matrix B elements
    matrixB[0][0] = 7;
    matrixB[0][1] = 8;
    matrixB[0][2] = 9;
    matrixB[1][0] = 10;
    matrixB[1][1] = 11;
    matrixB[1][2] = 12;

    // Matrix C elements
    matrixC[0][0] = matrixA[0][0] + matrixB[0][0];
    matrixC[0][1] = matrixA[0][1] + matrixB[0][1];
    matrixC[0][2] = matrixA[0][2] + matrixB[0][2];
    matrixC[1][0] = matrixA[1][0] + matrixB[1][0];
    matrixC[1][1] = matrixA[1][1] + matrixB[1][1];
    matrixC[1][2] = matrixA[1][2] + matrixB[1][2];

    // Display matrix C
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            printf("%d ", matrixC[i][j]);
        }
        printf("\n");
    }

    free(matrixA);
    free(matrixB);
    free(matrixC);
}