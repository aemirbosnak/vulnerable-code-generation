//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the player's spaceship
typedef struct {
  int x, y; // Coordinates
  int fuel; // Remaining fuel
} Spaceship;

// Define the game world
typedef struct {
  int width, height; // Dimensions
  char **grid; // 2D array of characters representing the world
} World;

// Create a new spaceship
Spaceship *create_spaceship(int x, int y, int fuel) {
  Spaceship *ship = malloc(sizeof(Spaceship));
  ship->x = x;
  ship->y = y;
  ship->fuel = fuel;
  return ship;
}

// Create a new world
World *create_world(int width, int height) {
  World *world = malloc(sizeof(World));
  world->width = width;
  world->height = height;
  world->grid = malloc(sizeof(char *) * height);
  for (int i = 0; i < height; i++) {
    world->grid[i] = malloc(sizeof(char) * width);
  }
  return world;
}

// Generate a random world
void generate_world(World *world) {
  srand(time(NULL));
  for (int i = 0; i < world->height; i++) {
    for (int j = 0; j < world->width; j++) {
      world->grid[i][j] = rand() % 2 ? '*' : ' ';
    }
  }
}

// Print the world
void print_world(World *world) {
  for (int i = 0; i < world->height; i++) {
    for (int j = 0; j < world->width; j++) {
      printf("%c", world->grid[i][j]);
    }
    printf("\n");
  }
}

// Move the spaceship
void move_spaceship(Spaceship *ship, World *world, char direction) {
  int dx, dy;
  switch (direction) {
    case 'w':
      dx = 0;
      dy = -1;
      break;
    case 's':
      dx = 0;
      dy = 1;
      break;
    case 'a':
      dx = -1;
      dy = 0;
      break;
    case 'd':
      dx = 1;
      dy = 0;
      break;
  }

  // Check if the spaceship can move in the given direction
  if (ship->x + dx >= 0 && ship->x + dx < world->width && ship->y + dy >= 0 && ship->y + dy < world->height && world->grid[ship->y + dy][ship->x + dx] != '*') {
    // Move the spaceship
    ship->x += dx;
    ship->y += dy;
    ship->fuel--;
  }
}

// Check if the spaceship has won
int has_won(Spaceship *ship) {
  return ship->fuel > 0;
}

// Check if the spaceship has lost
int has_lost(Spaceship *ship) {
  return ship->fuel <= 0;
}

// Play the game
void play_game() {
  // Create the spaceship and world
  Spaceship *ship = create_spaceship(0, 0, 10);
  World *world = create_world(10, 10);
  generate_world(world);

  // Game loop
  while (!has_won(ship) && !has_lost(ship)) {
    // Print the world
    print_world(world);

    // Get the player's input
    char input;
    printf("Enter a direction to move (w, s, a, d): ");
    scanf(" %c", &input);

    // Move the spaceship
    move_spaceship(ship, world, input);
  }

  // Game over
  if (has_won(ship)) {
    printf("Congratulations! You won the game!\n");
  } else {
    printf("Game over! You ran out of fuel.\n");
  }

  // Free the memory
  free(ship);
  for (int i = 0; i < world->height; i++) {
    free(world->grid[i]);
  }
  free(world->grid);
  free(world);
}

int main() {
  play_game();
  return 0;
}