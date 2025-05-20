//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, i, j, count = 0;
    scanf("%d %d", &n, &m);
    int grid[n][m], visited[n][m];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &grid[i][j]);
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && visited[i][j] == 0)
            {
                count++;
                visited[i][j] = 1;
                int stack[n * m][2];
                int top = -1;
                stack[++top][0] = i;
                stack[top][1] = j;

                while (top >= 0)
                {
                    int x = stack[top][0];
                    int y = stack[top--][1];

                    if (x > 0 && grid[x - 1][y] == 1 && visited[x - 1][y] == 0)
                    {
                        stack[++top][0] = x - 1;
                        stack[top][1] = y;
                        visited[x - 1][y] = 1;
                    }
                    if (x < n - 1 && grid[x + 1][y] == 1 && visited[x + 1][y] == 0)
                    {
                        stack[++top][0] = x + 1;
                        stack[top][1] = y;
                        visited[x + 1][y] = 1;
                    }
                    if (y > 0 && grid[x][y - 1] == 1 && visited[x][y - 1] == 0)
                    {
                        stack[++top][0] = x;
                        stack[top][1] = y - 1;
                        visited[x][y - 1] = 1;
                    }
                    if (y < m - 1 && grid[x][y + 1] == 1 && visited[x][y + 1] == 0)
                    {
                        stack[++top][0] = x;
                        stack[top][1] = y + 1;
                        visited[x][y + 1] = 1;
                    }
                }
            }
        }
    }

    printf("%d\n", count);

    return 0;
}