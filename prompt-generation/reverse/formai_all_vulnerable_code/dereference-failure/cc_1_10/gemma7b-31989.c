//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void percol_sim(int **arr, int n, int m)
{
    int i, j, k, r, c;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                r = rand() % n;
                c = rand() % m;
                if (arr[r][c] == 1)
                {
                    arr[i][j] = 1;
                    percol_sim(arr, n, m);
                }
            }
        }
    }
    return;
}

int main()
{
    int n, m, i, j;
    printf("Enter the number of rows:");
    scanf("%d", &n);
    printf("Enter the number of columns:");
    scanf("%d", &m);
    int **arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(m * sizeof(int));
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            arr[i][j] = 0;
        }
    }
    percol_sim(arr, n, m);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}