//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: shocked
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_SIM_SIZE 1024

int main()
{
    int **percolation_matrix;
    int sim_size;
    int num_iter;
    int i, j, k;

    sim_size = MAX_SIM_SIZE;
    num_iter = 1000;

    percolation_matrix = (int *)malloc(sim_size * sim_size * sizeof(int));
    for (i = 0; i < sim_size * sim_size; i++)
    {
        percolation_matrix[i] = 0;
    }

    srand(time(NULL));

    for (k = 0; k < num_iter; k++)
    {
        for (i = 0; i < sim_size; i++)
        {
            for (j = 0; j < sim_size; j++)
            {
                if (percolation_matrix[i][j] == 0)
                {
                    if (rand() % 2 == 0)
                    {
                        percolation_matrix[i][j] = 1;
                    }
                }
            }
        }
    }

    for (i = 0; i < sim_size; i++)
    {
        for (j = 0; j < sim_size; j++)
        {
            printf("%d ", percolation_matrix[i][j]);
        }
        printf("\n");
    }

    free(percolation_matrix);

    return 0;
}