//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

void labyrinth_search(int **grid, int n, int m, int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
    {
        return;
    }
    if (grid[x][y] == 2)
    {
        return;
    }
    grid[x][y] = 2;

     labyrinth_search(grid, n, m, x - 1, y);
    labyrinth_search(grid, n, m, x, y - 1);
    labyrinth_search(grid, n, m, x + 1, y);
    labyrinth_search(grid, n, m, x, y + 1);
}

int main()
{
    int n, m, x, y;
    int **grid;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    grid = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        grid[i] = (int *)malloc(m * sizeof(int));
    }

    printf("Enter the position of the treasure (x, y): ");
    scanf("%d", &x);
    scanf("%d", &y);

    labyrinth_search(grid, n, m, x, y);

    if (grid[x][y] == 2)
    {
        printf("Congratulations! You found the treasure!");
    }
    else
    {
        printf("Sorry, the treasure was not found.");
    }

    return 0;
}