//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 20

#define BULLET_WIDTH 5
#define BULLET_HEIGHT 1

#define invader_WIDTH 5
#define invader_HEIGHT 3

#define invader_SPEED 5

#define BORDER_WIDTH 2

void draw_screen(int **screen, int x, int y);
void draw_border(int **screen);
void draw_invaders(int **screen, int invaders_x, int invaders_y);
void draw_bullet(int **screen, int bullet_x, int bullet_y);

int main()
{
    int **screen = NULL;
    int x, y, bullet_x, bullet_y, invaders_x, invaders_y;

    screen = (int **)malloc(SCREEN_HEIGHT * sizeof(int *));
    for (y = 0; y < SCREEN_HEIGHT; y++)
    {
        screen[y] = (int *)malloc(SCREEN_WIDTH * sizeof(int));
    }

    // Initialize the screen, bullet, and invaders
    for (x = 0; x < SCREEN_WIDTH; x++)
    {
        for (y = 0; y < SCREEN_HEIGHT; y++)
        {
            screen[y][x] = 0;
        }
    }

    bullet_x = SCREEN_WIDTH / 2;
    bullet_y = SCREEN_HEIGHT - 1;
    invaders_x = 0;
    invaders_y = 0;

    // Game loop
    while (!screen[invaders_y][invaders_x])
    {
        draw_screen(screen, x, y);
        draw_border(screen);
        draw_invaders(screen, invaders_x, invaders_y);
        draw_bullet(screen, bullet_x, bullet_y);

        // Move the bullet
        bullet_x++;

        // If the bullet reaches the invaders, the invaders are destroyed
        if (screen[invaders_y][invaders_x] == 1)
        {
            screen[invaders_y][invaders_x] = 0;
            invaders_x++;
            if (invaders_x == SCREEN_WIDTH - invader_WIDTH)
            {
                invaders_y++;
                invaders_x = 0;
            }
        }

        // If the bullet reaches the border, the game is over
        if (bullet_x == SCREEN_WIDTH - 1)
        {
            draw_screen(screen, x, y);
            draw_border(screen);
            draw_invaders(screen, invaders_x, invaders_y);
            draw_bullet(screen, bullet_x, bullet_y);
            printf("Game Over!");
            break;
        }

        // Pause the game
        sleep(0.1);
    }

    // Free the memory allocated for the screen
    for (y = 0; y < SCREEN_HEIGHT; y++)
    {
        free(screen[y]);
    }
    free(screen);

    return 0;
}

void draw_screen(int **screen, int x, int y)
{
    for (x = 0; x < SCREEN_WIDTH; x++)
    {
        for (y = 0; y < SCREEN_HEIGHT; y++)
        {
            printf("%c ", screen[y][x]);
        }
        printf("\n");
    }
}

void draw_border(int **screen)
{
    for (int x = 0; x < SCREEN_WIDTH; x++)
    {
        screen[0][x] = '#';
        screen[SCREEN_HEIGHT - 1][x] = '#';
    }

    for (int y = 0; y < SCREEN_HEIGHT; y++)
    {
        screen[y][0] = '#';
        screen[y][SCREEN_WIDTH - 1] = '#';
    }
}

void draw_invaders(int **screen, int invaders_x, int invaders_y)
{
    for (int x = invaders_x; x < invaders_x + invader_WIDTH; x++)
    {
        for (int y = invaders_y; y < invaders_y + invader_HEIGHT; y++)
        {
            screen[y][x] = 'I';
        }
    }
}

void draw_bullet(int **screen, int bullet_x, int bullet_y)
{
    screen[bullet_y][bullet_x] = '*';
}