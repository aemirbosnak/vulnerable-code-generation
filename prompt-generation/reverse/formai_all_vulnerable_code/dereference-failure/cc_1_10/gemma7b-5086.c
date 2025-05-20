//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIM_SIZE 100

int main()
{
    int **arr;
    int i, j, k, sim_size;

    // Allocate memory for the simulation
    sim_size = MAX_SIM_SIZE;
    arr = (int *)malloc(sim_size * sizeof(int *));
    for (i = 0; i < sim_size; i++)
    {
        arr[i] = (int *)malloc(sim_size * sizeof(int));
    }

    // Initialize the simulation
    for (i = 0; i < sim_size; i++)
    {
        for (j = 0; j < sim_size; j++)
        {
            arr[i][j] = 0;
        }
    }

    // Simulate Percolation
    k = 0;
    while (k < MAX_SIM_SIZE)
    {
        // Generate a random pair of indices
        i = rand() % sim_size;
        j = rand() % sim_size;

        // If the cell is not already saturated and the sum of the neighbors is greater than the threshold, saturate the cell
        if (arr[i][j] == 0 && (arr[i-1][j] + arr[i+1][j] + arr[i][j-1] + arr[i][j+1] >= 3))
        {
            arr[i][j] = 1;
            k++;
        }
    }

    // Print the simulation results
    for (i = 0; i < sim_size; i++)
    {
        for (j = 0; j < sim_size; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (i = 0; i < sim_size; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}