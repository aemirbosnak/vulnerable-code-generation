//FormAI DATASET v1.0 Category: Matrix operations ; Style: genious
#include <stdio.h>

// Function to print a given matrix
void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices of given size
void addMatrices(int rows, int cols, int a[rows][cols], int b[rows][cols], int result[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Function to multiply two matrices of given size
void multiplyMatrices(int rows1, int cols1, int a[rows1][cols1], int rows2, int cols2, int b[rows2][cols2], int result[rows1][cols2]) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    // Define two matrices of size 2x2
    int matrix1[2][2] = {{1, 2}, {3, 4}};
    int matrix2[2][2] = {{5, 6}, {7, 8}};

    // Define a matrix to hold the sum of the two matrices
    int sum[2][2];

    // Define a matrix to hold the product of the two matrices
    int product[2][2];

    // Add the two matrices and store the result in the sum matrix
    addMatrices(2, 2, matrix1, matrix2, sum);

    printf("The sum of the matrices is:\n");
    printMatrix(2, 2, sum);

    // Multiply the two matrices and store the result in the product matrix
    multiplyMatrices(2, 2, matrix1, 2, 2, matrix2, product);

    printf("The product of the matrices is:\n");
    printMatrix(2, 2, product);

    return 0;
}