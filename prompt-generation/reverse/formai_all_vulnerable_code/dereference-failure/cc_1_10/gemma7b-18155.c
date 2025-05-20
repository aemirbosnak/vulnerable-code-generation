//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20

#define PLAYER_SHIP_SIZE 3
#define BULLET_SIZE 5

void DrawGrid(int **grid, int w, int h)
{
    for(int r = 0; r < h; r++)
    {
        for(int c = 0; c < w; c++)
        {
            printf("%c ", grid[r][c] ? 'O' : '.');
        }
        printf("\n");
    }
}

void MovePlayerShip(int **grid, int x, int y)
{
    if(x < 0)
    {
        x = 0;
    }
    else if(x >= WIDTH - PLAYER_SHIP_SIZE)
    {
        x = WIDTH - PLAYER_SHIP_SIZE - 1;
    }

    if(y < 0)
    {
        y = 0;
    }
    else if(y >= HEIGHT - PLAYER_SHIP_SIZE)
    {
        y = HEIGHT - PLAYER_SHIP_SIZE - 1;
    }

    for(int r = y; r < y + PLAYER_SHIP_SIZE; r++)
    {
        for(int c = x; c < x + PLAYER_SHIP_SIZE; c++)
        {
            grid[r][c] = 1;
        }
    }
}

void PlaceBullets(int **grid, int x, int y)
{
    for(int r = y; r < y + BULLET_SIZE; r++)
    {
        for(int c = x; c < x + BULLET_SIZE; c++)
        {
            grid[r][c] = 2;
        }
    }
}

int main()
{
    int **grid = (int**)malloc(HEIGHT * sizeof(int *) + HEIGHT);
    for(int i = 0; i < HEIGHT; i++)
    {
        grid[i] = (int *)malloc(WIDTH * sizeof(int));
    }

    int x = 20;
    int y = 10;

    int score = 0;

    srand(time(NULL));

    while(!grid[y][x] && score < 10)
    {
        int dx = rand() % 3 - 1;
        int dy = rand() % 3 - 1;

        MovePlayerShip(grid, x, y);
        PlaceBullets(grid, x + dx, y);

        DrawGrid(grid, WIDTH, HEIGHT);
        printf("Score: %d\n", score);

        score++;
    }

    DrawGrid(grid, WIDTH, HEIGHT);
    printf("Game Over!\n");
    printf("Your score: %d\n", score);

    free(grid);

    return 0;
}