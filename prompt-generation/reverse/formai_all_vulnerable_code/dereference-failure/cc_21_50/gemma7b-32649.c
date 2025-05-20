//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Create a 2D array to store the game of life cells
    int **cells = NULL;
    int rows = 20;
    int cols = 20;
    cells = (int**)malloc(rows * sizeof(int*));
    for (int r = 0; r < rows; r++)
    {
        cells[r] = (int*)malloc(cols * sizeof(int));
    }

    // Initialize the cell values randomly
    srand(time(NULL));
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            cells[r][c] = rand() % 2;
        }
    }

    // Print the initial cell values
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            printf("%d ", cells[r][c]);
        }
        printf("\n");
    }

    // Simulate the game of life
    int generations = 0;
    while (1)
    {
        // Calculate the number of neighbors for each cell
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                int neighbors = 0;
                if (r > 0) neighbors++;
                if (r < rows - 1) neighbors++;
                if (c > 0) neighbors++;
                if (c < cols - 1) neighbors++;

                // Update the cell value based on the number of neighbors
                if (cells[r][c] == 1 && neighbors < 2) cells[r][c] = 0;
                if (cells[r][c] == 0 && neighbors == 3) cells[r][c] = 1;
            }
        }

        // Increment the number of generations
        generations++;

        // Print the updated cell values
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                printf("%d ", cells[r][c]);
            }
            printf("\n");
        }

        // Check if the game is over
        if (generations > 10) break;
    }

    // Free the memory allocated for the game of life cells
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            free(cells[r][c]);
        }
        free(cells[r]);
    }

    free(cells);

    return 0;
}