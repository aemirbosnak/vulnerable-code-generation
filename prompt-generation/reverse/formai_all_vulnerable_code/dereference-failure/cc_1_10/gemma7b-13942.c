//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 100

void update_cells(int **cells, int rows, int cols)
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            int neighbors = 0;
            if (r > 0) neighbors++;
            if (r < rows - 1) neighbors++;
            if (c > 0) neighbors++;
            if (c < cols - 1) neighbors++;

            cells[r][c] = (cells[r][c] == 1 && neighbors >= 2) || neighbors == 3;
        }
    }
}

int main()
{
    int **cells = (int **)malloc(MAX_CELLS * sizeof(int *));
    for (int i = 0; i < MAX_CELLS; i++)
    {
        cells[i] = (int *)malloc(MAX_CELLS * sizeof(int));
    }

    int rows = 10;
    int cols = 10;

    // Initialize the game of life board
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            cells[r][c] = rand() % 2;
        }
    }

    // Simulate the game of life
    for (int t = 0; t < 10; t++)
    {
        update_cells(cells, rows, cols);
    }

    // Print the final board
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            printf("%d ", cells[r][c]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < MAX_CELLS; i++)
    {
        free(cells[i]);
    }
    free(cells);

    return 0;
}