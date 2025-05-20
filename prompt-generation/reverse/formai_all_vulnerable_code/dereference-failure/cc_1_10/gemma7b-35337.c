//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void game_of_life(int **arr, int n, int m)
{
    int i, j, k, l, count = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            count = 0;
            for (k = -1; k <= 1; k++)
            {
                for (l = -1; l <= 1; l++)
                {
                    if (arr[i + k][j + l] == 1 && (k == 0 || l == 0))
                    {
                        count++;
                    }
                }
            }
            if (arr[i][j] == 0 && count == 3)
            {
                arr[i][j] = 1;
            }
            else if (arr[i][j] == 1 && (count < 2 || count > 3))
            {
                arr[i][j] = 0;
            }
        }
    }
    game_of_life(arr, n, m);
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

    // Initialize the grid
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = 0;
        }
    }

    // Set some initial cells to 1
    arr[1][1] = 1;
    arr[2][2] = 1;
    arr[3][3] = 1;

    game_of_life(arr, n, m);

    // Print the final grid
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