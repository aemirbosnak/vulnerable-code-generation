//GEMINI-pro DATASET v1.0 Category: Game of Life ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALIVE 1
#define DEAD 0

#define NEIGHBOR_COUNT 8

typedef struct {
  int x;
  int y;
} point;

typedef struct {
  int width;
  int height;
  int **board;
} game_of_life;

game_of_life *create_game_of_life(int width, int height) {
  game_of_life *game = malloc(sizeof(game_of_life));
  game->width = width;
  game->height = height;
  game->board = malloc(sizeof(int *) * height);
  for (int i = 0; i < height; i++) {
    game->board[i] = malloc(sizeof(int) * width);
  }
  return game;
}

void destroy_game_of_life(game_of_life *game) {
  for (int i = 0; i < game->height; i++) {
    free(game->board[i]);
  }
  free(game->board);
  free(game);
}

void set_cell(game_of_life *game, int x, int y, int state) {
  if (x < 0 || x >= game->width || y < 0 || y >= game->height) {
    return;
  }
  game->board[y][x] = state;
}

int get_cell(game_of_life *game, int x, int y) {
  if (x < 0 || x >= game->width || y < 0 || y >= game->height) {
    return DEAD;
  }
  return game->board[y][x];
}

int count_neighbors(game_of_life *game, int x, int y) {
  int count = 0;
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i == 0 && j == 0) {
        continue;
      }
      if (get_cell(game, x + i, y + j) == ALIVE) {
        count++;
      }
    }
  }
  return count;
}

void update_cell(game_of_life *game, int x, int y) {
  int neighbors = count_neighbors(game, x, y);
  int state = get_cell(game, x, y);
  if (state == ALIVE) {
    if (neighbors < 2 || neighbors > 3) {
      set_cell(game, x, y, DEAD);
    }
  } else {
    if (neighbors == 3) {
      set_cell(game, x, y, ALIVE);
    }
  }
}

void update_game_of_life(game_of_life *game) {
  for (int y = 0; y < game->height; y++) {
    for (int x = 0; x < game->width; x++) {
      update_cell(game, x, y);
    }
  }
}

void print_game_of_life(game_of_life *game) {
  for (int y = 0; y < game->height; y++) {
    for (int x = 0; x < game->width; x++) {
      printf("%c", get_cell(game, x, y) == ALIVE ? 'O' : ' ');
    }
    printf("\n");
  }
}

int main() {
  game_of_life *game = create_game_of_life(80, 25);
  for (int i = 0; i < 100; i++) {
    update_game_of_life(game);
    print_game_of_life(game);
    printf("\n");
  }
  destroy_game_of_life(game);
  return 0;
}