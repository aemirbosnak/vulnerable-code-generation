//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main()
{
    int **a = (int **)malloc(MAX * sizeof(int *));
    for (int i = 0; i < MAX; i++)
    {
        a[i] = (int *)malloc(MAX * sizeof(int));
    }

    int n, m, k;
    scanf("Enter the number of rows: ", &n);
    scanf("Enter the number of columns: ", &m);
    scanf("Enter the number of iterations: ", &k);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = rand() % 10;
        }
    }

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int l = 0; l < m; l++)
            {
                a[j][l] = (a[j][l] * 2) % 10;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < MAX; i++)
    {
        free(a[i]);
    }
    free(a);

    return 0;
}