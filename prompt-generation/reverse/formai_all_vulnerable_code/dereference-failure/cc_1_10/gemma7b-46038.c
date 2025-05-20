//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENEMY 5

void initialize_map(int **map, int x, int y);
void draw_map(int **map, int x, int y);
void generate_enemies(int **map, int x, int y);

int main()
{
    int x = 20;
    int y = 20;
    int **map = NULL;

    initialize_map(&map, x, y);
    draw_map(map, x, y);
    generate_enemies(map, x, y);

    return 0;
}

void initialize_map(int **map, int x, int y)
{
    map = (int **)malloc(x * sizeof(int *) + 1);
    for (int i = 0; i < x; i++)
    {
        map[i] = (int *)malloc(y * sizeof(int) + 1);
        for (int j = 0; j < y; j++)
        {
            map[i][j] = 0;
        }
    }
}

void draw_map(int **map, int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}

void generate_enemies(int **map, int x, int y)
{
    int num_enemies = rand() % MAX_ENEMY;
    for (int i = 0; i < num_enemies; i++)
    {
        int x_pos = rand() % x;
        int y_pos = rand() % y;
        map[x_pos][y_pos] = 1;
    }
}