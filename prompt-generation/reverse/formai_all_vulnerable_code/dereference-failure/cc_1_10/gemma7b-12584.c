//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 20

// Define the Percolation Matrix
int **percolation_matrix(int size)
{
    int **matrix = malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        matrix[i] = malloc(size * sizeof(int));
    }

    return matrix;
}

// Simulate Percolation
void simulate_percolation(int **matrix, int size)
{
    srand(time(NULL));

    // Randomly assign open and closed sites
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = rand() % 2;
        }
    }

    // Connect open sites
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j] == 1)
            {
                // Connect horizontally
                if (j - 1 >= 0 && matrix[i][j - 1] == 1)
                {
                    matrix[i][j] |= matrix[i][j - 1];
                }

                // Connect vertically
                if (i - 1 >= 0 && matrix[i - 1][j] == 1)
                {
                    matrix[i][j] |= matrix[i - 1][j];
                }
            }
        }
    }
}

int main()
{
    int size = BOARD_SIZE;

    // Create the percolation matrix
    int **matrix = percolation_matrix(size);

    // Simulate percolation
    simulate_percolation(matrix, size);

    // Print the matrix
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < size; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}