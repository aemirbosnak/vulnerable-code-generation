//GEMINI-pro DATASET v1.0 Category: Game of Life ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>

#define WIDTH 80
#define HEIGHT 25

typedef struct {
  int x;
  int y;
} point;

typedef struct {
  int width;
  int height;
  bool **grid;
  int num_alive;
} game_of_life;

game_of_life *create_game_of_life(int width, int height) {
  game_of_life *game = malloc(sizeof(game_of_life));
  game->width = width;
  game->height = height;
  game->grid = malloc(sizeof(bool *) * height);
  for (int i = 0; i < height; i++) {
    game->grid[i] = malloc(sizeof(bool) * width);
    memset(game->grid[i], false, sizeof(bool) * width);
  }
  game->num_alive = 0;
  return game;
}

void destroy_game_of_life(game_of_life *game) {
  for (int i = 0; i < game->height; i++) {
    free(game->grid[i]);
  }
  free(game->grid);
  free(game);
}

void set_cell(game_of_life *game, int x, int y, bool alive) {
  if (x >= 0 && x < game->width && y >= 0 && y < game->height) {
    game->grid[y][x] = alive;
    if (alive) {
      game->num_alive++;
    } else {
      game->num_alive--;
    }
  }
}

bool get_cell(game_of_life *game, int x, int y) {
  if (x >= 0 && x < game->width && y >= 0 && y < game->height) {
    return game->grid[y][x];
  } else {
    return false;
  }
}

int count_neighbors(game_of_life *game, int x, int y) {
  int count = 0;
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i == 0 && j == 0) {
        continue;
      }
      if (get_cell(game, x + i, y + j)) {
        count++;
      }
    }
  }
  return count;
}

void *evolve(void *arg) {
  game_of_life *game = (game_of_life *)arg;

  while (true) {
    // Create a new grid to store the next generation.
    bool **new_grid = malloc(sizeof(bool *) * game->height);
    for (int i = 0; i < game->height; i++) {
      new_grid[i] = malloc(sizeof(bool) * game->width);
      memcpy(new_grid[i], game->grid[i], sizeof(bool) * game->width);
    }

    // Update the new grid.
    for (int i = 0; i < game->height; i++) {
      for (int j = 0; j < game->width; j++) {
        int num_neighbors = count_neighbors(game, j, i);
        if (get_cell(game, j, i)) {
          if (num_neighbors < 2 || num_neighbors > 3) {
            new_grid[i][j] = false;
            game->num_alive--;
          }
        } else {
          if (num_neighbors == 3) {
            new_grid[i][j] = true;
            game->num_alive++;
          }
        }
      }
    }

    // Swap the new grid with the old grid.
    for (int i = 0; i < game->height; i++) {
      free(game->grid[i]);
      game->grid[i] = new_grid[i];
    }
    free(new_grid);

    // Sleep for a bit.
    usleep(100000);
  }

  return NULL;
}

int main() {
  // Create the game of life.
  game_of_life *game = create_game_of_life(WIDTH, HEIGHT);

  // Set the initial state of the game.
  set_cell(game, 10, 10, true);
  set_cell(game, 11, 10, true);
  set_cell(game, 12, 10, true);

  // Create a thread to evolve the game.
  pthread_t thread;
  pthread_create(&thread, NULL, evolve, game);

  // Wait for the user to press a key.
  getchar();

  // Destroy the game of life.
  destroy_game_of_life(game);

  return 0;
}