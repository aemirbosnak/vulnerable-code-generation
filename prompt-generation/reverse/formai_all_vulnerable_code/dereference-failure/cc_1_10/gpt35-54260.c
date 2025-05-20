//FormAI DATASET v1.0 Category: Matrix operations ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

// Function to print the matrix
void printMatrix(int **matrix) {
    printf("Matrix:\n");

    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

// Function to add two matrices
void addMatrix(int **matrix1, int **matrix2, int **result) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    printf("Addition of matrices successful!\n");
}

// Function to multiply two matrices
void multiplyMatrix(int **matrix1, int **matrix2, int **result) {
    int sum = 0;

    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            for(int k=0; k<ROWS; k++) {
                sum += matrix1[i][k] * matrix2[k][j];
            }

            result[i][j] = sum;
            sum = 0;
        }
    }

    printf("Multiplication of matrices successful!\n");
}

int main() {
    int **matrix1 = (int**) malloc(sizeof(int*) * ROWS);
    int **matrix2 = (int**) malloc(sizeof(int*) * ROWS);
    int **addResult = (int**) malloc(sizeof(int*) * ROWS);
    int **multiplyResult = (int**) malloc(sizeof(int*) * ROWS);

    for(int i=0; i<ROWS; i++) {
        matrix1[i] = (int*) malloc(sizeof(int) * COLS);
        matrix2[i] = (int*) malloc(sizeof(int) * COLS);
        addResult[i] = (int*) malloc(sizeof(int) * COLS);
        multiplyResult[i] = (int*) malloc(sizeof(int) * COLS);
    }

    // Initializing the matrices
    matrix1[0][0] = 1; matrix1[0][1] = 2; matrix1[0][2] = 3;
    matrix1[1][0] = 4; matrix1[1][1] = 5; matrix1[1][2] = 6;
    matrix1[2][0] = 7; matrix1[2][1] = 8; matrix1[2][2] = 9;

    matrix2[0][0] = 9; matrix2[0][1] = 8; matrix2[0][2] = 7;
    matrix2[1][0] = 6; matrix2[1][1] = 5; matrix2[1][2] = 4;
    matrix2[2][0] = 3; matrix2[2][1] = 2; matrix2[2][2] = 1;

    // Printing the matrices
    printMatrix(matrix1);
    printMatrix(matrix2);

    // Adding the matrices
    addMatrix(matrix1, matrix2, addResult);
    printMatrix(addResult);

    // Multiplying the matrices
    multiplyMatrix(matrix1, matrix2, multiplyResult);
    printMatrix(multiplyResult);

    return 0;
}