//GEMINI-pro DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Donald Knuth
// A whimsical C rogue-like game with procedural generation

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent the game world
typedef struct {
  int width, height;
  char **grid;
} World;

// Structure to represent the player character
typedef struct {
  int x, y;
  int health;
} Player;

// Function to create a new world
World *new_world(int w, int h) {
  World *world = malloc(sizeof(World));
  world->width = w;
  world->height = h;
  world->grid = malloc(sizeof(char *) * h);
  for (int i = 0; i < h; i++) {
    world->grid[i] = malloc(sizeof(char) * w);
    for (int j = 0; j < w; j++) {
      world->grid[i][j] = '.';
    }
  }
  return world;
}

// Function to free a world
void free_world(World *world) {
  for (int i = 0; i < world->height; i++) {
    free(world->grid[i]);
  }
  free(world->grid);
  free(world);
}

// Function to generate a new world
World *generate_world(int w, int h) {
  World *world = new_world(w, h);
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      if (rand() % 10 == 0) {
        world->grid[i][j] = '#';
      } else if (rand() % 10 == 0) {
        world->grid[i][j] = 'P';
      } else if (rand() % 10 == 0) {
        world->grid[i][j] = 'H';
      }
    }
  }
  return world;
}

// Function to create a new player
Player *new_player(int x, int y) {
  Player *player = malloc(sizeof(Player));
  player->x = x;
  player->y = y;
  player->health = 100;
  return player;
}

// Function to free a player
void free_player(Player *player) {
  free(player);
}

// Function to draw the world
void draw_world(World *world) {
  for (int i = 0; i < world->height; i++) {
    for (int j = 0; j < world->width; j++) {
      printf("%c", world->grid[i][j]);
    }
    printf("\n");
  }
}

// Function to move the player
void move_player(Player *player, int dx, int dy) {
  player->x += dx;
  player->y += dy;
}

// Function to check if the player is alive
int is_player_alive(Player *player) {
  return player->health > 0;
}

// Function to play the game
void play_game(World *world, Player *player) {
  while (is_player_alive(player)) {
    // Draw the world
    draw_world(world);

    // Get the player's input
    int dx = 0, dy = 0;
    char input = getchar();
    switch (input) {
      case 'h': dx = -1; break;
      case 'j': dy = 1; break;
      case 'k': dy = -1; break;
      case 'l': dx = 1; break;
      case 'q': exit(0); break;
    }

    // Move the player
    move_player(player, dx, dy);
  }

  // Game over
  printf("Game over!\n");
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Create a new world
  World *world = generate_world(80, 25);

  // Create a new player
  Player *player = new_player(1, 1);

  // Play the game
  play_game(world, player);

  // Free the world and the player
  free_world(world);
  free_player(player);

  return 0;
}