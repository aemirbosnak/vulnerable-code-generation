//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the galaxy structure
typedef struct {
  int width;
  int height;
  char **stars;
} Galaxy;

// Define the ship structure
typedef struct {
  int x;
  int y;
  int fuel;
} Ship;

// Create a new galaxy
Galaxy *create_galaxy(int width, int height) {
  Galaxy *galaxy = malloc(sizeof(Galaxy));
  galaxy->width = width;
  galaxy->height = height;
  galaxy->stars = malloc(sizeof(char *) * height);
  for (int i = 0; i < height; i++) {
    galaxy->stars[i] = malloc(sizeof(char) * width);
    for (int j = 0; j < width; j++) {
      galaxy->stars[i][j] = rand() % 2 ? '.' : ' ';
    }
  }
  return galaxy;
}

// Destroy a galaxy
void destroy_galaxy(Galaxy *galaxy) {
  for (int i = 0; i < galaxy->height; i++) {
    free(galaxy->stars[i]);
  }
  free(galaxy->stars);
  free(galaxy);
}

// Create a new ship
Ship *create_ship(int x, int y, int fuel) {
  Ship *ship = malloc(sizeof(Ship));
  ship->x = x;
  ship->y = y;
  ship->fuel = fuel;
  return ship;
}

// Destroy a ship
void destroy_ship(Ship *ship) {
  free(ship);
}

// Move the ship
void move_ship(Ship *ship, int dx, int dy) {
  ship->x += dx;
  ship->y += dy;
  ship->fuel--;
}

// Draw the galaxy
void draw_galaxy(Galaxy *galaxy) {
  for (int i = 0; i < galaxy->height; i++) {
    for (int j = 0; j < galaxy->width; j++) {
      printf("%c", galaxy->stars[i][j]);
    }
    printf("\n");
  }
}

// Draw the ship
void draw_ship(Galaxy *galaxy, Ship *ship) {
  galaxy->stars[ship->y][ship->x] = '>';
}

// Main game loop
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Create a new galaxy
  Galaxy *galaxy = create_galaxy(80, 25);

  // Create a new ship
  Ship *ship = create_ship(galaxy->width / 2, galaxy->height / 2, 100);

  // Game loop
  while (ship->fuel > 0) {
    // Draw the galaxy
    draw_galaxy(galaxy);

    // Draw the ship
    draw_ship(galaxy, ship);

    // Get the user input
    char input = getchar();

    // Move the ship
    switch (input) {
      case 'w':
        move_ship(ship, 0, -1);
        break;
      case 's':
        move_ship(ship, 0, 1);
        break;
      case 'a':
        move_ship(ship, -1, 0);
        break;
      case 'd':
        move_ship(ship, 1, 0);
        break;
    }
  }

  // Game over
  printf("Game over!\n");

  // Destroy the ship
  destroy_ship(ship);

  // Destroy the galaxy
  destroy_galaxy(galaxy);

  return 0;
}