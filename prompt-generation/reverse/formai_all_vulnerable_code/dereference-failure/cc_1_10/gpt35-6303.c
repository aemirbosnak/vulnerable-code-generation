//FormAI DATASET v1.0 Category: Matrix operations ; Style: Ken Thompson
#include <stdio.h>

void printMatrix(int rows, int cols, int matrix[][cols]) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void scaleMatrix(int rows, int cols, int matrix[][cols], int scalar) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix[i][j] *= scalar;
        }
    }
}

void addMatrices(int rows, int cols, int matrixA[][cols], int matrixB[][cols]) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrixA[i][j] += matrixB[i][j];
        }
    }
}

int main() {

    int matrix1[3][3] = {{1, 2, 3},
                         {4, 5, 6},
                         {7, 8, 9}};
    int matrix2[3][3] = {{9, 8, 7},
                         {6, 5, 4},
                         {3, 2, 1}};

    printf("Matrix 1:\n");
    printMatrix(3, 3, matrix1);

    printf("Matrix 2:\n");
    printMatrix(3, 3, matrix2);

    printf("Scaling Matrix 1 by 2...\n");
    scaleMatrix(3, 3, matrix1, 2);

    printf("Matrix 1 after scaling:\n");
    printMatrix(3, 3, matrix1);

    printf("Adding Matrix 1 and Matrix 2...\n");
    addMatrices(3, 3, matrix1, matrix2);

    printf("Matrix 1 after addition:\n");
    printMatrix(3, 3, matrix1);

    return 0;
}