//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define T 100
#define D 0.5

int **create_grid();
void percolate(int **grid);
int count_percolating_clusters(int **grid);

int main()
{
    srand(time(NULL));

    int **grid = create_grid();
    percolate(grid);

    int num_clusters = count_percolating_clusters(grid);

    printf("Number of percolating clusters: %d\n", num_clusters);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] == 1)
                printf("*");
            else
                printf(".");
        }
        printf("\n");
    }

    for (int i = 0; i < N; i++)
        free(grid[i]);
    free(grid);

    return 0;
}

int **create_grid()
{
    int **grid = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++)
    {
        grid[i] = (int *)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++)
            grid[i][j] = rand() % 2;
    }
    return grid;
}

void percolate(int **grid)
{
    int num_clusters = 0;

    for (int i = 0; i < N; i++)
    {
        if (grid[i][0] == 1)
        {
            grid[i][0] = 2;
            num_clusters++;
        }
    }

    for (int j = 0; j < N; j++)
    {
        if (grid[0][j] == 1)
        {
            grid[0][j] = 2;
            num_clusters++;
        }
    }

    for (int i = 1; i < N - 1; i++)
    {
        for (int j = 1; j < N - 1; j++)
        {
            if (grid[i][j] == 1)
            {
                grid[i][j] = 2;
                num_clusters++;
            }
        }
    }
}

int count_percolating_clusters(int **grid)
{
    int count = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] == 2)
            {
                count++;
            }
        }
    }

    return count;
}