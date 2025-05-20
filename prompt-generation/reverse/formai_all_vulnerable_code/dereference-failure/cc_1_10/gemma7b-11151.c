//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20

#define PLAYER_WIDTH 3
#define PLAYER_HEIGHT 3

#define BULLET_WIDTH 1
#define BULLET_HEIGHT 1

#define ENEMY_WIDTH 5
#define ENEMY_HEIGHT 2

#define BULLET_SPEED 5
#define ENEMY_SPEED 3

#define SCORE 0

void draw_map(int **map, int w, int h)
{
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            printf("%c ", map[y][x]);
        }
        printf("\n");
    }
}

void move_player(int **map, int x, int y)
{
    if (map[y][x] == ' ')
    {
        map[y][x] = 'P';
    }
    else if (map[y][x] == '#')
    {
        printf("Game Over!\n");
        exit(0);
    }
    else
    {
        map[y][x] = ' ';
        map[y][x] = 'P';
    }
}

void shoot_bullet(int **map, int x, int y)
{
    map[y][x] = 'B';
}

void move_enemy(int **map, int x, int y)
{
    if (map[y][x] == ' ')
    {
        map[y][x] = 'E';
    }
    else if (map[y][x] == '#')
    {
        printf("Game Over!\n");
        exit(0);
    }
    else
    {
        map[y][x] = ' ';
        map[y][x] = 'E';
    }
}

int main()
{
    int **map = malloc(MAP_HEIGHT * sizeof(int *));
    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        map[i] = malloc(MAP_WIDTH * sizeof(int));
    }

    int x = 10;
    int y = 0;

    int enemy_x = 0;
    int enemy_y = 0;

    time_t t = time(NULL);

    while (1)
    {
        draw_map(map, MAP_WIDTH, MAP_HEIGHT);

        move_player(map, x, y);

        shoot_bullet(map, x, y);

        move_enemy(map, enemy_x, enemy_y);

        if (time(NULL) - t >= BULLET_SPEED)
        {
            t = time(NULL);
            enemy_y++;
            enemy_x++;
        }

        if (map[enemy_y][enemy_x] == 'B')
        {
            printf("You Win!\n");
            exit(0);
        }

        sleep(0.01);
    }

    return 0;
}