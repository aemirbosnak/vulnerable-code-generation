//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 20
#define BALL_SIZE 10

typedef struct Ball
{
    int x, y;
    int dx, dy;
} Ball;

void draw_map(int **map)
{
    for (int y = 0; y < MAP_SIZE; y++)
    {
        for (int x = 0; x < MAP_SIZE; x++)
        {
            printf("%c ", map[x][y] ? '#' : '.');
        }
        printf("\n");
    }
}

void move_ball(Ball *ball)
{
    ball->x += ball->dx;
    ball->y += ball->dy;

    if (ball->x >= MAP_SIZE - BALL_SIZE || ball->x <= 0)
    {
        ball->dx *= -1;
    }

    if (ball->y >= MAP_SIZE - BALL_SIZE || ball->y <= 0)
    {
        ball->dy *= -1;
    }
}

int main()
{
    int **map = NULL;
    Ball ball;

    map = (int **)malloc(MAP_SIZE * sizeof(int *));
    for (int i = 0; i < MAP_SIZE; i++)
    {
        map[i] = (int *)malloc(MAP_SIZE * sizeof(int));
    }

    ball.x = MAP_SIZE / 2;
    ball.y = MAP_SIZE / 2;
    ball.dx = 1;
    ball.dy = 1;

    srand(time(NULL));

    while (1)
    {
        system("clear");
        draw_map(map);
        move_ball(&ball);

        if (map[ball.x][ball.y] == '#')
        {
            printf("Game Over!");
            break;
        }

        sleep(0.1);
    }

    return 0;
}