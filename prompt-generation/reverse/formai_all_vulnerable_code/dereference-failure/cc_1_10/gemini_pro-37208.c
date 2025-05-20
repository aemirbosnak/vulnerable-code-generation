//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the player's ship
typedef struct {
  int x, y; // Position
  int fuel; // Remaining fuel
  int hull; // Remaining hull strength
} Ship;

// Define the universe
typedef struct {
  int width, height; // Dimensions
  char **map; // 2D array of characters representing the universe
} Universe;

// Create a new ship
Ship *create_ship(int x, int y) {
  Ship *ship = malloc(sizeof(Ship));
  ship->x = x;
  ship->y = y;
  ship->fuel = 100;
  ship->hull = 100;
  return ship;
}

// Create a new universe
Universe *create_universe(int width, int height) {
  Universe *universe = malloc(sizeof(Universe));
  universe->width = width;
  universe->height = height;
  universe->map = malloc(sizeof(char *) * height);
  for (int i = 0; i < height; i++) {
    universe->map[i] = malloc(sizeof(char) * width);
    for (int j = 0; j < width; j++) {
      universe->map[i][j] = '.'; // Initialize the map with empty space
    }
  }
  return universe;
}

// Generate a random universe
void generate_universe(Universe *universe) {
  // Seed the random number generator
  srand(time(NULL));

  // Generate the universe
  for (int i = 0; i < universe->height; i++) {
    for (int j = 0; j < universe->width; j++) {
      int r = rand() % 100; // Generate a random number between 0 and 99
      if (r < 10) { // 10% chance of generating a star
        universe->map[i][j] = '*';
      } else if (r < 20) { // 10% chance of generating a planet
        universe->map[i][j] = 'O';
      } // 80% chance of generating empty space
    }
  }
}

// Draw the universe
void draw_universe(Universe *universe) {
  for (int i = 0; i < universe->height; i++) {
    for (int j = 0; j < universe->width; j++) {
      printf("%c", universe->map[i][j]);
    }
    printf("\n");
  }
}

// Move the ship
void move_ship(Ship *ship, Universe *universe) {
  // Get the player's input
  char input;
  scanf(" %c", &input);

  // Move the ship based on the input
  switch (input) {
    case 'w': // Up
      if (ship->y > 0) {
        ship->y--;
      }
      break;
    case 's': // Down
      if (ship->y < universe->height - 1) {
        ship->y++;
      }
      break;
    case 'a': // Left
      if (ship->x > 0) {
        ship->x--;
      }
      break;
    case 'd': // Right
      if (ship->x < universe->width - 1) {
        ship->x++;
      }
      break;
    default:
      break;
  }
}

// Update the game state
void update_game(Ship *ship, Universe *universe) {
  // Decrement the ship's fuel
  ship->fuel--;

  // Check if the ship is out of fuel
  if (ship->fuel <= 0) {
    printf("Your ship is out of fuel! Game over.\n");
    exit(0);
  }

  // Check if the ship has crashed into anything
  if (universe->map[ship->y][ship->x] != '.') {
    printf("Your ship has crashed! Game over.\n");
    exit(0);
  }
}

// Main game loop
int main() {
  // Create the ship and universe
  Ship *ship = create_ship(0, 0);
  Universe *universe = create_universe(10, 10);
  generate_universe(universe);

  // Main game loop
  while (1) {
    // Draw the universe
    draw_universe(universe);

    // Move the ship
    move_ship(ship, universe);

    // Update the game state
    update_game(ship, universe);
  }

  return 0;
}