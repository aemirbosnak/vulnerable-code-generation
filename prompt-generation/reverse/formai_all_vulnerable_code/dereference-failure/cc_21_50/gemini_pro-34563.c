//GEMINI-pro DATASET v1.0 Category: Weather simulation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Turing Weather Simulation
 *
 * This program simulates the weather using a cellular automaton.
 * The weather is represented by a grid of cells, each of which can be in one of three states:
 *
 *    0: Sun
 *    1: Cloud
 *    2: Rain
 *
 * The weather evolves according to the following rules:
 *
 *    * If a cell is in the Sun state, it will stay in the Sun state unless it is adjacent to a cell in the Cloud or Rain state, in which case it will change to the Cloud state.
 *    * If a cell is in the Cloud state, it will stay in the Cloud state unless it is adjacent to a cell in the Rain state, in which case it will change to the Rain state.
 *    * If a cell is in the Rain state, it will stay in the Rain state unless it is adjacent to a cell in the Sun state, in which case it will change to the Cloud state.
 *
 * The program takes the following command-line arguments:
 *
 *    * -s: The size of the grid.
 *    * -n: The number of iterations to run the simulation.
 *    * -p: The probability of a cell being in the Cloud state at the start of the simulation.
 *
 * The program prints the weather grid to the standard output.
 */

int main(int argc, char **argv)
{
    // Parse command-line arguments.

    int size = 100;
    int iterations = 100;
    double probability = 0.5;

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-s") == 0)
        {
            size = atoi(argv[i + 1]);
        }
        else if (strcmp(argv[i], "-n") == 0)
        {
            iterations = atoi(argv[i + 1]);
        }
        else if (strcmp(argv[i], "-p") == 0)
        {
            probability = atof(argv[i + 1]);
        }
    }

    // Create the weather grid.

    int **grid = malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        grid[i] = malloc(size * sizeof(int));
    }

    // Initialize the weather grid.

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            grid[i][j] = (drand48() < probability) ? 1 : 0;
        }
    }

    // Run the simulation.

    for (int k = 0; k < iterations; k++)
    {
        // Update the weather grid.

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                int count = 0;

                // Count the number of adjacent cells in the Cloud or Rain state.

                for (int m = -1; m <= 1; m++)
                {
                    for (int n = -1; n <= 1; n++)
                    {
                        if (i + m >= 0 && i + m < size && j + n >= 0 && j + n < size && (grid[i + m][j + n] == 1 || grid[i + m][j + n] == 2))
                        {
                            count++;
                        }
                    }
                }

                // Update the cell's state.

                if (grid[i][j] == 0)
                {
                    if (count > 0)
                    {
                        grid[i][j] = 1;
                    }
                }
                else if (grid[i][j] == 1)
                {
                    if (count > 0)
                    {
                        grid[i][j] = 2;
                    }
                }
                else if (grid[i][j] == 2)
                {
                    if (count == 0)
                    {
                        grid[i][j] = 1;
                    }
                }
            }
        }

        // Print the weather grid.

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (grid[i][j] == 0)
                {
                    printf(" ");
                }
                else if (grid[i][j] == 1)
                {
                    printf(".");
                }
                else if (grid[i][j] == 2)
                {
                    printf("*");
                }
            }
            printf("\n");
        }

        printf("\n");
    }

    // Free the weather grid.

    for (int i = 0; i < size; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}