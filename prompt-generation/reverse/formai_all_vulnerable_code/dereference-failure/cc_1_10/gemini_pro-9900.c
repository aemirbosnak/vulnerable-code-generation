//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the player struct
typedef struct {
  int x;
  int y;
  int health;
} player;

// Define the world struct
typedef struct {
  int width;
  int height;
  char **map;
} world;

// Create a new player
player *new_player(int x, int y) {
  player *p = malloc(sizeof(player));
  p->x = x;
  p->y = y;
  p->health = 100;
  return p;
}

// Create a new world
world *new_world(int width, int height) {
  world *w = malloc(sizeof(world));
  w->width = width;
  w->height = height;

  // Allocate memory for the map
  w->map = malloc(sizeof(char *) * height);
  for (int i = 0; i < height; i++) {
    w->map[i] = malloc(sizeof(char) * width);
  }

  // Fill the map with random characters
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      w->map[i][j] = rand() % 26 + 'a';
    }
  }

  return w;
}

// Draw the world
void draw_world(world *w) {
  for (int i = 0; i < w->height; i++) {
    for (int j = 0; j < w->width; j++) {
      printf("%c", w->map[i][j]);
    }
    printf("\n");
  }
}

// Move the player
void move_player(player *p, world *w, int dx, int dy) {
  // Check if the player is trying to move off the edge of the world
  if (p->x + dx < 0 || p->x + dx >= w->width || p->y + dy < 0 || p->y + dy >= w->height) {
    return;
  }

  // Move the player
  p->x += dx;
  p->y += dy;
}

// Main game loop
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Create a new world
  world *w = new_world(80, 24);

  // Create a new player
  player *p = new_player(w->width / 2, w->height / 2);

  // Game loop
  while (p->health > 0) {
    // Draw the world
    draw_world(w);

    // Get the player's input
    char input = getchar();

    // Move the player
    switch (input) {
      case 'w':
        move_player(p, w, 0, -1);
        break;
      case 's':
        move_player(p, w, 0, 1);
        break;
      case 'a':
        move_player(p, w, -1, 0);
        break;
      case 'd':
        move_player(p, w, 1, 0);
        break;
    }
  }

  // Game over
  printf("Game over!\n");

  // Free the memory
  free(p);
  for (int i = 0; i < w->height; i++) {
    free(w->map[i]);
  }
  free(w);

  return 0;
}