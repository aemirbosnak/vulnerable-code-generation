//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomMatrix(int rows, int cols, int matrix[rows][cols]) {
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrices(int rows1, int cols1, int rows2, int cols2, int matrix1[rows1][cols1], int matrix2[rows2][cols2], int result[rows1][cols2]) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int rows1, cols1, rows2, cols2;
    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    int matrix1[rows1][cols1];
    generateRandomMatrix(rows1, cols1, matrix1);
    printMatrix(rows1, cols1, matrix1);

    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &rows2, &cols2);
    int matrix2[rows2][cols2];
    generateRandomMatrix(rows2, cols2, matrix2);
    printMatrix(rows2, cols2, matrix2);

    if (cols1!= rows2) {
        printf("Error: The number of columns in the first matrix must be equal to the number of rows in the second matrix.\n");
        return 1;
    }

    int result[rows1][cols2];
    multiplyMatrices(rows1, cols1, rows2, cols2, matrix1, matrix2, result);
    printf("Product of the matrices:\n");
    printMatrix(rows1, cols2, result);

    return 0;
}