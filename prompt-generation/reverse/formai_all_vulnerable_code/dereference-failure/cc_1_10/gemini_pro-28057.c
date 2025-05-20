//GEMINI-pro DATASET v1.0 Category: Breakout Game Clone ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 24
#define PADDLE_WIDTH 10
#define BALL_SIZE 2

typedef struct {
  int x, y;
} Point;

typedef struct {
  Point pos;
  int dx, dy;
} Ball;

typedef struct {
  Point pos;
} Paddle;

typedef struct {
  int score;
  Ball ball;
  Paddle paddle;
  char **grid;
} Game;

void init_game(Game *game) {
  game->score = 0;
  game->ball.pos.x = WIDTH / 2;
  game->ball.pos.y = HEIGHT - 3;
  game->ball.dx = 1;
  game->ball.dy = -1;
  game->paddle.pos.x = WIDTH / 2 - PADDLE_WIDTH / 2;
  game->paddle.pos.y = HEIGHT - 1;
  game->grid = malloc(HEIGHT * sizeof(char *));
  for (int i = 0; i < HEIGHT; i++) {
    game->grid[i] = malloc(WIDTH * sizeof(char));
    for (int j = 0; j < WIDTH; j++) {
      game->grid[i][j] = ' ';
    }
  }
}

void free_game(Game *game) {
  for (int i = 0; i < HEIGHT; i++) {
    free(game->grid[i]);
  }
  free(game->grid);
}

void draw_game(Game *game) {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      if (i == 0 || i == HEIGHT - 1) {
        game->grid[i][j] = '-';
      } else if (j == 0 || j == WIDTH - 1) {
        game->grid[i][j] = '|';
      } else if (i == game->ball.pos.y && j == game->ball.pos.x) {
        game->grid[i][j] = 'O';
      } else if (i == game->paddle.pos.y && j >= game->paddle.pos.x && j < game->paddle.pos.x + PADDLE_WIDTH) {
        game->grid[i][j] = '=';
      }
    }
  }

  printf("\nScore: %d\n", game->score);
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      printf("%c", game->grid[i][j]);
    }
    printf("\n");
  }
}

void update_game(Game *game) {
  // Move the ball
  game->ball.pos.x += game->ball.dx;
  game->ball.pos.y += game->ball.dy;

  // Check if the ball has hit a wall
  if (game->ball.pos.x <= 0 || game->ball.pos.x >= WIDTH - 1) {
    game->ball.dx *= -1;
  }
  if (game->ball.pos.y <= 0) {
    game->ball.dy *= -1;
  }

  // Check if the ball has hit the paddle
  if (game->ball.pos.y == game->paddle.pos.y &&
      game->ball.pos.x >= game->paddle.pos.x &&
      game->ball.pos.x < game->paddle.pos.x + PADDLE_WIDTH) {
    game->ball.dy *= -1;
    game->score++;
  }

  // Check if the ball has hit the bottom of the screen
  if (game->ball.pos.y >= HEIGHT - 1) {
    game->ball.dy *= -1;
  }
}

void handle_input(Game *game) {
  char input;
  scanf(" %c", &input);

  switch (input) {
    case 'a':
      if (game->paddle.pos.x > 0) game->paddle.pos.x--;
      break;
    case 'd':
      if (game->paddle.pos.x < WIDTH - PADDLE_WIDTH) game->paddle.pos.x++;
      break;
    case 'q':
      exit(0);
      break;
  }
}

int main() {
  srand(time(NULL));

  Game game;
  init_game(&game);

  while (1) {
    draw_game(&game);
    update_game(&game);
    handle_input(&game);
  }

  free_game(&game);

  return 0;
}