//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 100

void initialize_game(int **cells, int size)
{
    for (int i = 0; i < size; i++)
    {
        cells[i] = malloc(sizeof(int) * size);
        for (int j = 0; j < size; j++)
        {
            cells[i][j] = 0;
        }
    }
}

void play_game(int **cells, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int num_neighbors = 0;
            for (int x = -1; x <= 1; x++)
            {
                for (int y = -1; y <= 1; y++)
                {
                    if (x == 0 && y == 0)
                        continue;
                    if (cells[i + x][j + y] == 1)
                        num_neighbors++;
                }
            }
            if (cells[i][j] == 1 && num_neighbors < 2)
                cells[i][j] = 0;
            else if (cells[i][j] == 0 && num_neighbors == 3)
                cells[i][j] = 1;
        }
    }
}

int main()
{
    int size = MAX_CELLS;
    int **cells = NULL;
    initialize_game(&cells, size);
    play_game(cells, size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", cells[i][j]);
        }
        printf("\n");
    }
    return 0;
}