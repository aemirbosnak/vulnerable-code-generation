//FormAI DATASET v1.0 Category: Matrix operations ; Style: enthusiastic
#include<stdio.h>
int main()
{
    printf("Welcome to Matrix Operations in C!\n");
    int r1, c1, r2, c2, i, j, k; //declaring variables for matrix dimensions and indexing
    printf("Enter the dimensions of the first matrix:\n");
    scanf("%d%d", &r1, &c1); //Taking input of row and column
    int A[r1][c1]; //Declaring array with Matrix 1 dimensions
    printf("Enter the elements of the first matrix:\n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            scanf("%d", &A[i][j]); //Taking input values of Matrix 1
        }
    }
    printf("Enter the dimensions of the second matrix:\n");
    scanf("%d%d", &r2, &c2); //Taking input of second matrix dimensions
    int B[r2][c2];
    printf("Enter the elements of the second matrix:\n");
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            scanf("%d", &B[i][j]); //Taking input values of Matrix 2
        }
    }
    printf("Matrix 1:\n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            printf("%d ", A[i][j]); //Displaying Matrix 1
        }
        printf("\n");
    }
    printf("Matrix 2:\n");
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            printf("%d ", B[i][j]); //Displaying Matrix 2
        }
        printf("\n");
    }
    if(c1!=r2) //Checking the feasibility of matrix multiplication
    {
        printf("Matrix multiplication is not possible!\n");
    }
    else
    {
        int C[r1][c2];
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c2;j++)
            {
                C[i][j]=0; //Initializing Matrix 3 values to zero
                for(k=0;k<c1;k++)
                {
                    C[i][j]=C[i][j]+A[i][k]*B[k][j]; //Matrix multiplication
                }
            }
        }
        printf("Product of Matrix 1 and Matrix 2 is:\n");
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c2;j++)
            {
                printf("%d ", C[i][j]); //Displaying the result of matrix multiplication
            }
            printf("\n");
        }
    }
    return 0;
}