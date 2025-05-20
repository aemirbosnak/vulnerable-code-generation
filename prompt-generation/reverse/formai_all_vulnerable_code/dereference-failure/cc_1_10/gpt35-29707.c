//FormAI DATASET v1.0 Category: Matrix operations ; Style: expert-level
#include <stdio.h>

// function to print a matrix
void printMatrix(int rows, int cols, int matrix[rows][cols])
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// function to add two matrices
void addMatrix(int rows, int cols, int matrixA[rows][cols], int matrixB[rows][cols], int result[rows][cols])
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

// function to multiply two matrices
void multiplyMatrix(int rowsA, int colsA, int rowsB, int colsB, int matrixA[rowsA][colsA], int matrixB[rowsB][colsB], int result[rowsA][colsB])
{
    if(colsA != rowsB)
    {
        printf("Error: Matrix A columns must be equal to Matrix B rows.\n");
        return;
    }
    
    for(int i=0; i<rowsA; i++)
    {
        for(int j=0; j<colsB; j++)
        {
            int sum = 0;
            for(int k=0; k<colsA; k++)
            {
                sum += matrixA[i][k] * matrixB[k][j];
            }
            result[i][j] = sum;
        }
    }
}

int main()
{
    // create matrices
    int matrixA[3][2] = {{1, 2}, {3, 4}, {5, 6}};
    int matrixB[2][3] = {{7, 8, 9}, {10, 11, 12}};
    
    // print matrices
    printf("Matrix A:\n");
    printMatrix(3, 2, matrixA);
    printf("Matrix B:\n");
    printMatrix(2, 3, matrixB);
    
    // add matrices
    int matrixC[3][2];
    addMatrix(3, 2, matrixA, matrixA, matrixC);
    printf("Matrix A + A:\n");
    printMatrix(3, 2, matrixC);
    
    // multiply matrices
    int matrixD[3][3];
    multiplyMatrix(3, 2, 2, 3, matrixA, matrixB, matrixD);
    printf("Matrix A * B:\n");
    printMatrix(3, 3, matrixD);
    
    return 0;
}