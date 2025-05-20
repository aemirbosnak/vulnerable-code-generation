//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

void initialize_universe(int **universe, int size)
{
    *universe = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        (*universe)[i] = 0;
    }
}

void simulate_explosion(int **universe, int x, int y)
{
    for (int i = x - 1; i <= x + 1; i++)
    {
        for (int j = y - 1; j <= y + 1; j++)
        {
            if ((*universe)[i] && (*universe)[j] && i != x && j != y)
            {
                (*universe)[i] = (*universe)[j] = 0;
            }
        }
    }
}

int main()
{
    int size = MAX_SIZE;
    int **universe;

    initialize_universe(&universe, size);

    // Seed the random number generator
    srand(time(NULL));

    // Create a random explosion
    int x = rand() % size;
    int y = rand() % size;
    simulate_explosion(&universe, x, y);

    // Print the universe
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", universe[i][j]);
        }
        printf("\n");
    }

    return 0;
}