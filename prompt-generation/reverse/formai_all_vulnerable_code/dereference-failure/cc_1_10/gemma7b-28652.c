//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: Ada Lovelace
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int n, m, i, j, x, y;
    printf("Enter the number of rows and columns:");
    scanf("%d %d", &n, &m);
    int **arr = (int **)malloc(n * sizeof(int *) + m * sizeof(int));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(m * sizeof(int));
    }
    printf("Enter the number of drops:");
    scanf("%d", &x);
    for (i = 0; i < x; i++)
    {
        printf("Enter the row and column of the drop:");
        scanf("%d %d", &y, &j);
        arr[y][j] = 1;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                int dx[] = {0, 1, 0, -1};
                int dy[] = {1, 0, -1, 0};
                for (x = 0; x < 4; x++)
                {
                    if (arr[i + dx[x]][j + dy[x]] == 0)
                    {
                        arr[i + dx[x]][j + dy[x]] = 1;
                    }
                }
            }
        }
    }
    printf("The water has percolated:");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    free(arr);
    return 0;
}