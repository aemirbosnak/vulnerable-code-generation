//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 10

void initialize_game(int **cells, int size)
{
    for (int i = 0; i < size; i++)
    {
        cells[i] = malloc(size * sizeof(int));
        for (int j = 0; j < size; j++)
        {
            cells[i][j] = 0;
        }
    }
}

void update_cells(int **cells, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int neighbors = 0;
            if (i > 0) neighbors++;
            if (i < size - 1) neighbors++;
            if (j > 0) neighbors++;
            if (j < size - 1) neighbors++;

            if (cells[i][j] == 1 && neighbors < 2)
            {
                cells[i][j] = 0;
            }
            else if (cells[i][j] == 0 && neighbors == 3)
            {
                cells[i][j] = 1;
            }
        }
    }
}

int main()
{
    int **cells = NULL;
    initialize_game(cells, MAX_CELLS);

    // Initial cell setup
    cells[5][5] = 1;
    cells[5][6] = 1;
    cells[6][5] = 1;

    // Game loop
    for (int t = 0; t < 10; t++)
    {
        update_cells(cells, MAX_CELLS);
    }

    // Print final cell state
    for (int i = 0; i < MAX_CELLS; i++)
    {
        for (int j = 0; j < MAX_CELLS; j++)
        {
            printf("%d ", cells[i][j]);
        }
        printf("\n");
    }

    return 0;
}