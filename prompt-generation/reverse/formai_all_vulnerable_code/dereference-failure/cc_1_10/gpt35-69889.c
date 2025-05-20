//FormAI DATASET v1.0 Category: Matrix operations ; Style: recursive
#include <stdio.h>

// function to print matrix
// m is the matrix and rows and cols are the dimensions of the matrix
void printMatrix(int m[][10], int rows, int cols)
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

// function to add two matrices
// m1, m2 and result are the matrices to be added
// rows and cols are the dimensions of the matrices
void addMatrices(int m1[][10], int m2[][10], int result[][10], int rows, int cols)
{
    if(rows==0 || cols==0)
        return;
    else
    {
        result[rows-1][cols-1] = m1[rows-1][cols-1] + m2[rows-1][cols-1];
        addMatrices(m1, m2, result, rows-1, cols);
        addMatrices(m1, m2, result, rows, cols-1);
    }
}

// function to multiply two matrices recursively
// m1, m2 and result are the matrices to be multiplied
// r1, c1 and r2, c2 are the dimensions of the matrices
void multiplyMatrices(int m1[][10], int m2[][10], int result[][10], int r1, int c1, int r2, int c2)
{
    if(c1 != r2)
        return;
    else if(r2==0 || c2==0)
        return;
    else
    {
        int sum=0;
        for(int i=0; i<c1; i++)
        {
            sum += m1[r1][i] * m2[i][c2-1];
        }
        result[r1][c2-1] = sum;
        multiplyMatrices(m1, m2, result, r1, c1, r2-1, c2);
        multiplyMatrices(m1, m2, result, r1, c1, r2, c2-1);
    }
}

int main()
{
    int m1[10][10], m2[10][10], add[10][10], mul[10][10];
    int r1, c1, r2, c2;

    // asking user for dimensions of the first matrix
    printf("Enter rows & columns of the first matrix: ");
    scanf("%d %d", &r1, &c1);

    // taking input for the first matrix
    printf("Enter elements of the first matrix:\n");
    for(int i=0; i<r1; i++)
    {
        for(int j=0; j<c1; j++)
        {
            scanf("%d", &m1[i][j]);
        }
    }

    // asking user for dimensions of the second matrix
    printf("Enter rows & columns of the second matrix: ");
    scanf("%d %d", &r2, &c2);

    // taking input for the second matrix
    printf("Enter elements of the second matrix:\n");
    for(int i=0; i<r2; i++)
    {
        for(int j=0; j<c2; j++)
        {
            scanf("%d", &m2[i][j]);
        }
    }

    // adding the matrices
    addMatrices(m1, m2, add, r1, c1);

    // printing the addition result
    printf("\nAddition of both matrices: \n");
    printMatrix(add, r1, c1);

    // multiplying the matrices
    multiplyMatrices(m1, m2, mul, r1, c1, r2, c2);

    // printing the multiplication result
    printf("\nMultiplication of both matrices: \n");
    printMatrix(mul, r1, c2);

    return 0;
}