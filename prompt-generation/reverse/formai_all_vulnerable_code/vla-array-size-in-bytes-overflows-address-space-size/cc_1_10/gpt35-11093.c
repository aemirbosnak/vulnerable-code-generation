//FormAI DATASET v1.0 Category: Matrix operations ; Style: ultraprecise
/*
* This program demonstrates some of the basic math functions that can be performed on matrices using C language.
* The program requires user input for the matrix dimensions, the elements of the matrix, and the operation to be performed.
* Available operations are matrix addition, matrix subtraction, scalar multiplication, and matrix multiplication.
*/

#include <stdio.h>

// Function prototypes
void readMatrix(int row, int col, int matrix[row][col]);
void printMatrix(int row, int col, int matrix[row][col]);
void addMatrix(int row, int col, int matrix1[row][col], int matrix2[row][col], int result[row][col]);
void subtractMatrix(int row, int col, int matrix1[row][col], int matrix2[row][col], int result[row][col]);
void multiplyMatrix(int row1, int col1, int matrix1[row1][col1], int row2, int col2, int matrix2[row2][col2], int result[row1][col2]);
void scalarMulMatrix(int row, int col, int matrix[row][col], int scalar, int result[row][col]);

int main()
{
    int row1, row2, col1, col2, scalar, option;
    
    // Reading matrix dimensions and scalar value from user
    printf("Enter the number of rows and columns of first matrix:\n");
    scanf("%d%d", &row1, &col1);
    printf("Enter the number of rows and columns of second matrix:\n");
    scanf("%d%d", &row2, &col2);
    printf("Enter a scalar value for arithmetic operations on matrix:\n");
    scanf("%d", &scalar);

    if (col1!=row2)
    {
        printf("Cannot perform matrix multiplication. The number of columns of matrix 1 and rows of matrix 2 are not equal.\n");
        return 0;
    }

    // Creating matrices
    int matrix1[row1][col1], matrix2[row2][col2], result[row1][col2];

    // Reading matrix elements from user input
    printf("Enter elements of matrix 1:\n");
    readMatrix(row1, col1, matrix1);
    printf("Enter elements of matrix 2:\n");
    readMatrix(row2, col2, matrix2);
    
    // Display menu for operations
    printf("Enter 1 for matrix addition.\n");
    printf("Enter 2 for matrix subtraction.\n");
    printf("Enter 3 for matrix multiplication.\n");
    printf("Enter 4 for scalar multiplication.\n");

    // Reading option from user input
    scanf("%d", &option);

    // Performing matrix operations based on user choice
    switch (option)
    {
        case 1:
            addMatrix(row1, col1, matrix1, matrix2, result);
            break;
        case 2:
            subtractMatrix(row1, col1, matrix1, matrix2, result);
            break;
        case 3:
            multiplyMatrix(row1, col1, matrix1, row2, col2, matrix2, result);
            break;
        case 4:
            scalarMulMatrix(row1, col1, matrix1, scalar, result);
            break;
        default:
            printf("Invalid choice. Terminate.");
            return 0;
    }

    // Display the result of matrix operation
    printf("The result of the operation is:\n");
    printMatrix(row1, col2, result);

    return 0;
}

// Function to read matrix elements from user input
void readMatrix(int row, int col, int matrix[row][col])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print matrix elements
void printMatrix(int row, int col, int matrix[row][col])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrix(int row, int col, int matrix1[row][col], int matrix2[row][col], int result[row][col])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrix(int row, int col, int matrix1[row][col], int matrix2[row][col], int result[row][col])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrix(int row1, int col1, int matrix1[row1][col1], int row2, int col2, int matrix2[row2][col2], int result[row1][col2])
{
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < col1; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Function to multiply a matrix by a scalar value
void scalarMulMatrix(int row, int col, int matrix[row][col], int scalar, int result[row][col])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result[i][j] = matrix[i][j] * scalar;
        }
    }
}