//FormAI DATASET v1.0 Category: Matrix operations ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows_a, cols_a, rows_b, cols_b, i, j, k;

    //Get the dimensions of both matrices
    printf("Enter rows and columns of matrix A: ");
    scanf("%d %d", &rows_a, &cols_a);
    printf("Enter rows and columns of matrix B: ");
    scanf("%d %d", &rows_b, &cols_b);

    //Check if matrix multiplication is possible
    if(cols_a != rows_b)
    {
        printf("Invalid dimensions! Multiplication is not possible");
        exit(1);
    }

    //Declare matrices
    int matrix_a[rows_a][cols_a], matrix_b[rows_b][cols_b], result_matrix[rows_a][cols_b];

    //Get values for matrix A
    printf("\nEnter elements of matrix A:\n");
    for(i=0;i<rows_a;i++)
    {
        for(j=0;j<cols_a;j++)
        {
            printf("Enter element (%d,%d): ", i+1, j+1);
            scanf("%d", &matrix_a[i][j]);
        }
    }

    //Get values for matrix B
    printf("\nEnter elements of matrix B:\n");
    for(i=0;i<rows_b;i++)
    {
        for(j=0;j<cols_b;j++)
        {
            printf("Enter element (%d,%d): ", i+1, j+1);
            scanf("%d", &matrix_b[i][j]);
        }
    }

    //Initialize result matrix with 0
    for(i=0;i<rows_a;i++)
    {
        for(j=0;j<cols_b;j++)
        {
            result_matrix[i][j] = 0;
        }
    }

    //Perform matrix multiplication
    for(i=0;i<rows_a;i++)
    {
        for(j=0;j<cols_b;j++)
        {
            for(k=0;k<cols_a;k++)
            {
                result_matrix[i][j] += (matrix_a[i][k] * matrix_b[k][j]);
            }
        }
    }

    //Print result matrix
    printf("\nResultant matrix: \n");
    for(i=0;i<rows_a;i++)
    {
        for(j=0;j<cols_b;j++)
        {
            printf("%d ", result_matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}