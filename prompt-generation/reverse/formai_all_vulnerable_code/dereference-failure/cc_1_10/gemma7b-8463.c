//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: genius
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

void solve(int n)
{
    int i, j, k, l, r, mid, ctr = 0;
    int **arr = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int*)malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
            {
                arr[i][j] = 1;
            }
        }
    }

    for (k = 0; k < n; k++)
    {
        for (l = 0; l < n; l++)
        {
            for (r = 0; r < n; r++)
            {
                if (arr[l][r] && arr[r][k] && arr[k][l] && l != r && k != l)
                {
                    ctr++;
                }
            }
        }
    }

    printf("The number of triangles is: %d", ctr);
}

int main()
{
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    solve(n);

    return 0;
}