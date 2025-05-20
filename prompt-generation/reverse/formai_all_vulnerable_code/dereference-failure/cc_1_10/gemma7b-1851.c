//Gemma-7B DATASET v1.0 Category: Weather simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j, n, t, x, y;
    char **grid;
    time_t t_start, t_end;

    n = 10;
    grid = (char **)malloc(n * sizeof(char *));
    for(i = 0; i < n; i++)
    {
        grid[i] = (char *)malloc(n * sizeof(char));
    }

    t_start = time(NULL);
    srand(time(NULL));

    for(t = 0; t < 1000; t++)
    {
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                x = rand() % 2;
                y = rand() % 2;
                if(x == y)
                {
                    grid[i][j] = 'H';
                }
                else
                {
                    grid[i][j] = 'O';
                }
            }
        }
    }

    t_end = time(NULL);
    printf("Time taken: %ld seconds\n", t_end - t_start);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }

    free(grid);

    return 0;
}