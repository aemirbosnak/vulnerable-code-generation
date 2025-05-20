//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void generateMap(int **map, int size);
void drawMap(int **map, int size);
void playerMove(int **map, int size);

int main()
{
    int **map;
    int size = MAX_SIZE;

    map = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        map[i] = (int *)malloc(size * sizeof(int));
    }

    generateMap(map, size);
    drawMap(map, size);
    playerMove(map, size);

    for (int i = 0; i < size; i++)
    {
        free(map[i]);
    }
    free(map);

    return 0;
}

void generateMap(int **map, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            map[i][j] = rand() % 3;
        }
    }
}

void drawMap(int **map, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}

void playerMove(int **map, int size)
{
    int x, y;

    printf("Enter your move (x, y): ");
    scanf("%d %d", &x, &y);

    if (x < 0 || x >= size || y < 0 || y >= size)
    {
        printf("Invalid move.\n");
    }
    else
    {
        map[x][y] = 2;
        drawMap(map, size);
    }
}