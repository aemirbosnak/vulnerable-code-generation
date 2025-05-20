//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIM_SIZE 256

// Define the Percolation Matrix
int **percolation_matrix(int size)
{
    int **matrix = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        matrix[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}

// Simulate Percolation
void percolat(int **matrix, int size)
{
    // Randomly set some sites to open
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (rand() % 2 == 0)
            {
                matrix[i][j] = 1;
            }
        }
    }

    // Connect open sites to their neighbors
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j] == 1)
            {
                // Connect horizontally
                if (j > 0 && matrix[i][j - 1] == 1)
                {
                    matrix[i][j] |= 2;
                }
                // Connect vertically
                if (i > 0 && matrix[i - 1][j] == 1)
                {
                    matrix[i][j] |= 4;
                }
            }
        }
    }
}

int main()
{
    // Set the simulation size
    int size = MAX_SIM_SIZE;

    // Create the percolatation matrix
    int **matrix = percolation_matrix(size);

    // Simulate percolat
    percolat(matrix, size);

    // Print the percolatation matrix
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}