//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 20

void initialize_game(int **cells, int size);
void simulate_game(int **cells, int size);
void print_cells(int **cells, int size);

int main()
{
    int **cells;
    int size = MAX_CELLS;

    initialize_game(cells, size);
    simulate_game(cells, size);
    print_cells(cells, size);

    return 0;
}

void initialize_game(int **cells, int size)
{
    cells = (int *)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        cells[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++)
        {
            cells[i][j] = 0;
        }
    }
}

void simulate_game(int **cells, int size)
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

            if (cells[i][j] == 1 && neighbors < 2) cells[i][j] = 0;
            if (cells[i][j] == 0 && neighbors == 3) cells[i][j] = 1;
        }
    }
}

void print_cells(int **cells, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", cells[i][j]);
        }
        printf("\n");
    }
}