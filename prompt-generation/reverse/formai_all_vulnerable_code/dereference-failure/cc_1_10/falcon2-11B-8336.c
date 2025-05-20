//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Function to print a matrix
void printMatrix(int matrix[][2], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

// Function to add two matrices
int addMatrices(int matrix1[][2], int matrix2[][2], int rows, int cols)
{
    int sum[rows][cols];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return sum;
}

// Function to multiply two matrices
int multiplyMatrices(int matrix1[][2], int matrix2[][2], int rows, int cols)
{
    int result[rows][cols];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int sum = 0;
            for (int k = 0; k < cols; k++)
            {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = sum;
        }
    }
    return result;
}

int main()
{
    int matrix1[2][2] = {{1, 2}, {3, 4}};
    int matrix2[2][2] = {{5, 6}, {7, 8}};

    int result = addMatrices(matrix1, matrix2, 2, 2);
    printf("Addition of matrices:\n");
    printMatrix(result, 2, 2);

    result = multiplyMatrices(matrix1, matrix2, 2, 2);
    printf("Multiplication of matrices:\n");
    printMatrix(result, 2, 2);

    return 0;
}