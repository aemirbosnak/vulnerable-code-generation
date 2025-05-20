//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: recursive
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void percol_sim(int **arr, int n, int m, int **visited, int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y] || arr[x][y] == 0)
    {
        return;
    }

    visited[x][y] = 1;

    percol_sim(arr, n, m, visited, x - 1, y);
    percol_sim(arr, n, m, visited, x + 1, y);
    percol_sim(arr, n, m, visited, x, y - 1);
    percol_sim(arr, n, m, visited, x, y + 1);
}

int main()
{
    int n, m;
    scanf("Enter the number of rows: ", &n);
    scanf("Enter the number of columns: ", &m);

    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(m * sizeof(int));
    }

    int **visited = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        visited[i] = (int *)malloc(m * sizeof(int));
    }

    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = rand() % 2;
        }
    }

    percol_sim(arr, n, m, visited, 0, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}