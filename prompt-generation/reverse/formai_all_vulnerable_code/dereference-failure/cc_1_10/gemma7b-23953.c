//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

void matrix_operations(int **a, int **b, int **c)
{
    int i, j, k, l, m, n;
    printf("Enter the number of rows for matrix A: ");
    scanf("%d", &l);
    printf("Enter the number of columns for matrix A: ");
    scanf("%d", &m);
    printf("Enter the number of rows for matrix B: ");
    scanf("%d", &n);
    printf("Enter the number of columns for matrix B: ");
    scanf("%d", &k);

    a = (int **)malloc(l * sizeof(int *));
    for (i = 0; i < l; i++)
    {
        a[i] = (int *)malloc(m * sizeof(int));
    }

    b = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        b[i] = (int *)malloc(k * sizeof(int));
    }

    c = (int **)malloc(l * sizeof(int *));
    for (i = 0; i < l; i++)
    {
        c[i] = (int *)malloc(k * sizeof(int));
    }

    printf("Enter the elements of matrix A: ");
    for (i = 0; i < l; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the elements of matrix B: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < k; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    matrix_operations(a, b, c);
}

int main()
{
    int **a = NULL, **b = NULL, **c = NULL;
    matrix_operations(a, b, c);
    return 0;
}