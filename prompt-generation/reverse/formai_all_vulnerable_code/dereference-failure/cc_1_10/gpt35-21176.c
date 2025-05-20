//FormAI DATASET v1.0 Category: Matrix operations ; Style: creative
#include <stdio.h>

// Function to print the matrix
void printMatrix(int row, int col, int mat[row][col])
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrix(int row, int col, int mat1[row][col], int mat2[row][col], int result[row][col])
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrix(int row, int col, int mat1[row][col], int mat2[row][col], int result[row][col])
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrix(int row1, int col1, int mat1[row1][col1], int row2, int col2, int mat2[row2][col2], int result[row1][col2])
{
    if(col1 != row2)
    {
        printf("Multiplication not possible!");
        return;
    }
    
    for(int i=0; i<row1; i++)
    {
        for(int j=0; j<col2; j++)
        {
            result[i][j] = 0;
            for(int k=0; k<col1; k++)
            {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main()
{
    int mat1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int mat2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int result[3][3];
    
    printf("Matrix 1:\n");
    printMatrix(3, 3, mat1);
    
    printf("\nMatrix 2:\n");
    printMatrix(3, 3, mat2);
    
    printf("\nAddition of matrices:\n");
    addMatrix(3, 3, mat1, mat2, result);
    printMatrix(3, 3, result);
    
    printf("\nSubtraction of matrices:\n");
    subtractMatrix(3, 3, mat1, mat2, result);
    printMatrix(3, 3, result);
    
    printf("\nMultiplication of matrices:\n");
    multiplyMatrix(3, 3, mat1, 3, 3, mat2, result);
    printMatrix(3, 3, result);
    
    return 0;
}