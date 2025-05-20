//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: complex
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 20

typedef struct Cell {
    int x, y, state;
} Cell;

void simulate(Cell **cells, int size)
{
    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
        {
            cells[x][y].state = 0;
        }
    }

    cells[0][0].state = 1;
    cells[0][size - 1].state = 1;
    cells[size - 1][0].state = 1;
    cells[size - 1][size - 1].state = 1;

    int iterations = 0;
    while (!cells[size - 1][size - 1].state)
    {
        iterations++;
        for (int x = 0; x < size; x++)
        {
            for (int y = 0; y < size; y++)
            {
                if (cells[x][y].state == 0)
                {
                    int sum = 0;
                    for (int dx = -1; dx <= 1; dx++)
                    {
                        for (int dy = -1; dy <= 1; dy++)
                        {
                            if (cells[x + dx][y + dy].state == 1)
                            {
                                sum++;
                            }
                        }
                    }
                    if (sum >= 3)
                    {
                        cells[x][y].state = 1;
                    }
                }
            }
        }
    }

    printf("Number of iterations: %d\n", iterations);
}

int main()
{
    Cell **cells = (Cell **)malloc(MAX_SIZE * MAX_SIZE * sizeof(Cell));
    for (int i = 0; i < MAX_SIZE * MAX_SIZE; i++)
    {
        cells[i] = (Cell *)malloc(sizeof(Cell));
        cells[i]->x = -1;
        cells[i]->y = -1;
        cells[i]->state = 0;
    }

    simulate(cells, MAX_SIZE);

    return 0;
}