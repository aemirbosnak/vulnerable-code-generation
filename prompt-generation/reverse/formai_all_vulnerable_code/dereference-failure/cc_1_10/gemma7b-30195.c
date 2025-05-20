//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

void mx(int **a, int n, int m)
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            for (k = 0; k < n; k++)
            {
                if (i == k)
                {
                    a[i][j] = 1;
                }
                else
                {
                    a[i][j] = 0;
                }
            }
        }
    }
}

int main()
{
    int n, m;
    scanf("Enter the number of rows: ", &n);
    scanf("Enter the number of columns: ", &m);

    int **a = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        a[i] = (int *)malloc(m * sizeof(int));
    }

    mx(a, n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    free(a);

    return 0;
}