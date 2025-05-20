//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define a 2D array to store the game of life cells
    int **cells = NULL;
    int rows = 10;
    int cols = 10;

    // Allocate memory for the cells
    cells = malloc(rows * sizeof(int *) + rows);
    for (int i = 0; i < rows; i++)
    {
        cells[i] = malloc(cols * sizeof(int));
    }

    // Initialize the cells
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            cells[r][c] = 0;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Randomly set some cells to alive
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            if (rand() % 2 == 0)
            {
                cells[r][c] = 1;
            }
        }
    }

    // Simulate the game of life for 10 generations
    for (int gen = 0; gen < 10; gen++)
    {
        // Calculate the number of neighbors for each cell
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                int neighbors = 0;
                // Check the cells to the left
                if (c - 1 >= 0)
                {
                    neighbors++;
                }
                // Check the cells above
                if (r - 1 >= 0)
                {
                    neighbors++;
                }
                // Check the cells to the right
                if (c + 1 < cols)
                {
                    neighbors++;
                }
                // Check the cells below
                if (r + 1 < rows)
                {
                    neighbors++;
                }

                // Update the cell's state based on its number of neighbors
                if (cells[r][c] == 1 && neighbors < 2)
                {
                    cells[r][c] = 0;
                }
                else if (cells[r][c] == 0 && neighbors == 3)
                {
                    cells[r][c] = 1;
                }
            }
        }
    }

    // Print the final state of the cells
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            printf("%d ", cells[r][c]);
        }
        printf("\n");
    }

    // Free the memory allocated for the cells
    for (int r = 0; r < rows; r++)
    {
        free(cells[r]);
    }
    free(cells);

    return 0;
}