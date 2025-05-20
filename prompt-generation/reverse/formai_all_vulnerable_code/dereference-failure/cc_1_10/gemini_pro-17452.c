//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAP_SIZE 10
#define PLAYER_SYMBOL 'P'
#define TREASURE_SYMBOL '$'
#define WALL_SYMBOL '#'
#define EMPTY_SYMBOL ' '

typedef struct {
  int x;
  int y;
} Coordinate;

typedef struct {
  Coordinate position;
  int score;
} Player;

typedef struct {
  Coordinate position;
} Treasure;

typedef struct {
  char** map;
  Player player;
  Treasure treasure;
} Game;

Game* create_game() {
  Game* game = malloc(sizeof(Game));
  game->map = malloc(sizeof(char*) * MAP_SIZE);
  for (int i = 0; i < MAP_SIZE; i++) {
    game->map[i] = malloc(sizeof(char) * MAP_SIZE);
    for (int j = 0; j < MAP_SIZE; j++) {
      game->map[i][j] = EMPTY_SYMBOL;
    }
  }
  game->player.position.x = 0;
  game->player.position.y = 0;
  game->player.score = 0;
  game->treasure.position.x = rand() % MAP_SIZE;
  game->treasure.position.y = rand() % MAP_SIZE;
  return game;
}

void destroy_game(Game* game) {
  for (int i = 0; i < MAP_SIZE; i++) {
    free(game->map[i]);
  }
  free(game->map);
  free(game);
}

void draw_map(Game* game) {
  for (int i = 0; i < MAP_SIZE; i++) {
    for (int j = 0; j < MAP_SIZE; j++) {
      if (i == game->player.position.x && j == game->player.position.y) {
        printf("%c", PLAYER_SYMBOL);
      } else if (i == game->treasure.position.x && j == game->treasure.position.y) {
        printf("%c", TREASURE_SYMBOL);
      } else {
        printf("%c", game->map[i][j]);
      }
    }
    printf("\n");
  }
}

int move_player(Game* game, int dx, int dy) {
  if (game->map[game->player.position.x + dx][game->player.position.y + dy] == WALL_SYMBOL) {
    return 0;
  }
  game->player.position.x += dx;
  game->player.position.y += dy;
  if (game->player.position.x == game->treasure.position.x && game->player.position.y == game->treasure.position.y) {
    game->player.score++;
    game->treasure.position.x = rand() % MAP_SIZE;
    game->treasure.position.y = rand() % MAP_SIZE;
  }
  return 1;
}

int main() {
  srand(time(NULL));
  Game* game = create_game();
  draw_map(game);
  while (1) {
    char input = getchar();
    switch (input) {
      case 'w':
        move_player(game, -1, 0);
        break;
      case 's':
        move_player(game, 1, 0);
        break;
      case 'a':
        move_player(game, 0, -1);
        break;
      case 'd':
        move_player(game, 0, 1);
        break;
      case 'q':
        exit(0);
        break;
    }
    draw_map(game);
    printf("Score: %d\n", game->player.score);
  }
  destroy_game(game);
  return 0;
}