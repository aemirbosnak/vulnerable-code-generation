//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: mathematical
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_SIM_SIZE 512
#define MAX_WATER_LEVEL 256

int main()
{
    int sim_size = MAX_SIM_SIZE;
    int water_level = MAX_WATER_LEVEL;
    int **percolation_map = NULL;

    percolation_map = (int **)malloc(sim_size * sizeof(int *));
    for (int i = 0; i < sim_size; i++)
    {
        percolation_map[i] = (int *)malloc(water_level * sizeof(int));
    }

    // Initialize the percoltion map
    for (int i = 0; i < sim_size; i++)
    {
        for (int j = 0; j < water_level; j++)
        {
            percolation_map[i][j] = 0;
        }
    }

    // Simulate water flow
    int x, y;
    srand(time(NULL));
    for (int i = 0; i < 1000; i++)
    {
        x = rand() % sim_size;
        y = rand() % water_level;
        if (percolation_map[x][y] == 0)
        {
            percolation_map[x][y] = 1;
        }
    }

    // Print the percoltion map
    for (int i = 0; i < sim_size; i++)
    {
        for (int j = 0; j < water_level; j++)
        {
            printf("%d ", percolation_map[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < sim_size; i++)
    {
        free(percolation_map[i]);
    }
    free(percolation_map);

    return 0;
}