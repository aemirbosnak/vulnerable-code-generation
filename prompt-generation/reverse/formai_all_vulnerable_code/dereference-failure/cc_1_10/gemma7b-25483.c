//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

void matrix_operations(int **a, int **b, int **c, int n)
{
    int i, j, k;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            c[i][j] = 0;
            for(k = 0; k < n; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main()
{
    int n;
    scanf("Enter the number of rows and columns:", &n);
    int **a = (int **)malloc(n * sizeof(int *));
    int **b = (int **)malloc(n * sizeof(int *));
    int **c = (int **)malloc(n * sizeof(int *));

    for(int i = 0; i < n; i++)
    {
        a[i] = (int *)malloc(n * sizeof(int));
        b[i] = (int *)malloc(n * sizeof(int));
        c[i] = (int *)malloc(n * sizeof(int));
    }

    // Enter the elements of matrix A and matrix B
    printf("Enter the elements of matrix A:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d ", &a[i][j]);
        }
    }

    printf("Enter the elements of matrix B:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d ", &b[i][j]);
        }
    }

    // Perform matrix operations
    matrix_operations(a, b, c, n);

    // Print the elements of matrix C
    printf("The elements of matrix C are:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", c[i][j]);
        }
    }

    return 0;
}