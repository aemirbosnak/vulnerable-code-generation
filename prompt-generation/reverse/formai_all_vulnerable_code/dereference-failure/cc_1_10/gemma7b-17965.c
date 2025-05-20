//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 50
#define MAX_HEIGHT 30

#define invader_WIDTH 10
#define invader_HEIGHT 2

#define invader_SPEED 5
#define invader_BULLET_SPEED 3

#define PLAYER_WIDTH 5
#define PLAYER_HEIGHT 2

#define PLAYER_SPEED 3

#define BULLET_WIDTH 2
#define BULLET_HEIGHT 2

#define BULLET_SPEED 4

#define GAME_OVER_MSG "GAME OVER!"

void draw_invaders(int **invaders, int x, int y)
{
  for (int i = 0; i < invader_HEIGHT; i++)
  {
    for (int j = 0; j < invader_WIDTH; j++)
    {
      if (invaders[i][j] == 1)
      {
        printf("%c", '#');
      }
      else
      {
        printf(" ");
      }
    }

    printf("\n");
  }
}

void draw_player(int x, int y)
{
  for (int i = x; i < x + PLAYER_WIDTH; i++)
  {
    printf("%c", '-');
  }

  printf("\n");
  for (int i = y; i < y + PLAYER_HEIGHT; i++)
  {
    printf("%c", '|');
  }

  printf("\n");
}

void draw_bullet(int x, int y)
{
  printf("%c", '*');
  printf("%c", ' ');
  printf("%c", '*');
  printf("\n");
  printf("%c", ' ');
  printf("%c", '*');
  printf("%c", ' ');
  printf("\n");
}

int main()
{
  int **invaders = (int **)malloc(MAX_HEIGHT * sizeof(int *));
  for (int i = 0; i < MAX_HEIGHT; i++)
  {
    invaders[i] = (int *)malloc(MAX_WIDTH * sizeof(int));
  }

  int player_x = MAX_WIDTH / 2;
  int player_y = MAX_HEIGHT - 1;

  int bullet_x = player_x;
  int bullet_y = player_y - 1;

  for (int i = 0; i < MAX_HEIGHT; i++)
  {
    for (int j = 0; j < MAX_WIDTH; j++)
    {
      invaders[i][j] = 0;
    }
  }

  int game_over = 0;

  while (!game_over)
  {
    draw_invaders(invaders, MAX_WIDTH, MAX_HEIGHT);
    draw_player(player_x, player_y);
    draw_bullet(bullet_x, bullet_y);

    // Move invaders
    for (int i = 0; i < invader_HEIGHT; i++)
    {
      for (int j = 0; j < invader_WIDTH; j++)
      {
        if (invaders[i][j] == 1)
        {
          invaders[i][j] = 0;
          invaders[i - 1][j] = 1;
        }
      }
    }

    // Move bullet
    bullet_x += BULLET_SPEED;

    // Check if bullet has reached the end of the screen
    if (bullet_x >= MAX_WIDTH)
    {
      bullet_x = player_x;
      bullet_y--;
    }

    // Check if bullet has hit an invader
    for (int i = 0; i < invader_HEIGHT; i++)
    {
      for (int j = 0; j < invader_WIDTH; j++)
      {
        if (invaders[i][j] == 1 && bullet_x == j && bullet_y == i)
        {
          invaders[i][j] = 0;
          bullet_x = player_x;
          bullet_y--;
        }
      }
    }

    // Check if the invaders have reached the bottom of the screen
    if (invaders[0][0] == 1)
    {
      game_over = 1;
    }

    // Pause the game
    sleep(1);
  }

  // Game Over message
  printf("%s", GAME_OVER_MSG);

  return 0;
}