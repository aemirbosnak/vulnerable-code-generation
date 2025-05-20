//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: Ada Lovelace
//The Matrix Operations Example Program

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;

    printf("Welcome to the Matrix Operations Example Program!\n");

    printf("Please enter the number of rows for the matrix A:");
    scanf("%d", &a);

    printf("Please enter the number of columns for the matrix A:");
    scanf("%d", &b);

    printf("Please enter the number of rows for the matrix B:");
    scanf("%d", &c);

    printf("Please enter the number of columns for the matrix B:");
    scanf("%d", &d);

    int **a_matrix = (int **)malloc(a * sizeof(int *));
    for(i = 0; i < a; i++)
    {
        a_matrix[i] = (int *)malloc(b * sizeof(int));
    }

    int **b_matrix = (int **)malloc(c * sizeof(int *));
    for(i = 0; i < c; i++)
    {
        b_matrix[i] = (int *)malloc(d * sizeof(int));
    }

    printf("Please enter the elements of the matrix A:");
    for(i = 0; i < a; i++)
    {
        for(j = 0; j < b; j++)
        {
            scanf("%d", &a_matrix[i][j]);
        }
    }

    printf("Please enter the elements of the matrix B:");
    for(i = 0; i < c; i++)
    {
        for(j = 0; j < d; j++)
        {
            scanf("%d", &b_matrix[i][j]);
        }
    }

    int **c_matrix = (int **)malloc(a * sizeof(int *));
    for(i = 0; i < a; i++)
    {
        c_matrix[i] = (int *)malloc(b * sizeof(int));
    }

    matrix_multiplication(a_matrix, b_matrix, c_matrix, a, b, c);

    printf("The elements of the product matrix C are:");
    for(i = 0; i < a; i++)
    {
        for(j = 0; j < b; j++)
        {
            printf("%d ", c_matrix[i][j]);
        }
        printf("\n");
    }

    free(a_matrix);
    free(b_matrix);
    free(c_matrix);

    return 0;
}

int matrix_multiplication(int **a_matrix, int **b_matrix, int **c_matrix, int a, int b, int c)
{
    int i, j, k, l, m, n;

    for(i = 0; i < a; i++)
    {
        for(j = 0; j < b; j++)
        {
            c_matrix[i][j] = 0;
            for(k = 0; k < c; k++)
            {
                l = a_matrix[i][k] * b_matrix[k][j];
                c_matrix[i][j] += l;
            }
        }
    }

    return 0;
}