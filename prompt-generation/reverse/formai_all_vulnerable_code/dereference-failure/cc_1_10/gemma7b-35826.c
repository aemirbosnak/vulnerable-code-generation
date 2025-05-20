//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void generate_map(int **map, int size)
{
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            map[r][c] = rand() % 2;
        }
    }
}

void traverse_map(int **map, int size)
{
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            if (map[r][c] == 1)
            {
                printf("O ");
            }
            else
            {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int main()
{
    int map_size = 10;
    int **map = (int **)malloc(map_size * sizeof(int *));
    for (int i = 0; i < map_size; i++)
    {
        map[i] = (int *)malloc(map_size * sizeof(int));
    }

    generate_map(map, map_size);
    traverse_map(map, map_size);

    free(map);

    return 0;
}