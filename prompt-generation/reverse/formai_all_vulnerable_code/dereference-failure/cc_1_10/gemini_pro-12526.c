//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEFT  0
#define RIGHT 1
#define UP    2
#define DOWN  3
#define JUMP  4
#define SHOOT 5

typedef struct {
  int x, y;
  int dir;
  int speed;
  int health;
  int ammo;
} Player;

typedef struct {
  int w, h;
  int num_walls;
  int **walls;
} World;

void init_player(Player *player) {
  player->x = 0;
  player->y = 0;
  player->dir = RIGHT;
  player->speed = 1;
  player->health = 100;
  player->ammo = 100;
}

void init_world(World *world) {
  world->w = 100;
  world->h = 100;
  world->num_walls = 10;
  world->walls = malloc(sizeof(int *) * world->num_walls);
  for (int i = 0; i < world->num_walls; i++) {
    world->walls[i] = malloc(sizeof(int) * 2);
    world->walls[i][0] = rand() % world->w;
    world->walls[i][1] = rand() % world->h;
  }
}

void draw_world(World *world, Player *player) {
  for (int i = 0; i < world->h; i++) {
    for (int j = 0; j < world->w; j++) {
      if (i == player->y && j == player->x) {
        printf("@");
      } else {
        int found_wall = 0;
        for (int k = 0; k < world->num_walls; k++) {
          if (i == world->walls[k][1] && j == world->walls[k][0]) {
            printf("#");
            found_wall = 1;
            break;
          }
        }
        if (!found_wall) {
          printf(" ");
        }
      }
    }
    printf("\n");
  }
}

void update_player(World *world, Player *player, int action) {
  switch (action) {
    case LEFT:
      player->x -= player->speed;
      break;
    case RIGHT:
      player->x += player->speed;
      break;
    case UP:
      player->y -= player->speed;
      break;
    case DOWN:
      player->y += player->speed;
      break;
    case JUMP:
      player->y -= player->speed * 2;
      break;
    case SHOOT:
      player->ammo--;
      break;
  }

  if (player->x < 0) {
    player->x = 0;
  } else if (player->x >= world->w) {
    player->x = world->w - 1;
  }

  if (player->y < 0) {
    player->y = 0;
  } else if (player->y >= world->h) {
    player->y = world->h - 1;
  }
}

int main() {
  srand(time(NULL));

  World world;
  init_world(&world);

  Player player;
  init_player(&player);

  while (1) {
    draw_world(&world, &player);

    int action = rand() % 6;

    update_player(&world, &player, action);
  }

  return 0;
}