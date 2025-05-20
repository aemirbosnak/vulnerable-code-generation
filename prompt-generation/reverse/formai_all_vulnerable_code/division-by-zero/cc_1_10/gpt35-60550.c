//FormAI DATASET v1.0 Category: Matrix operations ; Style: multivariable
#include <stdio.h>

// Function to initialize matrix with random values
void initMatrix(int m[10][10], int rows, int columns)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            m[i][j] = rand() % (rows * columns);
        }
    }
}

// Function to print matrix
void printMatrix(int m[10][10], int rows, int columns)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrix(int a[10][10], int b[10][10], int c[10][10], int rows, int columns)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrix(int a[10][10], int b[10][10], int c[10][10], int rows, int columns, int k)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            c[i][j] = 0;
            for (int p = 0; p < columns; ++p)
            {
                c[i][j] += a[i][p] * b[p][j];
            }
        }
    }
}

int main()
{
    int a[10][10], b[10][10], c[10][10];
    int rowsA, columnsA, rowsB, columnsB;

    printf("Enter number of rows and columns for matrix A: ");
    scanf("%d %d", &rowsA, &columnsA);

    printf("Enter number of rows and columns for matrix B: ");
    scanf("%d %d", &rowsB, &columnsB);

    if (columnsA != rowsB)
    {
        printf("Error: Number of columns in matrix A must be equal to number of rows in matrix B");
        return 0;
    }

    printf("Initializing matrix A...\n");
    initMatrix(a, rowsA, columnsA);
    printf("Matrix A:\n");
    printMatrix(a, rowsA, columnsA);

    printf("Initializing matrix B...\n");
    initMatrix(b, rowsB, columnsB);
    printf("Matrix B:\n");
    printMatrix(b, rowsB, columnsB);

    printf("Addition of matrix A and matrix B:\n");
    addMatrix(a, b, c, rowsA, columnsA);
    printMatrix(c, rowsA, columnsA);

    printf("Multiplication of matrix A and matrix B:\n");
    multiplyMatrix(a, b, c, rowsA, columnsA, columnsB);
    printMatrix(c, rowsA, columnsB);

    return 0;
}